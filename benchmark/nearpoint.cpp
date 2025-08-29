#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000b,
  0x08000044,
};

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
  (7 << 11) | 6, // Block(start=7, count=6)
  (12 << 11) | 14, // Block(start=12, count=14)
  (25 << 11) | 20, // Block(start=25, count=20)
  (44 << 11) | 27, // Block(start=44, count=27)
  (70 << 11) | 28, // Block(start=70, count=28)
  (97 << 11) | 32, // Block(start=97, count=32)
  (128 << 11) | 26, // Block(start=128, count=26)
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
