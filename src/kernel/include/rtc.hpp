#ifndef RTC_H
#define RTC_H

#include "stl/types.hpp"

namespace rtc
{
  struct data
  {
    uint8_t second;
    uint8_t minute;
    uint8_t hour;
    uint8_t day;
    uint8_t month;
    uint16_t year;
  };

  data all_data();
}

#endif
