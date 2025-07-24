#include <algorithm>
#include <cstring>

#include <algorithm>
#include <format>
#include <fstream>
#include <initializer_list>
#include <regex>
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
ld_plugin_get_symbols get_symbols = nullptr;
ld_plugin_get_symbols get_symbols_v2 = nullptr;
ld_plugin_get_symbols get_symbols_v3 = nullptr;

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

#if 0
ld_plugin_status claim_file_handler(const struct ld_plugin_input_file* p_file,
                                    int* p_claimed)
{
  println(LDPL_INFO,
          "p_file addr = {} :: p_claimed = {}",
          p_file->name,
          static_cast<void*>(p_claimed));

  // Store file handle for later processing
  // input_files.push_back(*file);

  std::vector<ld_plugin_symbol> set_of_symbols(10000);

  println(LDPL_INFO,
          "set_of_symbols({},{})",
          set_of_symbols.size(),
          static_cast<void*>(set_of_symbols.data()));
  println(LDPL_INFO, "get_symbols = ", reinterpret_cast<void*>(get_symbols));

  if (get_symbols == nullptr) {
    println(LDPL_INFO, "get_symbols == NULLPTR");
    return LDPS_ERR;
  }

  get_symbols(p_file->handle,
              static_cast<int>(set_of_symbols.size()),
              set_of_symbols.data());

  for (auto const symbol : set_of_symbols) {
    println(
      LDPL_ERROR, "type = {} :: name = {}", symbol.symbol_type, symbol.name);
  }
  // We don't claim the file (let normal processing continue)
  *p_claimed = 0;
  return LDPS_OK;
}
#endif

void analyze_symbols(void const* handle);

ld_plugin_status claim_file_handler(ld_plugin_input_file const* file,
                                    int* claimed)
{
  println(LDPL_INFO, "ℹ️ claim_file_handler");
  // Don't claim the file, just analyze it
  *claimed = 0;
  println(LDPL_INFO,
          "ℹ️ get_symbols_v2 = {}",
          reinterpret_cast<void*>(get_symbols_v2));
  println(
    LDPL_INFO, "ℹ️ get_symbols = {}", reinterpret_cast<void*>(get_symbols));

  // Get symbols from this file
  if (get_symbols_v2 != nullptr) {
    analyze_symbols(file->handle);
    return LDPS_OK;
  } else if (get_symbols != nullptr) {
    analyze_symbols(file->handle);
    return LDPS_OK;
  }

  return LDPS_ERR;
}

void analyze_symbols(void const* handle)
{
  ld_plugin_symbol test_plugin{};
  // First, get symbol count by calling with nullptr
  // int symbol_count = 0;
  if (get_symbols_v2(handle, 1, &test_plugin) != LDPS_OK) {
    println(LDPL_INFO, "❌ get_symbols_v2(1) FAILED!");
    return;
  }
  println(LDPL_INFO, "✅ get_symbols_v2(1) SUCCEED!");
  // The count is returned via a different mechanism - you need to
  // iterate or use a reasonable buffer size
  std::vector<ld_plugin_symbol> symbols(100);

  // Get actual symbols
  if (get_symbols_v2(
        handle, static_cast<int>(symbols.size()), symbols.data()) != LDPS_OK) {

    println(LDPL_INFO, "❌❌ get_symbols_v2({}) FAILED!", symbols.size());
    return;
  }
  println(LDPL_INFO, "✅✅ get_symbols_v2({}) SUCCEED!", symbols.size());

  // Process function symbols
  for (auto const& symbol : symbols) {
    if (symbol.name) {
      println(LDPL_INFO, "🔆 Symbol name: {}", symbol.name);
    } else {
      println(LDPL_INFO, "🔆 Symbol name: ???");
    }
    if (symbol.comdat_key) {
      println(LDPL_INFO, "    comdat_key: {}", symbol.comdat_key);
    }
    println(LDPL_INFO, "    version: {}", symbol.version);
    println(LDPL_INFO, "    resolution: {}", symbol.resolution);
    println(LDPL_INFO, "    section_kind: {}", symbol.section_kind);
    println(LDPL_INFO, "    def: {}", symbol.def);
    println(LDPL_INFO, "    size: {}", symbol.size);
    println(LDPL_INFO, "    type: {}", symbol.symbol_type);
    println(LDPL_INFO, "");
  }
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
      println(LDPL_INFO, "entry->tv_tag = {}", static_cast<int>(entry->tv_tag));
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
        case LDPT_GET_SYMBOLS:
          get_symbols = entry->tv_u.tv_get_symbols;
          println(LDPL_INFO, "🐞 LDPT_GET_SYMBOLS");
          break;
        case LDPT_GET_SYMBOLS_V2:
          get_symbols_v2 = entry->tv_u.tv_get_symbols;
          println(LDPL_INFO, "🐞 LDPT_GET_SYMBOLS_V2");
          break;
        case LDPT_GET_SYMBOLS_V3:
          get_symbols_v3 = entry->tv_u.tv_get_symbols;
          println(LDPL_INFO, "🐞 LDPT_GET_SYMBOLS_V3");
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

    println(LDPL_INFO, "®️ Registering Nearpoint plugin...");

    // Check that all resources have been acquired
    bool all_resources_acquired = true;

    if (add_input_file == nullptr) {
      println(LDPL_ERROR, "🪫 Resource 'add_input_file' is not available.");
      all_resources_acquired = false;
    }

    if (get_symbols == nullptr) {
      println(LDPL_ERROR, "🪫 Resource 'get_symbols' is not available.");
      all_resources_acquired = false;
    }

    if (register_claim_file == nullptr) {
      println(LDPL_ERROR,
              "🪫 Resource 'register_claim_file' is not available.");
      all_resources_acquired = false;
    }

    if (register_all_symbols_read == nullptr) {
      println(LDPL_ERROR,
              "🪫 Resource 'register_all_symbols_read' is not available.");
      all_resources_acquired = false;
    }

    if (register_cleanup == nullptr) {
      println(LDPL_ERROR, "🪫 Resource 'register_cleanup' is not available.");
      all_resources_acquired = false;
    }

    if (!all_resources_acquired) {
      return LDPS_ERR;
    }

    // Register handlers
    if (register_claim_file(claim_file_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    if (register_all_symbols_read(all_symbols_read_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    if (register_cleanup(cleanup_handler) != LDPS_OK) {
      return LDPS_ERR;
    }

    println(LDPL_INFO,
            "🔋 Nearpoint exception optimization ordering plugin loaded "
            "successfully");

    return LDPS_OK;
  }
}
