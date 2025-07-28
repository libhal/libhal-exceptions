#include <algorithm>
#include <cstring>

#include <algorithm>
#include <format>
#include <fstream>
#include <span>
#include <string_view>
#include <vector>

#include <plugin-api.h>

namespace {
// Plugin version info
[[maybe_unused]] std::string_view const plugin_version = "1.0";

// Function to handle messages/logging
ld_plugin_message message_handler = nullptr;

// Function pointer for adding input files
ld_plugin_add_input_file add_input_file = nullptr;
ld_plugin_get_input_section_count get_input_section_count = nullptr;
ld_plugin_get_input_section_type get_input_section_type = nullptr;
ld_plugin_get_input_section_name get_input_section_name = nullptr;
ld_plugin_get_input_section_contents get_input_section_contents = nullptr;
ld_plugin_get_input_section_size get_input_section_size = nullptr;

template<class... Args>
void println(ld_plugin_level p_level, std::string_view p_format, Args... p_args)
{
  if (not message_handler) {
    return;
  }
  auto const log = std::vformat(p_format, std::make_format_args(p_args...));
  message_handler(p_level, log.c_str());
}

struct function_info
{
  std::string name;
  std::string object_file;
  uint32_t address;
  uint32_t size;
  bool has_exception_info;

  constexpr bool operator<(function_info const& other) const
  {
    return size < other.size;
  }

