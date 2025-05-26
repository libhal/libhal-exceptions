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
import os

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
                       "CMakeLists.txt", "src/*")
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

    def validate(self):
        if self.settings.get_safe("compiler.cppstd"):
            check_min_cppstd(self, self._min_cppstd)

    def layout(self):
        cmake_layout(self)

    def build_requirements(self):
        self.tool_requires("cmake/3.27.1")
        self.tool_requires("libhal-cmake-util/[^4.0.3]")
        self.test_requires("boost-ext-ut/1.1.9")

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
             dst=os.path.join(self.package_folder, "licenses"),
             src=self.source_folder)
        copy(self,
             "*.h",
             dst=os.path.join(self.package_folder, "include"),
             src=os.path.join(self.source_folder, "include"))
        copy(self,
             "*.hpp",
             dst=os.path.join(self.package_folder, "include"),
             src=os.path.join(self.source_folder, "include"))

        cmake = CMake(self)
        cmake.install()

    def package_info(self):
        self.cpp_info.libs = ["libhal-exceptions"]
        self.cpp_info.set_property("cmake_target_name", "libhal::exceptions")
        lib_path = os.path.join(self.package_folder,
                                'lib', 'liblibhal-exceptions.a')

        if self.options.runtime == "estell":
            self.cpp_info.exelinkflags.extend([
                "-fexceptions",
                "-Wl,--wrap=__cxa_throw",
                "-Wl,--wrap=__cxa_rethrow",
                "-Wl,--wrap=__cxa_end_catch",
                "-Wl,--wrap=__cxa_begin_catch",
                "-Wl,--wrap=__cxa_end_cleanup",
                "-Wl,--wrap=__gnu_unwind_pr_common",
                "-Wl,--wrap=__aeabi_unwind_cpp_pr0",
                "-Wl,--wrap=_sig_func",
                "-Wl,--wrap=__gxx_personality_v0",
                "-Wl,--wrap=deregister_tm_clones",
                "-Wl,--wrap=register_tm_clones",
                # Ensure that all symbols are added to the linker's symbol table
                "-Wl,--whole-archive",
                lib_path,
                "-Wl,--no-whole-archive",
            ])

        # Keep this for now, will update this for the runtime select
        if self._is_arm_cortex:
            self.cpp_info.exelinkflags.extend([
                "-Wl,--wrap=__cxa_allocate_exception",
                "-Wl,--wrap=__cxa_free_exception",
                "-Wl,--wrap=__cxa_call_unexpected",
                # Ensure that all symbols are added to the linker's symbol table
                "-Wl,--whole-archive",
                lib_path,
                "-Wl,--no-whole-archive",
            ])
