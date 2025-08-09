#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 4> const _nearpoint_descriptor_data = {
  0x0000000a,  // normal block power
  0x08000040,  // normal program start address
  0x00000008,  // small block power
  0x08009e2a,  // small block address
};

std::array<std::uint32_t, 40> const _normal_table_data = {
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (2 << 10) | 0,     // entry=2, avg_size=0
  (2 << 10) | 0,     // entry=2, avg_size=0
  (3 << 10) | 0,     // entry=3, avg_size=0
  (3 << 10) | 0,     // entry=3, avg_size=0
  (4 << 10) | 0,     // entry=4, avg_size=0
  (5 << 10) | 0,     // entry=5, avg_size=0
  (6 << 10) | 996,   // entry=6, avg_size=996
  (7 << 10) | 754,   // entry=7, avg_size=754
  (9 << 10) | 448,   // entry=9, avg_size=448
  (10 << 10) | 332,  // entry=10, avg_size=332
  (13 << 10) | 228,  // entry=13, avg_size=228
  (18 << 10) | 160,  // entry=18, avg_size=160
  (24 << 10) | 148,  // entry=24, avg_size=148
  (31 << 10) | 109,  // entry=31, avg_size=109
  (40 << 10) | 82,   // entry=40, avg_size=82
  (52 << 10) | 80,   // entry=52, avg_size=80
  (65 << 10) | 76,   // entry=65, avg_size=76
  (78 << 10) | 76,   // entry=78, avg_size=76
  (92 << 10) | 72,   // entry=92, avg_size=72
  (106 << 10) | 68,  // entry=106, avg_size=68
  (121 << 10) | 68,  // entry=121, avg_size=68
  (136 << 10) | 68,  // entry=136, avg_size=68
  (151 << 10) | 54,  // entry=151, avg_size=54
};

std::array<std::uint32_t, 1> const _small_table_data = {};

}  // namespace

[[gnu::used]]
std::span<std::uint32_t const> nearpoint_descriptor =
  _nearpoint_descriptor_data;
[[gnu::used]]
std::span<std::uint32_t const> normal_table = _normal_table_data;
[[gnu::used]]
std::span<std::uint32_t const> small_table = _small_table_data;
}  // namespace ke::__except_abi::inline v1
