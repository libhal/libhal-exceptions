#include <libhal-exceptions/control.hpp>
#include <new>

#include "resource_list.hpp"

void terminate_handler()
{
  while (true) {
    continue;
  }
}

int main()
{
  hal::set_terminate(terminate_handler);
  auto resources = initialize_platform();
  application(resources);
}

extern "C"
{

  [[gnu::section(".text.throw_bad_alloc")]]
  void __wrap__ZSt17__throw_bad_allocv()
  {
    throw std::bad_alloc();
  }

  [[gnu::section(".text.abort")]]
  void __wrap_abort()
  {
    while (true) {
      continue;
    }
  }
}
