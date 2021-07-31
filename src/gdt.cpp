#include "include/gdt.h"

GlobalDescriptorTable::GlobalDescriptorTable()
: nullSegmentSelector(0,0,0),
unusedSegmentSelector(0,0,0),
codeSegmentSelector(0,64*1024*1024,0x9A),
dataSegmentSelector(0,64*1024*1024,0x92)
{
  std::uint32_t i[2];
  i[1] = (std::uint32_t)this;
  i[0] = sizeof(GlobalDescriptorTable) << 16;

  asm volatile("lgdt (%0)": :"p" (((std::uint8_t *) i)+2));
}

GlobalDescriptorTable::~GlobalDescriptorTable(){

}

std::uint16_t GlobalDescriptorTable::DataSegmentSelector(){
  return (std::uint8_t*)&dataSegmentSelector - (std::uint8_t*)this;
}

std::uint16_t GlobalDescriptorTable::CodeSegmentSelector(){
  return (std::uint8_t*)&codeSegmentSelector - (std::uint8_t*)this;
}

GlobalDescriptorTable::SegmentDescriptor::SegmentDescriptor(std::uint32_t base, std::uint32_t limit, std::uint8_t flags){
  std::uint8_t* target = (std::uint8_t*)this;

  if(limit < 65556){
    target[6] = 0x40;
  }else{
    if((limit & 0xFFF) != 0xFFF)
      limit = (limit >> 12)-1;
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

uint32_t GlobalDescriptorTable::SegmentDescriptor::Base(){
    std::uint8_t* target = (std::uint8_t*)this;
    std::uint32_t result = target[7];
    result = (result << 8) + target[4];
    result = (result << 8) + target[3];
    result = (result << 8) + target[2];

    return result;
}

std::uint32_t GlobalDescriptorTable::SegmentDescriptor::Limit(){
    std::uint8_t* target = (std::uint8_t*)this;
    std::uint32_t result = target[6] & 0xF;
    result = (result << 8) + target[1];
    result = (result << 8) + target[0];

    if((target[6] & 0xC0) == 0xC0)
        result = (result << 12) | 0xFFF;

    return result;
}

std::uint32_t __stack_chk_fail_local(){
    return 0;
}
