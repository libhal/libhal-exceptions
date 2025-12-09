#pragma once

#include <cstddef>

#include <new>

namespace ke {
struct exception_allocation_tag
{};
}  // namespace ke

void* operator new(std::size_t p_size,
                   std::align_val_t p_align,
                   ke::exception_allocation_tag);

void operator delete(void* p_ptr,
                     std::size_t p_size,
                     std::align_val_t p_align,
                     ke::exception_allocation_tag);
