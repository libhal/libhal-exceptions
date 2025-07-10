#include <span>

#include <libhal-exceptions/control.hpp>

#include <resource_list.hpp>

void terminate_handler()
{
  while (true) {
    continue;
  }
}

int main()
{
  hal::set_terminate(terminate_handler);
  initialize_platform();
  application();
}

// NOLINTBEGIN(bugprone-reserved-identifier)
// NOLINTBEGIN(readability-identifier-naming)
namespace ke::__except_abi {
std::span<std::uint32_t> near_point_descriptor{};
std::span<std::uint32_t> normal_table{};
std::span<std::uint32_t> small_table{};
}  // namespace ke::__except_abi
// NOLINTEND(readability-identifier-naming)
// NOLINTEND(bugprone-reserved-identifier)
