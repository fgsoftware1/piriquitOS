#ifndef GDT_H
#define GDT_H

#include "types.h";

class GlobalDescriptorTable
{
  public:
    class SegmentDescriptor{
      private:
        uint16_t limit_lo;
        uint16_t base_lo;
        uint8_t base_hi;
        uint8_t type;
        uint8_t flags_limit_hi;
        uint8_t base_vhi;

      public:
        SegmentSelector(uint32_t base, uint32_t limit, uint8_t type);
        uint32_t base();
        uint32_t limit();
    };

    SegmentDescriptor nullSegmentSelector;
    SegmentDescriptor unusedSegmentSelector;
    SegmentDescriptor codeSegmentSelector;
    SegmentDescriptor dataSegmentSelector;

    public:
      GlobalDescriptorTable();
      ~GlobalDescriptorTable();

      uint16_t codeSegmentSelector();
      uint16_t dataSegmentSelector();
};
#endif
