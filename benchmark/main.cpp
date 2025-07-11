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

#include <span>

#include "platform.hpp"

int main()
{
  initialize_platform();
  link_filler_functions();
  run_test();
  end_benchmark();
}

// // NOLINTBEGIN(bugprone-reserved-identifier)
// // NOLINTBEGIN(readability-identifier-naming)
// namespace ke::__except_abi {
// [[gnu::weak]] std::span<std::uint32_t> near_point_descriptor{};
// [[gnu::weak]] std::span<std::uint32_t> normal_table{};
// [[gnu::weak]] std::span<std::uint32_t> small_table{};
// }  // namespace ke::__except_abi
// // NOLINTEND(readability-identifier-naming)
// // NOLINTEND(bugprone-reserved-identifier)
