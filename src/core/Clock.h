#pragma once

#include <DS3231.h>

class Clock
{
public:
    inline static uint8_t GetSecond() { return s_RTC->getSecond(); }
    inline static uint8_t GetMinute() { return s_RTC->getMinute(); }

private:
    // real time clock
    static DS3231* s_RTC;

};