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
  (1 << 11) | 1, // Block(start=1, count=1)
  (3 << 11) | 2, // Block(start=3, count=2)
  (5 << 11) | 2, // Block(start=5, count=2)
  (7 << 11) | 8, // Block(start=7, count=8)
  (15 << 11) | 20, // Block(start=15, count=20)
  (35 << 11) | 25, // Block(start=35, count=25)
  (60 << 11) | 27, // Block(start=60, count=27)
  (87 << 11) | 29, // Block(start=87, count=29)
  (116 << 11) | 30, // Block(start=116, count=30)
  (146 << 11) | 28, // Block(start=146, count=28)
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
