#ifndef TIMER_HPP
#define TIMER_HPP

#include "stl/types.hpp"

void install_timer();
void sleep_ms(uint64_t delay);

uint64_t timer_ticks();
uint64_t timer_seconds();

#endif
