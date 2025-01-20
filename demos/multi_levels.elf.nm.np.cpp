
#include <cstdint>

#include <span>

namespace hal::__except_abi {

using u32 = std::uint32_t;
using u32_span = std::span<std::uint32_t>;

namespace {
u32 _near_point_descriptor_data[] = {
  0x0000000a,
  0x00000007,
  0x0000006a,
  0x0000c996,
};


u32 _normal_table_data[] = {
  (0 << 9) | 0,
  (0 << 9) | 0,
  (0 << 9) | 0,
  (0 << 9) | 0,
  (0 << 9) | 0,
  (1 << 9) | 0,
  (1 << 9) | 0,
  (1 << 9) | 0,
  (1 << 9) | 0,
  (2 << 9) | 0,
  (2 << 9) | 0,
  (2 << 9) | 0,
  (2 << 9) | 0,
  (3 << 9) | 0,
  (3 << 9) | 0,
  (3 << 9) | 0,
  (3 << 9) | 0,
  (4 << 9) | 0,
  (4 << 9) | 0,
  (4 << 9) | 0,
  (5 << 9) | 0,
  (5 << 9) | 0,
  (5 << 9) | 0,
  (6 << 9) | 0,
  (6 << 9) | 0,
  (6 << 9) | 0,
  (7 << 9) | 0,
  (7 << 9) | 0,
  (8 << 9) | 0,
  (8 << 9) | 0,
  (9 << 9) | 0,
  (10 << 9) | 0,
  (10 << 9) | 0,
  (11 << 9) | 0,
  (12 << 9) | 0,
  (12 << 9) | 0,
  (13 << 9) | 0,
  (15 << 9) | 0,
  (16 << 9) | 0,
  (17 << 9) | 0,
  (19 << 9) | 0,
  (20 << 9) | 0,
  (22 << 9) | 0,
  (25 << 9) | 0,
  (29 << 9) | 0,
  (35 << 9) | 27,
  (44 << 9) | 23,
  (54 << 9) | 24,
  (65 << 9) | 24,
  (76 << 9) | 17,
  (90 << 9) | 6,
};
u32 _small_table_data[] = {
  0,
};
}  // namespace

u32_span near_point_descriptor = _near_point_descriptor_data;
u32_span normal_table = _normal_table_data;
u32_span small_table = _small_table_data;
}  // namespace hal::__except_abi
