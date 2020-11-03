#pragma once

#include <Arduino.h>

class Input
{
public:
    static int GetAnalogueIn(int pin = A0) { return analogRead(pin); }
};