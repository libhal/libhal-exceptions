# Copyright 2024 - 2025 Khalil Estell and the libhal contributors
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

from conan import ConanFile
from conan.tools.cmake import CMake, cmake_layout
from conan.tools.files import copy
from conan.tools.build import check_min_cppstd
from pathlib import Path

required_conan_version = ">=2.0.14"


class libhal_exceptions_conan(ConanFile):
    name = "libhal-exceptions"
    license = "Apache-2.0"
    url = "https://github.com/conan-io/conan-center-index"
    homepage = "https://github.com/libhal/libhal-exceptions"
    description = (
        "Exception handling runtime support for the libhal ecosystem.")
    topics = ("exceptions", "error", "terminate", "unexpected")
    settings = "compiler", "build_type", "os", "arch"
    generators = "CMakeDeps", "CMakeToolchain", "VirtualBuildEnv"
    exports_sources = ("include/*", "tests/*", "LICENSE",
                       "CMakeLists.txt", "src/*", "linker_scripts/*")
    options = {
        "default_allocator": [True, False],
        "runtime": [
            "builtin",
            "estell",
        ]
    }
    default_options = {
        "default_allocator": True,
        "runtime": "builtin",
    }

    @property
    def _min_cppstd(self):
        return "20"

    @property
    def _compilers_minimum_version(self):
        return {
            "gcc": "11",
            "clang": "14",
        }

    @property
    def _is_arm_cortex(self):
        return str(self.settings.arch).startswith("cortex-")

    @property
    def _runtime_select(self):
        if self._is_arm_cortex and self.options.runtime == "builtin":
            return "ARM_CORTEX_GCC"
        elif self._is_arm_cortex and self.options.runtime == "estell":
            return "ARM_CORTEX_ESTELL"
        else:
            return "ARM_CORTEX_GCC"

    def validate(self):
        if self.settings.get_safe("compiler.cppstd"):
            check_min_cppstd(self, self._min_cppstd)

    def layout(self):
        cmake_layout(self)

    def build_requirements(self):
        self.tool_requires("cmake/3.27.1")
        self.tool_requires("libhal-cmake-util/[^4.0.3]")
        self.test_requires("boost-ext-ut/2.1.0")

    def requirements(self):
        self.requires("libhal-util/[^5.0.0]")

    def build(self):
        cmake = CMake(self)
        configure_variables = {"RUNTIME": self._runtime_select}
        cmake.configure(variables=configure_variables)
        cmake.build()

    def package(self):
        package_folder = Path(self.package_folder)
        source_folder = Path(self.source_folder)
        copy(self,
             "LICENSE",
             dst=package_folder / "licenses",
             src=source_folder)
        copy(self,
             "*.h",
             dst=package_folder / "include",
             src=source_folder / "include")
        copy(self,
             "*.hpp",
             dst=package_folder / "include",
             src=source_folder / "include")
        copy(self,
             "*.ld",
             dst=package_folder / "linker_scripts",
             src=source_folder / "linker_scripts")

        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["libhal-exceptions"]
        self.cpp_info.set_property("cmake_target_name", "libhal::exceptions")
        lib_path = Path(self.package_folder) / 'lib' / 'liblibhal-exceptions.a'
        linker_script_path = Path(self.package_folder) / 'linker_scripts'
        gcc_arm_14_2 = linker_script_path / 'arm-none-eabi-gcc-14.2'

        using_wrap = False
        if self.options.runtime == "estell":
            using_wrap = True
            # If the platform matches the linker script, just use that linker
            # script
            self.cpp_info.exelinkflags.extend([
                "-fexceptions",
                f"-L{linker_script_path}",
                f'-Wl,-T{gcc_arm_14_2 / "discard_unwind_c.ld" }',
                f'-Wl,-T{gcc_arm_14_2 / "override_gxx_personality_v0.ld" }',
                "-Wl,--wrap=__cxa_throw",
                "-Wl,--wrap=__cxa_rethrow",
                "-Wl,--wrap=__cxa_end_catch",
                "-Wl,--wrap=__cxa_begin_catch",
                "-Wl,--wrap=__cxa_end_cleanup",
                "-Wl,--wrap=_Unwind_Resume",
            ])

        # Keep this for now, will update this for the runtime select
        if self._is_arm_cortex:
            using_wrap = True
            self.cpp_info.exelinkflags.extend([
                "-Wl,--wrap=__cxa_allocate_exception",
                "-Wl,--wrap=__cxa_free_exception",
                "-Wl,--wrap=__cxa_call_unexpected",
            ])

        if using_wrap:
            self.cpp_info.exelinkflags.extend([
                # Ensure that all symbols are added to the linker's symbol table
                "-Wl,--whole-archive",
                str(lib_path),
                "-Wl,--no-whole-archive",
            ])
