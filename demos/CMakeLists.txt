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

cmake_minimum_required(VERSION 3.20)

project(demos LANGUAGES CXX)

set(platform_library $ENV{LIBHAL_PLATFORM_LIBRARY})
set(platform $ENV{LIBHAL_PLATFORM})

message(WARNING "${platform_library}")

if("${platform_library}" STREQUAL "")
    message(FATAL_ERROR
        "Build environment variable LIBHAL_PLATFORM_LIBRARY is required for " "this project.")
endif()

find_package(libhal-${platform_library} REQUIRED CONFIG)
find_package(libhal-__device__ REQUIRED CONFIG)
find_package(libhal-util REQUIRED CONFIG)

set(DEMOS __device__)

add_library(startup_code
    main.cpp
    platforms/${platform}.cpp)
target_include_directories(startup_code PUBLIC .)
target_compile_features(startup_code PRIVATE cxx_std_20)
target_link_libraries(startup_code PRIVATE
    libhal::${platform_library}
    libhal::__device__
    libhal::util)

foreach(demo IN LISTS DEMOS)
    set(current_project ${demo}.elf)
    message(STATUS "Generating Demo for \"${current_project}\"")
    add_executable(${current_project} applications/${demo}.cpp)
    target_include_directories(${current_project} PUBLIC .)
    target_compile_features(${current_project} PRIVATE cxx_std_20)
    target_compile_options(${current_project} PRIVATE -g)
    target_link_options(${current_project} PRIVATE --oslib=semihost)
    target_link_libraries(${current_project} PRIVATE
        libhal::${platform_library}
        libhal::__device__
        libhal::util
        startup_code)
    libhal_post_build(${current_project})
endforeach()
