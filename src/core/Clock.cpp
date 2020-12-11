#include "Clock.h"

// initialize the static members

// define a pointer to a new DS3231 object
DS3231* Clock::s_RTC = new DS3231;

// initialize the start time as 00:00
uint8_t Clock::s_StartSecond = 0;
uint8_t Clock::s_StartMinute = 0;

// by default no minute adjustment is required
uint8_t Clock::s_MinuteAdjustment = 0;
