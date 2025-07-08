#include <libhal-exceptions/control.hpp>

#include <resource_list.hpp>

void terminate_handler()
{
  while (true) {
    continue;
  }
}

int main()
{
  hal::set_terminate(terminate_handler);
  initialize_platform();
  application();
}

extern "C"
{
  void __aeabi_unwind_cpp_pr1(void*)
  {
  }
  void __aeabi_unwind_cpp_pr0(void*)
  {
  }
  void __aeabi_unwind_cpp_pr2(void*)
  {
  }
}
