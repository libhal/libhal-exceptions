# Copyright 2024 Khalil Estell
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
# http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.15)

project(demos LANGUAGES CXX)

set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} --save-temps")

libhal_build_demos(
  DEMOS
  single_level
  multi_levels
  multiple_virtual_inheritance

  INCLUDES
  .

  SOURCES
  single_level.elf.nm.np.cpp

  PACKAGES
  libhal-exceptions

  LINK_LIBRARIES
  libhal::exceptions

  LINK_FLAGS
  -L${CMAKE_SOURCE_DIR}/
  -Tlinker-stm32f103.ld
  -Wl,--wrap=_ZSt17__throw_bad_allocv
  -Wl,--wrap=abort
)
