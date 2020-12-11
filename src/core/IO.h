#pragma once

#include "core/IOBoardAPI.h"

#include <Arduino.h>

// define the analogue pin
#define ANALOGUE_PIN A0

/*
A static interface to interact with the IO board

This lets the features of the io board be accessed from anywhere within the program,
making it a more useful module for different projects
*/
class IO
{
public:
    inline static void Init()
    {
        // initialize the expansion board
        s_IOBoard->Init();

        // fill the string with spaces
        // so that nothing would be shown on the 7 segment by default
        for (int i = 0; i < 8; i++)
        {
            s_7SegString[i] = 32;
        }
    }

    // ANALOGUE INPUT
    // gets the raw input from the analogue pin
    inline static int GetAnalogueIn(int pin = ANALOGUE_PIN) { return analogRead(pin); }
    // normalizes the input from the analogue pin
    inline static float GetAnalogueInNormalized(int pin = ANALOGUE_PIN) { return (float)analogRead(pin) / (float)AnalogueMax; }
    // the max and min are predetermined by the hardware so they can be hard coded into the program
    const static int AnalogueMax = 1024;
    const static int AnalogueMin = 0;
    // we also want to use the midpoint value of the analogue stick sometimes
    const static int AnalogueMid = (AnalogueMax - AnalogueMin) / 2;

    // EXPANSION BOARD IO
    // (essentially a wrapper to the TM1638 functionality, but make it static and add a little input formatting)
    // set the LEDs as a byte of flags where each set bit will activate its corresponding LED
    inline static void SetLEDs(uint8_t values) { s_IOBoard->SetLEDs(values); }
    // set a specific LED to active or inactive
    // this function expects the same byte flag system, where the set bit corresponds to the desired LED
    // thus why we take the base-2 log of the input to convert to an LED index
    inline static void SetLED(uint8_t pos, bool active) { s_IOBoard->SetLED(log2(pos), active); }

    // get a true/false value representing whether the specified button is currently pressed
    inline static bool GetButton(uint8_t button) { return s_IOBoard->GetButton(button); }
    // gets the specified buttons state but as a byte flag, where the specified button's bit will either be set or not
    inline static uint8_t GetButtonAsByte(uint8_t button) { return s_IOBoard->GetButtonAsByte(button); }
    // gets the state of every button put into a byte of flags
    inline static uint8_t GetButtons() { return s_IOBoard->GetButtons(); }

    // functions for setting the 7 segment display to different bases of numbers
    // the dots parameter is a byte of flags to tell the display if you want the decimal dot activated on any of the displays
    // leading 0's determines whether you want 0's to be preprended in the empty space in front of the number
    inline static void SetDisplayToHexNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { s_IOBoard->SetDisplayToHexNumber(number, dots, leadingZeros); }
    inline static void SetDisplayToDecNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { s_IOBoard->SetDisplayToDecNumber(number, dots, leadingZeros); }
    inline static void SetDisplayToSignedDecNumber(signed long number, uint8_t dots, bool leadingZeros = true) { s_IOBoard->SetDisplayToSignedDecNumber(number, dots, leadingZeros); }
    inline static void SetDisplayToBinNumber(uint8_t number, uint8_t dots) { s_IOBoard->SetDisplayToBinNumber(number, dots); }

    // the system for displaying strings on the 7 segment display
    // this class stores an array of 8 characters, which is used as a buffer to store the data that
    // will be displayed on the 7 segment display once "SetDisplayToString" is called

    // sets a specific position in the buffer to a single character
    inline static void SetPositionToCharacter(uint8_t pos, char character) { s_7SegString[pos] = character; }
    // sets the buffer from a starting point to a string of characters
    inline static void SetPositionsToString(uint8_t startPos, String characters)
    {
        // get the length of the string
        int numChars = characters.length();
        // use the min function to avoid passing out of bounds of the display buffer
        for (int i = startPos; i < min(8, startPos + numChars); i++)
        {
            // assign the character into the buffer
            s_7SegString[i] = characters[i - startPos];
        }
    }

    // this is used for settings the dots to go along with the string
    // we also have a similar buffer for the dots, but this can simply be stored as a byte with each bit being
    // a flag for what dot is active

    // turns on a specific dot at the specified position
    inline static void SetDotActive(uint8_t pos) { s_7SegDots |= 1 << pos; }
    // turns off a specific dot at the specified position
    inline static void SetDotInactive(uint8_t pos) { s_7SegDots &= ~(1 << pos); }
    // sets the dots to a byte of flags
    inline static void SetDots(uint16_t dots) { s_7SegDots = dots; }

    // puts the stored string and dots buffers onto the 7 segment display
    inline static void SetDisplayToString() { s_IOBoard->SetDisplayToString(s_7SegString, s_7SegDots, 0); }
    // this overload is for if you want to display a string on the display without overriding whatever data is stored in the string buffer
    inline static void SetDisplayToString(const char* s, word d) { s_IOBoard->SetDisplayToString(s, d, 0); }

    // gets the string that is stored in the buffer
    // with the option to specify where to start in the buffer and how many characters to get
    inline static String GetDisplayString(uint8_t startChar = 0, uint8_t numChars = 8)
    {
        // start with an empty string
        String displayString = "";
        // iterate over the desired characters,
        // using the min to make sure we dont pass out of bounds of the buffer
        for (int i = startChar; i < min(8, startChar + numChars); i++)
        {
            // add the character onto the string
            displayString += s_7SegString[i];
        }
        // return the string
        return displayString;
    }

    // displays the 7 segments displays as empty
    inline static void Deactivate()
    { 
        String empty = "        ";
        SetDisplayToString(empty.c_str(), 0);
        s_Active = false;
    }
    // restores the previous data back onto the 7 segment displays
    inline static void Activate()
    {
        SetDisplayToString();
        s_Active = true;
    }
    // toggles whether the display is active or inactive
    inline static void ToggleActive() { s_Active ? Deactivate() : Activate(); }

public:
    // definitions specific to the IO module

    // this can be more readable sometimes when reading through the code
    static const bool ON = true;
    static const bool OFF = false;

    // byte flags for each LED
    // these should be passed into the functions when specifying which led you want to modify
    // and they can be OR-ed together to affect multiple LEDs
    static const uint8_t LED1 = 1;
    static const uint8_t LED2 = 2;
    static const uint8_t LED3 = 4;
    static const uint8_t LED4 = 8;
    static const uint8_t LED5 = 16;
    static const uint8_t LED6 = 32;
    static const uint8_t LED7 = 64;
    static const uint8_t LED8 = 128;

    // again designed to be more readable than having random integers lying in the source code
    static const uint8_t BUTTON1 = 0;
    static const uint8_t BUTTON2 = 1;
    static const uint8_t BUTTON3 = 2;
    static const uint8_t BUTTON4 = 3;
    static const uint8_t BUTTON5 = 4;
    static const uint8_t BUTTON6 = 5;
    static const uint8_t BUTTON7 = 6;
    static const uint8_t BUTTON8 = 7;


private:
    // a static pointer to the expansion board api
    static IOBoardAPI* s_IOBoard;

    // the buffers for storing data to be displayed onto the 7 segment display
    static char s_7SegString[];
    static uint16_t s_7SegDots;

    // a static bool to track if the display is active or not
    static bool s_Active;
};