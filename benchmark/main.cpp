extern void run_test();
extern void activate_filler();
extern void initialize_platform();
extern void end_benchmark();

int main()
{
  initialize_platform();
  run_test();
  end_benchmark();
}
