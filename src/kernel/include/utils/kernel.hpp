#ifndef KERNEL_UTILS_HPP
#define KERNEL_UTILS_HPP

#include "../stl/types.hpp"

uint8_t in_byte(uint16_t _port);
void out_byte(uint16_t _port, uint8_t _data);

uint16_t in_word(uint16_t _port);
void out_word(uint16_t _port, uint16_t _data);

#endif
