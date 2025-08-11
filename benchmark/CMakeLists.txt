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

cmake_minimum_required(VERSION 3.25)

project(benchmark_error_handling LANGUAGES CXX)

# Always check that the $ENV{LIBHAL_PLATFORM_LIBRARY} & $ENV{LIBHAL_PLATFORM}
# environment variables are set by the profile.
if("$ENV{LIBHAL_PLATFORM_LIBRARY}" STREQUAL "")
    message(FATAL_ERROR
        "Build environment variable LIBHAL_PLATFORM_LIBRARY is required for " "this project.")
endif()
if("$ENV{LIBHAL_PLATFORM}" STREQUAL "")
    message(FATAL_ERROR
        "Build environment variable LIBHAL_PLATFORM is required for "
        "this project.")
endif()

find_package(libhal-$ENV{LIBHAL_PLATFORM_LIBRARY} REQUIRED)
find_package(prebuilt-picolibc QUIET)

set(startup_source_files main.cpp filler.cpp)

# Makes the platform/<platform_name>.cpp file optional
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/platforms/$ENV{LIBHAL_PLATFORM}.cpp")
    list(APPEND startup_source_files platforms/$ENV{LIBHAL_PLATFORM}.cpp)
endif()

add_library(startup_code ${startup_source_files})

target_include_directories(startup_code PUBLIC .)
target_compile_options(startup_code PRIVATE
  -g
  -Werror
  -Wall
  -Wextra
  -Wshadow
  -fno-threadsafe-statics
  $<$<COMPILE_LANGUAGE:CXX>:-fexceptions -fno-rtti>
)

target_link_libraries(startup_code PRIVATE
  libhal::$ENV{LIBHAL_PLATFORM_LIBRARY}
)

if(prebuilt-picolibc_FOUND)
    target_link_libraries(startup_code PRIVATE picolibc)
    message(STATUS "Found picolibc, linking it in!")
endif()

# Glob all the files in the directory 'generated_tests'
file(GLOB GENERATED_TEST "${CMAKE_CURRENT_SOURCE_DIR}/generated_tests/*.cpp")

set(BENCHMARK_COMPILE_OPTIONS
    -g
    -Werror
    -Wall
    -Wextra
    -Wshadow
    -fno-threadsafe-statics)

foreach(test_path ${GENERATED_TEST})
  get_filename_component(test_file_name ${test_path} NAME)
  set(elf ${test_file_name}.elf)

  message(STATUS "Generating Demo for \"${elf}\"")
  add_executable(${elf} ${test_path})
  target_include_directories(${elf} PRIVATE .)
  target_compile_options(${elf} PRIVATE ${BENCHMARK_COMPILE_OPTIONS})

  # Check if the test file name starts with "result_"
  string(REGEX MATCH "^result_" is_result_file ${test_file_name})
  if(is_result_file)
    target_compile_options(${elf} PRIVATE
      $<$<COMPILE_LANGUAGE:CXX>:-fno-exceptions>)
  else()
    target_compile_options(${elf} PRIVATE
      $<$<COMPILE_LANGUAGE:CXX>:-fexceptions>)
  endif()

  target_link_libraries(${elf} PRIVATE
    startup_code
    libhal::$ENV{LIBHAL_PLATFORM_LIBRARY}
  )
  target_link_options(${elf} PRIVATE -fno-threadsafe-statics
    -L${CMAKE_SOURCE_DIR}/
    -Wl,-Map=${CMAKE_BINARY_DIR}/${elf}.map
  )
  if(prebuilt-picolibc_FOUND)
    target_link_libraries(${elf} PRIVATE picolibc)
  endif()

  if(${CMAKE_CROSSCOMPILING})
    # Convert elf into .bin, .hex and other formats needed for programming
    # devices.
    libhal_post_build(${elf})
    libhal_disassemble(${elf})
  endif()
endforeach()

# Build nearpoint binary if if available
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/nearpoint.cpp")
  message(STATUS "nearpoint.cpp exists!")
  set(elf nearpoint.cpp.elf)
  message(STATUS "Generating Demo for \"${elf}\"")
  add_executable(${elf} generated_tests/except.cpp nearpoint.cpp)
  target_include_directories(${elf} PRIVATE .)
  target_compile_options(${elf} PRIVATE
    ${BENCHMARK_COMPILE_OPTIONS}
    -fexceptions)

  target_link_libraries(${elf} PRIVATE
    startup_code
    libhal::$ENV{LIBHAL_PLATFORM_LIBRARY}
  )
  target_link_options(${elf} PRIVATE -fno-threadsafe-statics
    -L${CMAKE_SOURCE_DIR}/
    -Wl,-Map=${CMAKE_BINARY_DIR}/${elf}.map
    -Torder.ld
  )
  if(prebuilt-picolibc_FOUND)
    target_link_libraries(${elf} PRIVATE picolibc)
  endif()

  if(${CMAKE_CROSSCOMPILING})
    # Convert elf into .bin, .hex and other formats needed for programming
    # devices.
    libhal_post_build(${elf})
    libhal_disassemble(${elf})
  endif()
else()
    message(WARNING "nearpoint.cpp does not exist")
endif()


# Build nearpoint binary if if available
if(EXISTS "${CMAKE_CURRENT_SOURCE_DIR}/fast_gcc_unwind.cpp")
  message(STATUS "fast_gcc_unwind.cpp exists!")
  set(elf fast_gcc_unwind.cpp.elf)
  message(STATUS "Generating Demo for \"${elf}\"")
  add_executable(${elf} generated_tests/except.cpp fast_gcc_unwind.cpp)
  target_include_directories(${elf} PRIVATE .)
  target_compile_options(${elf} PRIVATE
    ${BENCHMARK_COMPILE_OPTIONS}
    -fexceptions
    -Wno-error=attributes)

  target_link_libraries(${elf} PRIVATE
    startup_code
    libhal::$ENV{LIBHAL_PLATFORM_LIBRARY}
  )
  target_link_options(${elf} PRIVATE -fno-threadsafe-statics
    -L${CMAKE_SOURCE_DIR}/
    -Wl,-Map=${CMAKE_BINARY_DIR}/${elf}.map
    -Wl,--wrap=__gnu_unwind_execute
    -Wl,--wrap=_Unwind_VRS_Pop
    -Wl,--wrap=__gnu_unwind_frame
  )
  if(prebuilt-picolibc_FOUND)
    target_link_libraries(${elf} PRIVATE picolibc)
  endif()

  if(${CMAKE_CROSSCOMPILING})
    # Convert elf into .bin, .hex and other formats needed for programming
    # devices.
    libhal_post_build(${elf})
    libhal_disassemble(${elf})
  endif()
else()
    message(WARNING "nearpoint.cpp does not exist")
endif()
