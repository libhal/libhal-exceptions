
#include <cstdint>

#include <span>

namespace hal::__except_abi {

using u32 = std::uint32_t;
using u32_span = std::span<std::uint32_t>;

namespace {
u32 _near_point_descriptor_data[] = {
  0x00000009,
  0x00000007,
  0x00000030,
  0x000016a2,
};

u32 _normal_table_data[] = {
  (0 << 9) | 0,  (0 << 9) | 0,  (1 << 9) | 0,   (2 << 9) | 0,
  (3 << 9) | 0,  (3 << 9) | 0,  (4 << 9) | 0,   (6 << 9) | 0,
  (10 << 9) | 0, (15 << 9) | 0, (23 << 9) | 10, (35 << 9) | 2,
};
u32 _small_table_data[] = { 0 };
}  // namespace

u32_span near_point_descriptor = _near_point_descriptor_data;
u32_span normal_table = _normal_table_data;
u32_span small_table = _small_table_data;
}  // namespace hal::__except_abi
