#ifndef PAGING_H
#define PAGING_H

#include "stl/types.hpp"

namespace paging
{
  constexpr const int PAGE_SIZE = 4096;

  template <typename T>
  constexpr bool page_aligned(T *addr)
  {
    return !(reinterpret_cast<uintptr_t>(addr) & (paging::PAGE_SIZE - 1));
  }

  void *physical_address(void *virt);
  bool page_present(void *virt);
  bool page_free_or_set(void *virt, void *physical);
  bool identity_map(void *virt);
  bool identity_map(void *virt, size_t pages);
}

#endif
