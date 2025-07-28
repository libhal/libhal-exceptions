#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000b,
  0x08000040,
};

std::array<std::uint32_t, 15> const _normal_table_data = {
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (0 << 11) | 0,     // entry=0, avg_size=0
  (1 << 11) | 0,     // entry=1, avg_size=0
  (1 << 11) | 0,     // entry=1, avg_size=0
  (2 << 11) | 1128,  // entry=2, avg_size=1128
  (4 << 11) | 363,   // entry=4, avg_size=363
  (8 << 11) | 146,   // entry=8, avg_size=146
  (21 << 11) | 49,   // entry=21, avg_size=49
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor =
  _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
