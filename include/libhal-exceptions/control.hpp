// Copyright 2024 Khalil Estell
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

#pragma once

#include <cstddef>
#include <cstdint>
#include <exception>
#include <memory_resource>
#include <span>

namespace hal {
/**
 * @brief Set the global exception allocator function
 *
 * More details on how you should use this API to come in the future.
 *
 * @param p_allocator - exception memory allocator implementation
 */
void set_exception_allocator(std::pmr::memory_resource& p_allocator) noexcept;

/**
 * @brief Get the global exception allocator function
 *
 * More details on how you should use this API to come in the future.
 *
 * @returns the global exception memory allocator implementation
 */
std::pmr::memory_resource& get_exception_allocator() noexcept;

/**
 * @brief Set the terminate handler
 *
 * @param p_terminate_handler - new global terminate handler
 */
std::terminate_handler set_terminate(
  std::terminate_handler p_terminate_handler) noexcept;

/**
 * @brief Get the terminate handler
 *
 * @return std::terminate_handler - the currently set terminate handler
 */
std::terminate_handler get_terminate() noexcept;

}  // namespace hal
