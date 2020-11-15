#pragma once

#include "core/InputAPI.h"

#include <Arduino.h>

#define BUTTON_PIN D3
#define ANALOGUE_PIN A0

class Input
{
public:
    static void Init()
    {
        pinMode(BUTTON_PIN, INPUT_PULLUP);
    }

    // ANALOGUE INPUT
    static int GetAnalogueIn(int pin = ANALOGUE_PIN) { return analogRead(pin); }
    const static int AnalogueMax = 1024;
    const static int AnalogueMin = 0;
    const static int AnalogueMid = (AnalogueMax - AnalogueMin) / 2;
    

    // DIGITAL READING FROM BUTTON
    static bool GetButtonPress() { return !GetDigitalRead(BUTTON_PIN); }

    static bool GetDigitalRead(int pin) { return digitalRead(pin); }

private:
    static InputAPI* s_InputAPI;
};