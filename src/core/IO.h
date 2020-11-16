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
    // (essentially a wrapper to the TM1638 functionality, but make it static)
    inline static void SetLEDs(uint8_t values) { s_IOBoard->SetLEDs(values); }
    inline static void SetLED(uint8_t pos, bool active) { s_IOBoard->SetLED(log2(pos), active); }

    inline static bool GetButton(uint8_t button) { return s_IOBoard->GetButton(button); }
    inline static uint8_t GetButtons() { return s_IOBoard->GetButtons(); }

public:
    // definitions specific to the IO module
    static const bool ON = true;
    static const bool OFF = false;

    static const uint8_t LED1 = 1;
    static const uint8_t LED2 = 2;
    static const uint8_t LED3 = 4;
    static const uint8_t LED4 = 8;
    static const uint8_t LED5 = 16;
    static const uint8_t LED6 = 32;
    static const uint8_t LED7 = 64;
    static const uint8_t LED8 = 128;

    static const uint8_t BUTTON1 = 0;
    static const uint8_t BUTTON2 = 1;
    static const uint8_t BUTTON3 = 2;
    static const uint8_t BUTTON4 = 3;
    static const uint8_t BUTTON5 = 4;
    static const uint8_t BUTTON6 = 5;
    static const uint8_t BUTTON7 = 6;
    static const uint8_t BUTTON8 = 7;


private:
    static IOBoardAPI* s_IOBoard;
};