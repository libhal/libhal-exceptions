# things I changed

- Reduced the number of instructions for capture
- Used array prefix for the pointers in pop reg range and just add at the end rather than incrementing the pointer each time
- Combine pop under mask because the order was wrong. We need all 15 bits to start from 0 to have the order be correct. Not 12 to 15 then 5 to 11
- Use bit_cast<> in `to_absolute_address` & `to_absolute_address_ptr`.
- Reduce the instructions for `restore_cpu_state`
- Remove shift variable in `read_uleb128`

info registers
r0             0x7fffffff          2147483647
r1             0x0                 0
r2             0x20000348          536871752
r3             0x80012f5           134222581
r4             0x20000348          536871752
r5             0x20000118          536871192
r6             0x20000278          536871544
r7             0x20000358          536871768
r8             0x7e                126
r9             0x0                 0
r10            0x0                 0
r11            0x0                 0
r12            0x0                 0
sp             0x200027d0          0x200027d0
lr             0x8001059           0x8001059 <application(resource_list&)+20>
pc             0x800107a           0x800107a <application(resource_list&)+54>
xpsr           0x61000000          1627389952
msp            0x200027d0          0x200027d0
psp            0x922f3724          0x922f3724
primask        0x0                 0
control        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0

(gdb) info registers
r0             0x200001cc          536871372
r1             0x1                 1
r2             0x8001085           134221957
r3             0x20000188          536871304
r4             0x20000348          536871752
r5             0x20000118          536871192
r6             0x0                 0
r7             0x0                 0
r8             0x7e                126
r9             0x0                 0
r10            0x0                 0
r11            0x0                 0
r12            0x0                 0
sp             0x200027d0          0x200027d0
lr             0x800108d           0x800108d <application(resource_list&)+72>
pc             0x800108c           0x800108c <application(resource_list&)+72>
xpsr           0x1000000           16777216
msp            0x200027d0          0x200027d0
psp            0x922f3724          0x922f3724
primask        0x0                 0
control        0x0                 0
basepri        0x0                 0
faultmask      0x0                 0