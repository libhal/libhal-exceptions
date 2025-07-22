#include <algorithm>
#include <cstring>

#include <algorithm>
#include <format>
#include <fstream>
#include <span>
#include <string_view>
#include <vector>

#include <plugin-api.h>

// Plugin entry point - this function must exist
enum ld_plugin_status onload(struct ld_plugin_tv* tv);
namespace {
// Plugin version info
[[maybe_unused]] std::string_view const plugin_version = "1.0";

// Function to handle messages/logging
ld_plugin_message message_handler = nullptr;

// Function pointer for adding input files
ld_plugin_add_input_file add_input_file = nullptr;

// Function pointers for section analysis
ld_plugin_get_input_section_count get_input_section_count = nullptr;
ld_plugin_get_input_section_type get_input_section_type = nullptr;
ld_plugin_get_input_section_name get_input_section_name = nullptr;
ld_plugin_get_input_section_contents get_input_section_contents = nullptr;
ld_plugin_get_input_section_size get_input_section_size = nullptr;

std::array<int, 1204> exception_index;
template<class... Args>
void println(ld_plugin_level p_level, std::string_view p_format, Args... p_args)
{
  if (not message_handler) {
    return;
  }
  uint32_t pc = 0;

  auto const& entry = exception_index[pc >> 2];

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

std::vector<function_info> parse_exception_tables()
{
  std::vector<function_info> functions;

  bool const can_proceed = get_input_section_count && get_input_section_name &&
                           get_input_section_contents;

  if (not can_proceed) {
    return functions;
  }

  // Sort by size for optimal nearpoint layout
  std::ranges::sort(functions);

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

void generate_extraction_and_reordering(std::span<function_info> functions)
{
  std::ofstream script("extract_and_order.ld");

  auto sorted_funcs = functions;
  std::sort(sorted_funcs.begin(), sorted_funcs.end());

  script << "SECTIONS {\n";
  script << "  .text.ordered : {\n";
  script << "    /* Extract and reorder exception functions by size */\n";

  for (auto const& func : sorted_funcs) {
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

  // Compile the nearpoint tables
  std::string cmd =
    "arm-none-eabi-g++ -c nearpoint_tables.cpp -o nearpoint_tables.o";
  if (std::system(cmd.c_str()) != 0) {
    println(LDPL_WARNING, "Failed to compile nearpoint tables");
  }
}

// All symbols read handler - called when all symbols are available
enum ld_plugin_status all_symbols_read_handler()
{
  println(LDPL_INFO,
          "All symbols have been read - analyzing for function ordering");

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

  return LDPS_OK;
}

// Cleanup handler - called at the end of linking
enum ld_plugin_status cleanup_handler()
{
  println(LDPL_INFO, "Plugin cleanup");
  return LDPS_OK;
}

}  // namespace

extern "C"
{

  // Main plugin entry point
  // NOLINTNEXTLINE(readability-identifier-naming)
  enum ld_plugin_status _onload(struct ld_plugin_tv* tv)
  {
    struct ld_plugin_tv* entry;
    ld_plugin_register_all_symbols_read register_all_symbols_read = nullptr;
    ld_plugin_register_cleanup register_cleanup = nullptr;

    // Parse the transfer vector to get linker interface functions
    for (entry = tv; entry->tv_tag != LDPT_NULL; ++entry) {
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

    if (register_all_symbols_read) {
      register_all_symbols_read(all_symbols_read_handler);
    }

    if (register_cleanup) {
      register_cleanup(cleanup_handler);
    }

    println(LDPL_INFO, "Function ordering plugin loaded successfully");

    return LDPS_OK;
  }
}
