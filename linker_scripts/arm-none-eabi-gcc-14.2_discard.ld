SECTIONS {
  /DISCARD/ : {
    *unwind-c.o(.text*)
    *(.text.next_unwind_byte)
    *(.text.__gnu_unwind_execute)
    *(.text.__gnu_unwind_pr_common)
    *(.text.__aeabi_unwind_cpp_pr0)
    *(.text.__aeabi_unwind_cpp_pr1)
    *(.text.__aeabi_unwind_cpp_pr2)
  }
  .text : {
    __gcc_personality_v0 = .;
    __gxx_personality_v0 = .;
    __aeabi_unwind_cpp_pr0 = .;
    __aeabi_unwind_cpp_pr1 = .;
    __aeabi_unwind_cpp_pr2 = .;
    __gnu_unwind_pr_common = .;
    LONG(0);
  }
}
INSERT BEFORE .text;