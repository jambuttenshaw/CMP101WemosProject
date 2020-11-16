#pragma once

#include "core/IOBoardAPI.h"

#include <Arduino.h>

#define BUTTON_PIN D3
#define ANALOGUE_PIN A0

class IO
{
public:
    inline static void Init()
    {
        pinMode(BUTTON_PIN, INPUT_PULLUP);

        // initialize the expansion board
        s_IOBoard->Init();
    }

    // ANALOGUE INPUT
    inline static int GetAnalogueIn(int pin = ANALOGUE_PIN) { return analogRead(pin); }
    const static int AnalogueMax = 1024;
    const static int AnalogueMin = 0;
    const static int AnalogueMid = (AnalogueMax - AnalogueMin) / 2;
    

    // DIGITAL READING FROM BUTTON
    inline static bool GetButtonPress() { return !GetDigitalRead(BUTTON_PIN); }

    inline static bool GetDigitalRead(int pin) { return digitalRead(pin); }


    // EXPANSION BOARD IO
    // (essentially a wrapper to the TM1638plus functionality, but make it static)
    inline static void SetLEDs(uint16_t values) { s_IOBoard->SetLEDs(values); }

private:
    static IOBoardAPI* s_IOBoard;
};