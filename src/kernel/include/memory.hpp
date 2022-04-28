#ifndef MEMORY_HPP
#define MEMORY_HPP

#include "stl/types.hpp"

void init_memory_manager();

void *k_malloc(uint64_t bytes);
void k_free(void *block);

template <typename T>
T *k_malloc()
{
  return reinterpret_cast<T *>(k_malloc(sizeof(T)));
}

uint64_t free_memory();
uint64_t used_memory();
uint64_t allocated_memory();

void memory_debug();

#endif