  constexpr bool operator==(function_info const& other) const
  {
    return size == other.size;
  }
};

#if 0
std::vector<function_info> parse_exception_tables()
{
  std::vector<function_info> functions;

  bool const can_proceed = get_input_section_count && get_input_section_name &&
                           get_input_section_contents;

  if (not can_proceed) {
    return functions;
  }

  std::ranges::sort(functions, [](auto const& p_left, auto const& p_right) {
    return p_left.size < p_right.size;
  });

  return functions;
}

bool check_if_sorted_by_size(std::span<function_info> p_functions)
{
  for (size_t i = 0; i < p_functions.size() - 1; ++i) {
    if (p_functions[i].has_exception_info &&
        p_functions[i + 1].has_exception_info) {
      if (p_functions[i].size > p_functions[i + 1].size) {
        return false;
      }
    }
  }
  return true;
}

void generate_extraction_and_reordering(std::span<function_info> p_sorted_funcs)
{
  std::ofstream script("extract_and_order.ld");
  auto const is_sorted = std::ranges::is_sorted(
    p_sorted_funcs, [](auto const& p_left, auto const& p_right) {
      return p_left.size < p_right.size;
    });

  if (is_sorted) {
    println(LDPL_WARNING,
            "The exception index is not sorted, nothing to do here");
    return;
  }

  script << "SECTIONS {\n";
  script << "  .text.ordered : {\n";
  script << "    /* Extract and reorder exception functions by size */\n";

  for (auto const& func : p_sorted_funcs) {
    if (func.has_exception_info) {
      script << std::format("    *(.text.{})\n", func.name);
    }
  }

  script << "  }\n";
  script << "}\n";

  // INSERT BEFORE .text so we get processed first (linker scripts are greedy)
  script << "INSERT BEFORE .text;\n";

  script.close();
}

void generate_nearpoint_tables(std::span<function_info> functions)
{
  std::ofstream cpp_file("nearpoint_tables.cpp");

  cpp_file << "#include <cstdint>\n";
  cpp_file << "#include <cstddef>\n";
  cpp_file << "\n";

  // Generate lookup table for exception functions
  cpp_file << "extern \"C\" {\n";
  cpp_file << "struct NearPointEntry {\n";
  cpp_file << "    const void* function_addr;\n";
  cpp_file << "    uint32_t size;\n";
  cpp_file << "    uint32_t exception_offset;\n";
  cpp_file << "};\n\n";

  // Sort by address order for the lookup table
  auto sorted_funcs =
    std::vector<function_info>(functions.begin(), functions.end());
  std::ranges::sort(sorted_funcs, [](auto const& a, auto const& b) {
    return a.address < b.address;
  });

  cpp_file << "[[gnu::used]] const NearPointEntry nearpoint_table[] = {\n";

  for (auto const& func : sorted_funcs) {
    if (func.has_exception_info) {
      cpp_file << std::format(
        "    {{reinterpret_cast<const void*>(0x{:x}), {}, 0}},\n",
        func.address,
        func.size);
    }
  }

  cpp_file << "};\n\n";
  cpp_file << std::format(
    "[[gnu::used]] const size_t nearpoint_table_size = {};\n",
    std::ranges::count_if(functions,
                          [](auto const& f) { return f.has_exception_info; }));
  cpp_file << "}\n";
  cpp_file.close();

  // TODO(kammce): Compile the nearpoint tables OR inject symbols directly
}

void process_except_ordered_data(uint8_t const* data, size_t length)
{
  println(LDPL_INFO, "Section contents (first 16 bytes): ");

  for (size_t i = 0; i < std::min(length, size_t(16)); ++i) {
    println(LDPL_INFO, "{:02X}", data[i]);
  }

  // TODO: Parse the actual data format here
  // This is where you'd implement your exception table parsing
}
enum ld_plugin_status read_except_ordered_section(
  const struct ld_plugin_input_file& p_file)
{
  void const* section_contents;
  size_t section_len;

  // Get the actual section data
  if (get_input_section_contents(&p_file, &section_contents, &section_len) !=
      LDPS_OK) {
    return LDPS_ERR;
  }

  println(LDPL_INFO, "Found .except_ordered section: {} bytes", section_len);

  // Process the section contents
  process_except_ordered_data(static_cast<uint8_t const*>(section_contents),
                              section_len);

  return LDPS_OK;
}

ld_plugin_status process_file_sections(ld_plugin_input_file const& p_file)
{
  unsigned int section_count;

  // Get total number of sections in this file
  if (get_input_section_count(&p_file, &section_count) != LDPS_OK) {
    return LDPS_ERR;
  }

  // Iterate through all sections
  for (unsigned int i = 0; i < section_count; ++i) {
    char* section_name;

    // Get section name
    if (get_input_section_name(&p_file, &section_name) != LDPS_OK) {
      continue;
    }

    // Check if this is our target section
    if (strcmp(section_name, ".except_ordered") == 0) {
      if (read_except_ordered_section(p_file, i) != LDPS_OK) {
        println(LDPL_ERROR, "Failed to read .except_ordered section");
        return LDPS_ERR;
      }
    }
  }

  return LDPS_OK;
}
#endif

// All symbols read handler - called when all symbols are available
ld_plugin_status all_symbols_read_handler()
{
  println(LDPL_INFO,
          "All symbols have been read - analyzing for function ordering");
#if 0

  for (auto const& file : input_files) {
    if (process_file_sections(file) != LDPS_OK) {
      println(LDPL_ERROR, "Failed to process file sections");
      return LDPS_ERR;
    }
  }

  // Parse exception information from input files
  auto functions = parse_exception_tables();

  if (functions.empty()) {
    println(LDPL_INFO, "No functions with exception info found");
    return LDPS_OK;
  }

  // Check current ordering
  bool is_sorted = check_if_sorted_by_size(functions);

  if (is_sorted) {
    println(
      LDPL_INFO,
      "Functions already sorted by size - generating nearpoint tables only");
  } else {
    println(LDPL_INFO,
            "Functions not sorted by size - creating reordered layout");

    // Generate reordering script
    generate_extraction_and_reordering(functions);

    if (add_input_file) {
      add_input_file("extract_and_order.ld");
    }
  }

  // Always generate nearpoint tables
  generate_nearpoint_tables(functions);

  if (add_input_file) {
    add_input_file("nearpoint_tables.o");
  }

  println(LDPL_INFO,
          "Generated function ordering for {} exception functions",
          functions.size());
#endif
  return LDPS_OK;
}

// Cleanup handler - called at the end of linking
ld_plugin_status cleanup_handler()
{
  println(LDPL_INFO, "Plugin cleanup");
  return LDPS_OK;
}

[[maybe_unused]]
void process_unwind_section(char* p_name, std::span<unsigned char const> p_data)
{
  println(LDPL_INFO, "section \"{}\"", p_name);
  if (not p_data.empty()) {
    println(LDPL_INFO, "has contents \"{}\"", p_data[0]);
  }
}

ld_plugin_status claim_file_handler(ld_plugin_input_file const* p_file,
                                    [[maybe_unused]] int* p_claimed)
{
  println(LDPL_INFO,
          "p_file addr = {} :: p_claimed = {}",
          p_file->name,
          static_cast<void*>(p_claimed));

  // Store file handle for later processing
  // input_files.push_back(*file);

#if 0
  unsigned int section_count = 0;

  if (get_input_section_count(p_file->handle, &section_count) != LDPS_OK) {
    return LDPS_ERR;
  }

  for (unsigned int i = 0; i < section_count; i++) {
    ld_plugin_section section{ .handle = p_file->handle, .shndx = i };

    char* section_name = nullptr;
    if (get_input_section_name(section, &section_name) == LDPS_OK) {

      if (strcmp(section_name, ".eh_frame") == 0 ||
          strcmp(section_name, ".eh_frame_hdr") == 0 ||
          strcmp(section_name, ".debug_frame") == 0) {

        unsigned char const* contents = nullptr;
        size_t len = 0;
        if (get_input_section_contents(section, &contents, &len) == LDPS_OK) {
          process_unwind_section(section_name, std::span(contents, len));
        }
      }

      free(section_name);  // API docs say plugin must free this
    }
  }
#endif

  // We don't claim the file (let normal processing continue)
  *p_claimed = 0;
  return LDPS_OK;
}
}  // namespace

