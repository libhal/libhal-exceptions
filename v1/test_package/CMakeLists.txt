# Copyright 2024 - 2025 Khalil Estell and the libhal contributors
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
project(test_package LANGUAGES CXX)

find_package(libhal-exceptions REQUIRED CONFIG)

add_executable(${PROJECT_NAME} main.cpp)
target_include_directories(${PROJECT_NAME} PUBLIC .)
target_compile_features(${PROJECT_NAME} PRIVATE cxx_std_20)
set_target_properties(${PROJECT_NAME} PROPERTIES CXX_EXTENSIONS OFF)
target_link_libraries(${PROJECT_NAME} PRIVATE libhal::exceptions)
target_compile_options(${PROJECT_NAME} PRIVATE -fexceptions -fno-rtti)

# Add nano newlib and nosys specs for ARM embedded systems
if(CMAKE_SYSTEM_PROCESSOR MATCHES "^arm" OR
   CMAKE_SYSTEM_PROCESSOR MATCHES "^ARM")
    if(CMAKE_SYSTEM_NAME STREQUAL "Generic" OR
       CMAKE_CROSSCOMPILING OR
       CMAKE_C_COMPILER MATCHES "arm.*gcc" OR
       CMAKE_CXX_COMPILER MATCHES "arm.*g\\+\\+")
        # NOTE: We disable the ODR violation because we need to have a way to
        # spell and address the types for the RTTI parent classes, but seeing
        # identical symbols with different representation triggers this warning.
        target_link_options(${PROJECT_NAME} PRIVATE
            --specs=nosys.specs
            -Wno-odr
        )

        message(STATUS "Added nosys.specs for ARM embedded target")
    endif()
endif()
