extern void run_test();
extern void activate_filler();
extern void initialize_platform();

int main()
{
  initialize_platform();
  run_test();

#if __CORTEX_M
  while (true) {
    continue;
  }
#endif
}
