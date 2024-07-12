# Copyright 2024 Khalil Estell
#
# Licensed under the Apache License, Version 2.0 (the "License");
# you may not use this file except in compliance with the License.
# You may obtain a copy of the License at
#
#      http://www.apache.org/licenses/LICENSE-2.0
#
# Unless required by applicable law or agreed to in writing, software
# distributed under the License is distributed on an "AS IS" BASIS,
# WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either express or implied.
# See the License for the specific language governing permissions and
# limitations under the License.

cmake_minimum_required(VERSION 3.15)

project(libhal-exceptions LANGUAGES CXX)


if("${RUNTIME}" STREQUAL "ARM_CORTEX_GCC")
set(SOURCE_LIST src/builtin/gcc/impl.cpp)
elseif("${RUNTIME}" STREQUAL "ARM_CORTEX_ESTELL")
set(SOURCE_LIST
    src/arm_cortex/estell/exception.cpp
    src/arm_cortex/estell/wrappers.cpp
)
else()
message(FATAL "Invalid Exception RUNTIME: '${RUNTIME}' provided!")
endif()

libhal_make_library(
  LIBRARY_NAME libhal-exceptions

  SOURCES
  src/control.cpp
  ${SOURCE_LIST}

  PACKAGES
  libhal-util

  LINK_LIBRARIES
  libhal::util
)

target_compile_definitions(libhal-exceptions PRIVATE
  OPTIMIZATION_LEVEL=${OPTIMIZATION_LEVEL})

if(NOT ${CMAKE_CROSSCOMPILING})
libhal_unit_test(
  LIBRARY_NAME libhal-exceptions

  SOURCES
  src/control.cpp
  tests/main.test.cpp
  ${SOURCE_LIST}

  PACKAGES
  libhal-util

  LINK_LIBRARIES
  libhal::util
)
endif()