extern "C"
{
  // Main plugin entry point
  // NOLINTNEXTLINE(readability-identifier-naming)
  enum ld_plugin_status _onload(ld_plugin_tv* tv)
  {
    // Function pointers for section analysis
    ld_plugin_register_claim_file register_claim_file = nullptr;
    ld_plugin_register_all_symbols_read register_all_symbols_read = nullptr;
    ld_plugin_register_cleanup register_cleanup = nullptr;

    // Parse the transfer vector to get linker interface functions
    for (ld_plugin_tv* entry = tv; entry->tv_tag != LDPT_NULL; ++entry) {
      switch (entry->tv_tag) {
        case LDPT_MESSAGE:
          message_handler = entry->tv_u.tv_message;
          break;
        case LDPT_ADD_INPUT_FILE:
          add_input_file = entry->tv_u.tv_add_input_file;
          break;
        case LDPT_GET_INPUT_SECTION_COUNT:
          get_input_section_count = entry->tv_u.tv_get_input_section_count;
          break;
        case LDPT_GET_INPUT_SECTION_TYPE:
          get_input_section_type = entry->tv_u.tv_get_input_section_type;
          break;
        case LDPT_GET_INPUT_SECTION_NAME:
          get_input_section_name = entry->tv_u.tv_get_input_section_name;
          break;
        case LDPT_GET_INPUT_SECTION_CONTENTS:
          get_input_section_contents =
            entry->tv_u.tv_get_input_section_contents;
          break;
        case LDPT_GET_INPUT_SECTION_SIZE:
          get_input_section_size = entry->tv_u.tv_get_input_section_size;
          break;
        case LDPT_REGISTER_CLAIM_FILE_HOOK:
          register_claim_file = entry->tv_u.tv_register_claim_file;
          break;
        case LDPT_REGISTER_ALL_SYMBOLS_READ_HOOK:
          register_all_symbols_read = entry->tv_u.tv_register_all_symbols_read;
          break;
        case LDPT_REGISTER_CLEANUP_HOOK:
          register_cleanup = entry->tv_u.tv_register_cleanup;
          break;
        case LDPT_API_VERSION:
          // Check API version compatibility
          if (entry->tv_u.tv_val != LD_PLUGIN_API_VERSION) {
            println(LDPL_ERROR,
                    "API version mismatch: expected {}, got {}",
                    static_cast<int>(LD_PLUGIN_API_VERSION),
                    static_cast<int>(entry->tv_u.tv_val));
            return LDPS_ERR;
          }
          break;
        default:
          // Ignore unknown entries
          break;
      }
    }

    // Register our handlers
    if (register_claim_file == nullptr ||
        register_all_symbols_read == nullptr || register_cleanup == nullptr) {
      return LDPS_ERR;
    }

    if (register_claim_file(claim_file_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    if (register_all_symbols_read(all_symbols_read_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    if (register_cleanup(cleanup_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    println(
      LDPL_INFO,
      "Nearpoint exception optimization ordering plugin loaded successfully");

    return LDPS_OK;
  }
}
