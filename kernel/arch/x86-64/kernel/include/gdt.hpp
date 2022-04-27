#ifndef GDT_HPP
#define GDT_HPP

#include "gdt_types.hpp"

namespace gdt
{
  void flush_tss();
  task_state_segment_t &tss();
}

#endif
