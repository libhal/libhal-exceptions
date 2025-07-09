#include <chrono>
#include <print>

void initialize_platform()
{
}

void log_start(std::string_view p_message)
{
  std::println("{}", p_message);
}

using timestamp = decltype(std::chrono::high_resolution_clock::now());
timestamp start_time;
std::chrono::nanoseconds total_time;

void start()
{
  start_time = std::chrono::high_resolution_clock::now();
}

void end()
{
  auto end_time = std::chrono::high_resolution_clock::now();
  total_time = end_time - start_time;
  std::println("Total time = {}", total_time);
}
