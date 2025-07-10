// Copyright 2024 - 2025 Khalil Estell and the libhal contributors
//
// Licensed under the Apache License, Version 2.0 (the "License");
// you may not use this file except in compliance with the License.
// You may obtain a copy of the License at
//
//      http://www.apache.org/licenses/LICENSE-2.0
//
// Unless required by applicable law or agreed to in writing, software
// distributed under the License is distributed on an "AS IS" BASIS,
// WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
// See the License for the specific language governing permissions and
// limitations under the License.

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

void end_benchmark()
{
}
