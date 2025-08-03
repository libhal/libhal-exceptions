#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000a,
  0x08000048,
};

std::array<std::uint32_t, 41> const _normal_table_data = {
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
  (1 << 10) | 0, // entry=1, avg_size=0
  (2 << 10) | 0, // entry=2, avg_size=0
  (2 << 10) | 0, // entry=2, avg_size=0
  (3 << 10) | 0, // entry=3, avg_size=0
  (3 << 10) | 0, // entry=3, avg_size=0
  (4 << 10) | 0, // entry=4, avg_size=0
  (5 << 10) | 0, // entry=5, avg_size=0
  (6 << 10) | 996, // entry=6, avg_size=996
  (7 << 10) | 768, // entry=7, avg_size=768
  (8 << 10) | 594, // entry=8, avg_size=594
  (10 << 10) | 297, // entry=10, avg_size=297
  (13 << 10) | 230, // entry=13, avg_size=230
  (17 << 10) | 185, // entry=17, avg_size=185
  (22 << 10) | 153, // entry=22, avg_size=153
  (29 << 10) | 145, // entry=29, avg_size=145
  (36 << 10) | 94, // entry=36, avg_size=94
  (47 << 10) | 80, // entry=47, avg_size=80
  (59 << 10) | 77, // entry=59, avg_size=77
  (73 << 10) | 76, // entry=73, avg_size=76
  (86 << 10) | 75, // entry=86, avg_size=75
  (100 << 10) | 69, // entry=100, avg_size=69
  (115 << 10) | 68, // entry=115, avg_size=68
  (130 << 10) | 68, // entry=130, avg_size=68
  (145 << 10) | 66, // entry=145, avg_size=66
  (160 << 10) | 47, // entry=160, avg_size=47
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
