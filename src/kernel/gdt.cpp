#include "include/gdt.hpp"
#include "include/types.hpp"

GlobalDescriptorTable::GlobalDescriptorTable()
    : nullSegmentSelector(0, 0, 0),
      unusedSegmentSelector(0, 0, 0),
      codeSegmentSelector(0, 64 * 1024 * 1024, 0x9A),
      dataSegmentSelector(0, 64 * 1024 * 1024, 0x92)
{
    tulli i[2];
    i[1] = (tulli)this;
    i[0] = sizeof(GlobalDescriptorTable) << 16;
    asm volatile("lgdt (%0)"
                 :
                 : "p"(((tuc *)i) + 2));
}

GlobalDescriptorTable::~GlobalDescriptorTable()
{
}

tus GlobalDescriptorTable::DataSegmentSelector()
{
    return (tuc *)&dataSegmentSelector - (tuc *)this;
}

tus GlobalDescriptorTable::CodeSegmentSelector()
{
    return (tuc *)&codeSegmentSelector - (tuc *)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(tui base, tui limit, tuc type)
{
    tuc *target = (tuc *)this;

    if (limit <= 65536)
    {
        target[6] = 0x40;
    }
    else
    {
        if ((limit & 0xFFF) != 0xFFF)
            limit = (limit >> 12) - 1;
        else
            limit = limit >> 12;

        target[6] = 0xC0;
    }

    target[0] = limit & 0xFF;
    target[1] = (limit >> 8) & 0xFF;
    target[6] |= (limit >> 16) & 0xF;

    target[2] = base & 0xFF;
    target[3] = (base >> 8) & 0xFF;
    target[4] = (base >> 16) & 0xFF;
    target[7] = (base >> 24) & 0xFF;

    target[5] = type;
}

tui GlobalDescriptorTable::SegmentDescriptor::Base()
{
    tuc *target = (tuc *)this;

    tulli result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];

    return result;
}

tui GlobalDescriptorTable::SegmentDescriptor::Limit()
{
    tuc *target = (tuc *)this;

    tulli result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];

    if ((target[6] & 0xC0) == 0xC0)
        result = (result << 12) | 0xFFF;

    return result;
}
