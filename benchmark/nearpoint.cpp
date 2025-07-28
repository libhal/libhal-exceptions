#include <cstdint>

#include <array>
#include <span>

namespace ke::__except_abi::inline v1 {

namespace {
std::array<std::uint32_t, 1> _near_point_descriptor_data = {
  0x0000000a,
};

std::array<std::uint32_t, 27> _normal_table_data = {
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
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (0 << 10) | 0,     // entry=0, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (1 << 10) | 0,     // entry=1, avg_size=0
  (2 << 10) | 0,     // entry=2, avg_size=0
  (3 << 10) | 1020,  // entry=3, avg_size=1020
  (4 << 10) | 371,   // entry=4, avg_size=371
  (7 << 10) | 257,   // entry=7, avg_size=257
  (11 << 10) | 95,   // entry=11, avg_size=95
  (20 << 10) | 38,   // entry=20, avg_size=38
};

}  // namespace

std::span<std::uint32_t> near_point_descriptor = _near_point_descriptor_data;
std::span<std::uint32_t> normal_table = _normal_table_data;
}  // namespace ke::__except_abi::inline v1
