SECTIONS {
  /DISCARD/ : {
    *unwind-c.o(.text*)
  }
}
INSERT BEFORE .text;