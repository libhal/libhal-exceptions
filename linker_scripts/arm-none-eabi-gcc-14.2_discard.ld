SECTIONS {
  /DISCARD/ : {
    *unwind-c.o(.text*)
  }
  .text : {
    __gcc_personality_v0 = .;
    LONG(0)
    __gxx_personality_v0 = .;
    LONG(0)
  }
}
INSERT BEFORE .text;