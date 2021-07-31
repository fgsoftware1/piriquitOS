#ifndef __GDT_H
#define __GDT_H

#include "types.h"
#include "cstdint.h"

    class GlobalDescriptorTable
    {
      public:
        class SegmentDescriptor
        {
          private:
            std::uint16_t limit_lo;
            std::uint16_t base_lo;
            std::uint8_t base_hi;
            std::uint8_t type;
            std::uint8_t limit_hi;
            std::uint8_t base_vhi;
          public:
            SegmentDescriptor(std::uint32_t base, std::uint32_t limit, std::uint8_t type);
            std::uint32_t Base();
            std::uint32_t Limit();
        } __attribute__((packed));

        private:
          SegmentDescriptor nullSegmentSelector;
          SegmentDescriptor unusedSegmentSelector;
          SegmentDescriptor codeSegmentSelector;
          SegmentDescriptor dataSegmentSelector;

        public:
          GlobalDescriptorTable();
          ~GlobalDescriptorTable();

          std::uint16_t CodeSegmentSelector();
          std::uint16_t DataSegmentSelector();
      };
#endif
