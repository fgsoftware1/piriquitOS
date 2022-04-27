#ifndef CODE_16
#include "stl/types.hpp"
#endif

#ifndef E820_HPP
#define E820_HPP

namespace e820
{
  constexpr const uint32_t MAX_E820_ENTRIES = 20;

  struct bios_e820_entry
  {
    uint32_t base_low;
    uint32_t base_high;
    uint32_t length_low;
    uint32_t length_high;
    uint16_t type;
    uint16_t acpi;
  } __attribute__((packed));

  extern int16_t bios_e820_entry_count;
  extern bios_e820_entry bios_e820_entries[MAX_E820_ENTRIES];

  struct mmapentry
  {
    uint64_t base;
    uint64_t size;
    uint64_t type;
  };

  void finalize_memory_detection();

  bool mmap_failed();
  uint64_t mmap_entry_count();
  const mmapentry &mmap_entry(uint64_t i);
  const char *str_e820_type(uint64_t type);

  size_t available_memory();
}

#endif
