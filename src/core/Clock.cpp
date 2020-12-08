#include "Clock.h"

DS3231* Clock::s_RTC = new DS3231;

uint8_t Clock::s_StartSecond = 0;
uint8_t Clock::s_StartMinute = 0;

uint8_t Clock::s_MinuteAdjustment = 0;
