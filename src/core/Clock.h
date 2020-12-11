#pragma once

#include <DS3231.h>

#include <Streaming.h>

/*
The clock uses I2P to interface with the wemos
Therefore connecting the hardware is fairly simple:
    - The SDA pin on the clock should be connected to one of the SDA pins on the wemos
    - The SCL pin on the clock should be connected to one of the SCL pins on the wemos


This is a static interface to the DS3231 module
So that the clock can be accessed from anywhere in the program without having a reference to an instance of the clock
*/

class Clock
{
public:
    // init the clock
    inline static void Init()
    {
        // reset the time elapsed on the clock
        Reset();
    }

    // gets the current real time second
    inline static uint8_t GetSecond() { return s_RTC->getSecond(); }
    // gets the current real time minute
    inline static uint8_t GetMinute() { return s_RTC->getMinute(); }

    // gets the number of seconds elapsed since the clock was last reset
    inline static uint8_t GetElapsedSeconds() 
    { 
        // find the elapsed seconds as the difference between now and when it was reset
        int8_t elapsedSeconds = GetSecond() - s_StartSecond;
        
        // it is possible the difference is 0
        if (elapsedSeconds < 0)
        {
            // in which case we want to add 60 onto the elapsed seconds to roll it back around
            elapsedSeconds += 60;
            // but we need to adjust the minutes in this case, so that the minutes elapsed dont increase
            // before they are due to
            s_MinuteAdjustment = 1;
        }
        else
        {
            // if the elapsed time is positive then the minutes will still display the correct duration
            s_MinuteAdjustment = 0;
        }

        // return the elapsed time as an unsigned integer, since at this point the elapsed time will not be negative
        return (uint8_t)elapsedSeconds;
    }

    // gets the number of seconds elapsed since the clock was last reset
    inline static uint8_t GetElapsedMinutes()
    {
        // find the number of minutes as the difference between now and when it was reset
        // take into account the minute adjustment to keep the elapsed time right if the seconds needed adjusted
        int8_t elapsedMinutes = GetMinute() - s_StartMinute - s_MinuteAdjustment;

        // if the elapsed minutes is less than 0 then we add 60 to roll it back around and make it right
        if (elapsedMinutes < 0)
            elapsedMinutes += 60;

        // case the elapsed minutes to an unsigned int and then return it
        return (uint8_t)elapsedMinutes;
    }

    inline static void Reset()
    {
        // sets the elapsed time on the clock to 0 by setting the start time to the current time
        s_StartSecond = GetSecond();
        s_StartMinute = GetMinute();
    }

private:
    // a pointer to the real time clock object
    static DS3231* s_RTC;

    // the second and minute that the clock was last reset at
    static uint8_t s_StartSecond;
    static uint8_t s_StartMinute;

    // any adjustment that may be required to the elapsed minutes
    static uint8_t s_MinuteAdjustment;
};