# things I changed

- Reduced the number of instructions for capture
- Used array prefix for the pointers in pop reg range and just add at the end rather than incrementing the pointer each time
- Combine pop under mask because the order was wrong. We need all 15 bits to start from 0 to have the order be correct. Not 12 to 15 then 5 to 11
- Use bit_cast<> in `to_absolute_address` & `to_absolute_address_ptr`.
- Reduce the instructions for `restore_cpu_state`