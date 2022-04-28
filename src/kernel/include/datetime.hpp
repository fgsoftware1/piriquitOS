#ifndef DATETIME_H
#define DATETIME_H

#include "stl/types.hpp"

struct datetime
{
  uint8_t year;
  uint8_t month;
  uint8_t day;
  uint8_t hour;
  uint8_t minutes;
  uint8_t seconds;
  uint16_t precise;
} __attribute__((packed));

#endif
