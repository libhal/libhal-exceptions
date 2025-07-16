#include <cstdint>
#include <span>

namespace hal::__except_abi {

using u32 = std::uint32_t;
using u32_span = std::span<std::uint32_t>;

namespace {
u32 _near_point_descriptor_data[] = {
  0x00000009,
  0x00000008,
  0x00000000,
  0x08000040,
};

u32 _normal_table_data[] = {
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (3 << 9) | 0, // entry=3, size=0
  (3 << 9) | 0, // entry=3, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (5 << 9) | 0, // entry=5, size=0
  (5 << 9) | 0, // entry=5, size=0
  (6 << 9) | 0, // entry=6, size=0
  (6 << 9) | 0, // entry=6, size=0
  (7 << 9) | 0, // entry=7, size=0
  (8 << 9) | 0, // entry=8, size=0
  (8 << 9) | 0, // entry=8, size=0
  (9 << 9) | 0, // entry=9, size=0
  (10 << 9) | 0, // entry=10, size=0
  (11 << 9) | 0, // entry=11, size=464
  (12 << 9) | 0, // entry=12, size=456
  (13 << 9) | 0, // entry=13, size=372
  (14 << 9) | 0, // entry=14, size=366
  (16 << 9) | 0, // entry=16, size=360
  (17 << 9) | 0, // entry=17, size=354
  (19 << 9) | 0, // entry=19, size=340
  (20 << 9) | 0, // entry=20, size=314
  (22 << 9) | 0, // entry=22, size=286
  (24 << 9) | 0, // entry=24, size=268
  (25 << 9) | 0, // entry=25, size=217
  (28 << 9) | 0, // entry=28, size=161
  (31 << 9) | 0, // entry=31, size=153
  (34 << 9) | 0, // entry=34, size=148
  (37 << 9) | 0, // entry=37, size=134
  (41 << 9) | 0, // entry=41, size=128
  (45 << 9) | 0, // entry=45, size=114
  (50 << 9) | 0, // entry=50, size=100
  (55 << 9) | 0, // entry=55, size=91
  (60 << 9) | 0, // entry=60, size=84
  (66 << 9) | 0, // entry=66, size=73
  (73 << 9) | 0, // entry=73, size=70
  (80 << 9) | 15, // entry=80, size=63
  (88 << 9) | 14, // entry=88, size=58
  (97 << 9) | 12, // entry=97, size=48
  (107 << 9) | 12, // entry=107, size=48
  (118 << 9) | 12, // entry=118, size=48
  (129 << 9) | 11, // entry=129, size=47
  (139 << 9) | 12, // entry=139, size=48
  (150 << 9) | 12, // entry=150, size=48
  (161 << 9) | 11, // entry=161, size=47
  (171 << 9) | 10, // entry=171, size=43
  (183 << 9) | 8, // entry=183, size=32
  (199 << 9) | 5, // entry=199, size=22
  (221 << 9) | 3, // entry=221, size=15
  (254 << 9) | 1, // entry=254, size=4
};

u32 _small_table_data[] = {
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (0 << 9) | 0, // entry=0, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (1 << 9) | 0, // entry=1, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (2 << 9) | 0, // entry=2, size=0
  (3 << 9) | 0, // entry=3, size=0
  (3 << 9) | 0, // entry=3, size=0
  (3 << 9) | 0, // entry=3, size=0
  (3 << 9) | 0, // entry=3, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (4 << 9) | 0, // entry=4, size=0
  (5 << 9) | 0, // entry=5, size=0
  (5 << 9) | 0, // entry=5, size=0
  (5 << 9) | 0, // entry=5, size=0
  (5 << 9) | 0, // entry=5, size=0
  (6 << 9) | 0, // entry=6, size=0
  (6 << 9) | 0, // entry=6, size=0
  (6 << 9) | 0, // entry=6, size=0
  (6 << 9) | 0, // entry=6, size=0
  (7 << 9) | 0, // entry=7, size=0
  (7 << 9) | 0, // entry=7, size=0
  (7 << 9) | 0, // entry=7, size=0
  (8 << 9) | 0, // entry=8, size=0
  (8 << 9) | 0, // entry=8, size=0
  (8 << 9) | 0, // entry=8, size=0
  (9 << 9) | 0, // entry=9, size=0
  (9 << 9) | 0, // entry=9, size=0
  (10 << 9) | 0, // entry=10, size=0
  (10 << 9) | 0, // entry=10, size=0
  (11 << 9) | 0, // entry=11, size=0
  (11 << 9) | 0, // entry=11, size=0
  (12 << 9) | 0, // entry=12, size=0
  (12 << 9) | 0, // entry=12, size=0
  (13 << 9) | 0, // entry=13, size=0
  (13 << 9) | 0, // entry=13, size=0
  (14 << 9) | 0, // entry=14, size=0
  (15 << 9) | 0, // entry=15, size=0
  (16 << 9) | 0, // entry=16, size=0
  (16 << 9) | 0, // entry=16, size=0
  (17 << 9) | 0, // entry=17, size=0
  (18 << 9) | 0, // entry=18, size=0
  (18 << 9) | 0, // entry=18, size=0
  (19 << 9) | 0, // entry=19, size=0
  (20 << 9) | 0, // entry=20, size=0
  (21 << 9) | 0, // entry=21, size=0
  (22 << 9) | 0, // entry=22, size=0
  (23 << 9) | 0, // entry=23, size=0
  (23 << 9) | 0, // entry=23, size=0
  (24 << 9) | 0, // entry=24, size=0
  (25 << 9) | 0, // entry=25, size=248
  (26 << 9) | 0, // entry=26, size=199
  (28 << 9) | 0, // entry=28, size=164
  (29 << 9) | 0, // entry=29, size=160
  (31 << 9) | 0, // entry=31, size=156
  (32 << 9) | 0, // entry=32, size=152
  (34 << 9) | 0, // entry=34, size=150
  (36 << 9) | 0, // entry=36, size=144
  (37 << 9) | 0, // entry=37, size=138
  (39 << 9) | 0, // entry=39, size=132
  (41 << 9) | 0, // entry=41, size=130
  (43 << 9) | 0, // entry=43, size=128
  (45 << 9) | 0, // entry=45, size=122
  (47 << 9) | 0, // entry=47, size=109
  (50 << 9) | 0, // entry=50, size=106
  (52 << 9) | 0, // entry=52, size=96
  (55 << 9) | 0, // entry=55, size=92
  (57 << 9) | 0, // entry=57, size=92
  (60 << 9) | 0, // entry=60, size=87
  (63 << 9) | 0, // entry=63, size=81
  (66 << 9) | 0, // entry=66, size=76
  (69 << 9) | 0, // entry=69, size=71
  (73 << 9) | 0, // entry=73, size=71
  (77 << 9) | 0, // entry=77, size=67
  (80 << 9) | 0, // entry=80, size=63
  (84 << 9) | 0, // entry=84, size=63
  (88 << 9) | 0, // entry=88, size=60
  (92 << 9) | 0, // entry=92, size=56
  (97 << 9) | 0, // entry=97, size=48
  (102 << 9) | 0, // entry=102, size=48
  (107 << 9) | 0, // entry=107, size=47
  (113 << 9) | 0, // entry=113, size=48
  (118 << 9) | 0, // entry=118, size=48
  (123 << 9) | 0, // entry=123, size=47
  (129 << 9) | 0, // entry=129, size=48
  (134 << 9) | 0, // entry=134, size=48
  (139 << 9) | 0, // entry=139, size=47
  (145 << 9) | 0, // entry=145, size=48
  (150 << 9) | 0, // entry=150, size=48
  (155 << 9) | 0, // entry=155, size=47
  (161 << 9) | 0, // entry=161, size=48
  (166 << 9) | 0, // entry=166, size=48
  (171 << 9) | 0, // entry=171, size=45
  (177 << 9) | 0, // entry=177, size=42
  (183 << 9) | 0, // entry=183, size=36
  (190 << 9) | 7, // entry=190, size=28
  (199 << 9) | 6, // entry=199, size=26
  (208 << 9) | 5, // entry=208, size=20
  (221 << 9) | 4, // entry=221, size=17
  (235 << 9) | 3, // entry=235, size=13
  (254 << 9) | 1, // entry=254, size=4
};
}  // namespace

u32_span near_point_descriptor = _near_point_descriptor_data;
u32_span normal_table = _normal_table_data;
u32_span small_table = _small_table_data;

}  // namespace hal::__except_abi
