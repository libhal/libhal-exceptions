#include <cstring>

#include <format>
#include <string>
#include <string_view>

#include <plugin-api.h>

// Plugin entry point - this function must exist
enum ld_plugin_status onload(struct ld_plugin_tv* tv);
namespace {
// Plugin version info
[[maybe_unused]] std::string_view const plugin_version = "1.0";

// Function to handle messages/logging
ld_plugin_message message_handler = nullptr;

template<class... Args>
void println(ld_plugin_level p_level, std::string_view p_format, Args... p_args)
{
  if (not message_handler) {
    return;
  }

  auto const log = std::vformat(p_format, std::make_format_args(p_args...));

  message_handler(p_level, log.c_str());
}

// All symbols read handler - called when all symbols are available
enum ld_plugin_status all_symbols_read_handler()
{
  println(LDPL_INFO, "All symbols have been read");

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
        case LDPT_REGISTER_ALL_SYMBOLS_READ_HOOK:
          register_all_symbols_read = entry->tv_u.tv_register_all_symbols_read;
          break;
        case LDPT_REGISTER_CLEANUP_HOOK:
          register_cleanup = entry->tv_u.tv_register_cleanup;
          break;
        case LDPT_API_VERSION:
          // Check API version compatibility
          if (entry->tv_u.tv_val != LD_PLUGIN_API_VERSION) {
            // TODO(kammce): make formatters for each of these
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

    println(LDPL_INFO, "Simple linker plugin loaded successfully");

    return LDPS_OK;
  }
}
