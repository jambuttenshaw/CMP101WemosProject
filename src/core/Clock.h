#pragma once

#include <DS3231.h>

#include <Streaming.h>

class Clock
{
public:
    inline static void Init()
    {
        Reset();
    }


    inline static uint8_t GetSecond() { return s_RTC->getSecond(); }
    inline static uint8_t GetMinute() { return s_RTC->getMinute(); }

    inline static uint8_t GetElapsedSeconds() 
    { 
        int8_t elapsedSeconds = GetSecond() - s_StartSecond;
        
        if (elapsedSeconds < 0)
        {
            elapsedSeconds += 60;
            s_MinuteAdjustment = 1;
        }
        else
        {
            s_MinuteAdjustment = 0;
        }

        return (uint8_t)elapsedSeconds;
    }

    inline static uint8_t GetElapsedMinutes()
    {
        int8_t elapsedMinutes = GetMinute() - s_StartMinute - s_MinuteAdjustment;

        if (elapsedMinutes < 0)
            elapsedMinutes += 60;

        return (uint8_t)elapsedMinutes;
    }

    inline static void Reset()
    {
        s_StartSecond = GetSecond();
        s_StartMinute = GetMinute();
    }

private:
    // real time clock
    static DS3231* s_RTC;

    static uint8_t s_StartSecond;
    static uint8_t s_StartMinute;

    static uint8_t s_MinuteAdjustment;
};