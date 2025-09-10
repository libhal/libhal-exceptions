#include <cstdint>

#include <array>
#include <span>

// NOLINTNEXTLINE
namespace ke::__except_abi::inline v1 {

namespace {
// NOLINTNEXTLINE
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000b,
  0x08000044,
};

// NOLINTNEXTLINE
std::array<std::uint32_t, 18> const _normal_table_data = {
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (1 << 11) | 1, // Block(start=1, count=1)
  (1 << 11) | 1, // Block(start=1, count=1)
  (2 << 11) | 2, // Block(start=2, count=2)
  (3 << 11) | 3, // Block(start=3, count=3)
  (5 << 11) | 3, // Block(start=5, count=3)
  (7 << 11) | 7, // Block(start=7, count=7)
  (13 << 11) | 14, // Block(start=13, count=14)
  (26 << 11) | 20, // Block(start=26, count=20)
  (45 << 11) | 27, // Block(start=45, count=27)
  (71 << 11) | 28, // Block(start=71, count=28)
  (98 << 11) | 31, // Block(start=98, count=31)
  (128 << 11) | 27, // Block(start=128, count=27)
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
