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
from conan.tools.cmake import CMake, CMakeDeps, CMakeToolchain, cmake_layout
from conan.tools.env import VirtualBuildEnv
import os


class demos(ConanFile):
    python_requires = "libhal-bootstrap/[>=4.3.0 <5]"
    python_requires_extend = "libhal-bootstrap.demo"
    settings = "compiler", "build_type", "os", "arch"
    options = {
        "platform": ["ANY"],
        "micromod_board": ["ANY"],
        "runtime": ["ANY"]
    }
    default_options = {
        "platform": "unspecified",
        "micromod_board": "unspecified",
        "runtime": "builtin",
    }

    def layout(self):
        build_path = os.path.join("build",
                                  str(self.options.platform),
                                  str(self.options.runtime))
        if "micromod" == str(self.options.platform):
            build_path = os.path.join(build_path,
                                      str(self.options.micromod_board))

        cmake_layout(self, build_folder=build_path)

    def build_requirements(self):
        self.tool_requires("make/4.4.1")
        self.tool_requires("cmake/3.27.1")
        self.tool_requires("libhal-cmake-util/[^4.3.3]")

    def generate(self):
        virt = VirtualBuildEnv(self)
        virt.generate()
        cmake = CMakeDeps(self)
        cmake.generate()
        tc = CMakeToolchain(self)
        tc.generate()

    def build(self):
        cmake = CMake(self)
        cmake.configure()
        cmake.build()

    def requirements(self):
        bootstrap = self.python_requires["libhal-bootstrap"]
        bootstrap.module.add_demo_requirements(self)
        if self.options.platform != "mac":
            self.requires("libhal-exceptions/1.4.1")
