#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000b,
  0x08000048,
};

std::array<std::uint32_t, 20> const _normal_table_data = {
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (0 << 11) | 1, // Block(start=0, count=1)
  (1 << 11) | 1, // Block(start=1, count=1)
  (1 << 11) | 1, // Block(start=1, count=1)
  (2 << 11) | 2, // Block(start=2, count=2)
  (3 << 11) | 2, // Block(start=3, count=2)
  (4 << 11) | 3, // Block(start=4, count=3)
  (6 << 11) | 3, // Block(start=6, count=3)
  (8 << 11) | 4, // Block(start=8, count=4)
  (11 << 11) | 8, // Block(start=11, count=8)
  (18 << 11) | 14, // Block(start=18, count=14)
  (31 << 11) | 21, // Block(start=31, count=21)
  (51 << 11) | 27, // Block(start=51, count=27)
  (77 << 11) | 29, // Block(start=77, count=29)
  (105 << 11) | 31, // Block(start=105, count=31)
  (135 << 11) | 24, // Block(start=135, count=24)
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
