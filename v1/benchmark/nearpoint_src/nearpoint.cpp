#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 2> const _near_point_descriptor_data = {
  0x0000000a,
  0x08000040,
};

std::array<std::uint32_t, 48> const _normal_table_data = {
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
  (2 << 10) | 0, // entry=2, avg_size=0
  (3 << 10) | 996, // entry=3, avg_size=996
  (4 << 10) | 754, // entry=4, avg_size=754
  (6 << 10) | 720, // entry=6, avg_size=720
  (7 << 10) | 696, // entry=7, avg_size=696
  (9 << 10) | 672, // entry=9, avg_size=672
  (10 << 10) | 672, // entry=10, avg_size=672
  (12 << 10) | 624, // entry=12, avg_size=624
  (13 << 10) | 568, // entry=13, avg_size=568
  (15 << 10) | 504, // entry=15, avg_size=504
  (17 << 10) | 480, // entry=17, avg_size=480
  (19 << 10) | 405, // entry=19, avg_size=405
  (22 << 10) | 344, // entry=22, avg_size=344
  (24 << 10) | 296, // entry=24, avg_size=296
  (28 << 10) | 233, // entry=28, avg_size=233
  (32 << 10) | 218, // entry=32, avg_size=218
  (37 << 10) | 145, // entry=37, avg_size=145
  (43 << 10) | 118, // entry=43, avg_size=118
  (52 << 10) | 74, // entry=52, avg_size=74
  (66 << 10) | 68, // entry=66, avg_size=68
  (81 << 10) | 68, // entry=81, avg_size=68
  (96 << 10) | 65, // entry=96, avg_size=65
  (111 << 10) | 64, // entry=111, avg_size=64
  (127 << 10) | 64, // entry=127, avg_size=64
  (143 << 10) | 64, // entry=143, avg_size=64
  (159 << 10) | 64, // entry=159, avg_size=64
  (175 << 10) | 64, // entry=175, avg_size=64
  (191 << 10) | 64, // entry=191, avg_size=64
  (207 << 10) | 64, // entry=207, avg_size=64
  (223 << 10) | 64, // entry=223, avg_size=64
  (239 << 10) | 64, // entry=239, avg_size=64
  (255 << 10) | 53, // entry=255, avg_size=53
};

}  // namespace

std::span<std::uint32_t const> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t const> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
