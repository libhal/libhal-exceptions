#include <cstdio>
#include <cstring>

#include <string_view>

#include <plugin-api.h>

// Plugin entry point - this function must exist
enum ld_plugin_status onload(struct ld_plugin_tv* tv);
namespace {
// Plugin version info
[[maybe_unused]] std::string_view const plugin_version = "1.0";

// Function to handle messages/logging
ld_plugin_message message_handler = nullptr;

// All symbols read handler - called when all symbols are available
enum ld_plugin_status all_symbols_read_handler()
{
  if (message_handler) {
    message_handler(LDPL_INFO, "All symbols have been read");
  }

  return LDPS_OK;
}

// Cleanup handler - called at the end of linking
enum ld_plugin_status cleanup_handler()
{
  if (message_handler) {
    message_handler(LDPL_INFO, "Plugin cleanup");
  }

  return LDPS_OK;
}
}  // namespace

extern "C"
{

  // Main plugin entry point
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
            if (message_handler) {
              message_handler(LDPL_ERROR,
                              "API version mismatch: expected %d, got %d",
                              LD_PLUGIN_API_VERSION,
                              entry->tv_u.tv_val);
            }
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

    if (message_handler) {
      message_handler(LDPL_INFO, "Simple linker plugin loaded successfully");
    }

    return LDPS_OK;
  }
}
