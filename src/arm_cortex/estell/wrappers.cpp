// Copyright 2024 - 2025 Khalil Estell and the libhal contributors
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

extern "C"
{
  [[gnu::section(".text.relocate.__gnu_unwind_pr_common")]]
  void __wrap___gnu_unwind_pr_common()
  {
  }

  [[gnu::section(".text.relocate.__aeabi_unwind_cpp_pr0")]]
  void __wrap___aeabi_unwind_cpp_pr0()
  {
  }

  [[gnu::section(".text.relocate._sig_func")]]
  void __wrap__sig_func()
  {
  }

  [[gnu::section(".text.relocate.__gxx_personality_v0")]]
  void __wrap___gxx_personality_v0()
  {
  }

  [[gnu::section(".text.relocate.deregister_tm_clones")]]
  void __wrap_deregister_tm_clones()
  {
  }

  [[gnu::section(".text.relocate.sregister_tm_clones")]]
  void __wrap_register_tm_clones()
  {
  }
}  // extern "C"
