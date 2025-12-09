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
from conan.errors import ConanException
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
        if self.options.runtime == "builtin":
            if self.settings.compiler == "gcc":
                return "ARM_CORTEX_GCC"
            if self.settings.compiler == "clang":
                return "ARM_CORTEX_LLVM"
        elif self.options.runtime == "estell":
            return "ARM_CORTEX_ESTELL"
        raise ConanException(
            f"Invalid runtime ({self.options.runtime}) & compiler ({self.settings.compiler}) selected")

    def validate(self):
        if self.settings.get_safe("compiler.cppstd"):
            check_min_cppstd(self, self._min_cppstd)

    def layout(self):
        cmake_layout(self)

    def build_requirements(self):
        self.tool_requires("cmake/[>=3.38.0 <5.0.0]")
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
        copy(self,
             "LICENSE",
             dst=Path(self.package_folder) / "licenses",
             src=self.source_folder)
        copy(self,
             "*.h",
             dst=Path(self.package_folder) / "include",
             src=Path(self.source_folder) / "include")
        copy(self,
             "*.hpp",
             dst=Path(self.package_folder) / "include",
             src=Path(self.source_folder) / "include")
        copy(self,
             "*.ld",
             dst=Path(self.package_folder) / "linker_scripts",
             src=Path(self.source_folder) / "linker_scripts")

        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["hal-exceptions"]
        self.cpp_info.set_property("cmake_target_name", "libhal::exceptions")
        using_wrap = False
        self.cpp_info.defines = []

        if self.options.runtime == "estell":
            using_wrap = True
            # If the platform matches the linker script, just use that linker
            # script
            self.cpp_info.exelinkflags.extend([
                "-fexceptions",
                "-L" + str(Path(self.package_folder) / "linker_scripts"),
                # '-Wl,-Tarm-none-eabi-gcc-14.2_discard.ld',
                "-Wl,--wrap=__cxa_throw",
                "-Wl,--wrap=__cxa_rethrow",
                "-Wl,--wrap=__cxa_end_catch",
                "-Wl,--wrap=__cxa_begin_catch",
                "-Wl,--wrap=__cxa_end_cleanup",
                "-Wl,--wrap=_Unwind_Resume",
            ])
            self.cpp_info.defines.append("LIBHAL_ESTELL_EXCEPTIONS")

        if self.settings.compiler == "clang":
            using_wrap = True
            # If the platform matches the linker script, just use that linker
            # script
            self.cpp_info.exelinkflags.extend([
                "-fexceptions",
                "-Wl,--wrap=__cxa_terminate_handler",
            ])

        # Keep this for now, will update this for the runtime select
        if self._is_arm_cortex and self.settings.compiler == "gcc":
            using_wrap = True
            self.cpp_info.exelinkflags.extend([
                "-Wl,--wrap=__cxa_allocate_exception",
                "-Wl,--wrap=__cxa_free_exception",
                "-Wl,--wrap=__cxa_call_unexpected",
            ])

        if using_wrap:
            package_folder = Path(self.package_folder)
            lib_path = package_folder / 'lib' / 'libhal-exceptions.a'
            self.cpp_info.exelinkflags.extend([
                # Ensure that all symbols are added to the linker's symbol table
                "-Wl,--whole-archive",
                str(lib_path),
                "-Wl,--no-whole-archive",
            ])
