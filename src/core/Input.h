#pragma once

#include <Arduino.h>

class Input
{
public:
    static void Init()
    {
        pinMode(D6, INPUT_PULLUP);
    }

    static int GetAnalogueIn(int pin = A0) { return analogRead(pin); }
    
    static bool GetButtonPress() { return !GetDigitalRead(D3); }

    static bool GetDigitalRead(int pin) { return digitalRead(pin); }
};