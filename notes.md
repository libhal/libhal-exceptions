# things I changed

- Reduced the number of instructions for capture
- Used array prefix for the pointers in pop reg range and just add at the end rather than incrementing the pointer each time
- Combine pop under mask because the order was wrong. We need all 15 bits to start from 0 to have the order be correct. Not 12 to 15 then 5 to 11
- Use bit_cast<> in `to_absolute_address` & `to_absolute_address_ptr`.
- Reduce the instructions for `restore_cpu_state`
- Remove shift variable in `read_uleb128`

- I've turned destructors back on and we are terminating. Looks like the encoding byte has 0x15 which we don't support. 0x5 for the encoding type is not present. So we need to figure out what that is. Its either us reading the wrong data OR a new format we need to handle.