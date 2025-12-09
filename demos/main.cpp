#include <exception>

#include <resource_list.hpp>

void terminate_handler()
{
  while (true) {
    continue;
  }
}

int main()
{
  std::set_terminate(terminate_handler);
  initialize_platform();
  application();
}
