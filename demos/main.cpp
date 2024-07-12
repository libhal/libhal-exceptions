#include <libhal-exceptions/control.hpp>

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