#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000a,
  0x08000040,
};

std::array<std::uint32_t, 29> const _normal_table_data = {
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (0 << 10) | 0, // entry=0, avg_size=0
  (1 << 10) | 0, // entry=1, avg_size=0
  (1 << 10) | 0, // entry=1, avg_size=0
  (1 << 10) | 0, // entry=1, avg_size=0
  (2 << 10) | 0, // entry=2, avg_size=0
  (3 << 10) | 0, // entry=3, avg_size=0
  (4 << 10) | 456, // entry=4, avg_size=456
  (5 << 10) | 332, // entry=5, avg_size=332
  (8 << 10) | 219, // entry=8, avg_size=219
  (12 << 10) | 114, // entry=12, avg_size=114
  (21 << 10) | 49, // entry=21, avg_size=49
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
