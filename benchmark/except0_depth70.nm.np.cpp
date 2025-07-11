
#include <cstdint>

#include <span>

namespace ke::__except_abi {

using u32 = std::uint32_t;
using u32_span = std::span<std::uint32_t>;

namespace {
u32 _near_point_descriptor_data[] = {
  0x0000000a,
  0x00000007,
  0x0000011b,
  0x000099b3,
};

u32 _normal_table_data[] = {
  (0 << 9) | 0,    (0 << 9) | 0,    (1 << 9) | 0,    (1 << 9) | 0,
  (1 << 9) | 0,    (2 << 9) | 0,    (2 << 9) | 0,    (2 << 9) | 0,
  (3 << 9) | 0,    (4 << 9) | 0,    (5 << 9) | 0,    (6 << 9) | 0,
  (7 << 9) | 0,    (8 << 9) | 0,    (9 << 9) | 0,    (10 << 9) | 0,
  (12 << 9) | 0,   (13 << 9) | 0,   (15 << 9) | 0,   (17 << 9) | 0,
  (20 << 9) | 0,   (23 << 9) | 0,   (25 << 9) | 0,   (28 << 9) | 0,
  (32 << 9) | 0,   (36 << 9) | 0,   (42 << 9) | 0,   (49 << 9) | 31,
  (57 << 9) | 26,  (66 << 9) | 22,  (78 << 9) | 17,  (92 << 9) | 15,
  (108 << 9) | 12, (128 << 9) | 12, (149 << 9) | 12, (170 << 9) | 11,
  (192 << 9) | 9,  (220 << 9) | 6,  (260 << 9) | 3,  (335 << 9) | 0,
};
u32 _small_table_data[] = {
  (0 << 9) | 3,  (8 << 9) | 3,  (18 << 9) | 2,
  (28 << 9) | 2, (40 << 9) | 1, (66 << 9) | 0,
};
}  // namespace

u32_span near_point_descriptor = _near_point_descriptor_data;
u32_span normal_table = _normal_table_data;
u32_span small_table = _small_table_data;
}  // namespace ke::__except_abi
