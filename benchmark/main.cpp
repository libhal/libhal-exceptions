extern void run_test();
[[gnu::weak]] [[gnu::noinline]] void run_test_again_but_different()
{
}
extern void activate_filler();
extern void initialize_platform();
extern void end_benchmark();

int main()
{
  initialize_platform();
  run_test();
  run_test_again_but_different();
  end_benchmark();
}
