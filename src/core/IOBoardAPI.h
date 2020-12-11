#pragma once

#include <Streaming.h>
#include <TM1638.h>

/*
The expansion board should be connected as follows:
STB into D5
CLK into D6
DIO into D7

An interface to the Wemos expansion board
this holds the pointer to the actual TM1638 object
*/
class IOBoardAPI
{
public:
    // set up the board
    void Init()
    {
        // STB = D5
        // CLK = D6
        // DIO = D7
        // creates a new TM1638 with the pins set up as shown
        m_Module = new TM1638(D7, D6, D5);
    }

    // sets the 7 segment display to hex numbers
    void SetDisplayToHexNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToHexNumber(number, dots, leadingZeros); }
    // sets the 7 segment display to decimal numbers
    void SetDisplayToDecNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToDecNumber(number, dots, leadingZeros); }
    // sets he 7 segment display to decimal numbers, but the first display is used to display the sign of the number
    void SetDisplayToSignedDecNumber(signed long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToSignedDecNumber(number, dots, leadingZeros); }
    // sets the 7 segment display to a binary number
    void SetDisplayToBinNumber(uint8_t number, uint8_t dots) { m_Module->setDisplayToBinNumber(number, dots); }
    // sets the 7 segment display to a string
    void SetDisplayToString(const char* string, const word dots, const byte pos) { m_Module->setDisplayToString(string, dots, pos); }

    // set a specific led at a position to on or off
    void SetLED(uint8_t pos, bool active) { m_Module->setLED(active ? TM1638_COLOR_RED : TM1638_COLOR_NONE, pos); }
    // set all of the leds using a byte of flags
    // where each digit in the byte corresponds to a specific LED
    // 0 would turn all LEDs off, 255 would turn them all on
    void SetLEDs(uint8_t led) { m_Module->setLEDs(led); }

    // get the byte of flags representing what buttons are pressed on the expansion board
    uint8_t GetButtons() { return m_Module->getButtons(); }
    // buttons should be specified as byte flags
    // where the set digit in the byte corresponds the button you wish to check
	uint8_t GetButtonAsByte(uint8_t button)
	{
        // gets the byte flag of the buttons pressed, but applies a mask to only check the specified button is active
		uint8_t buttonBit = (uint8_t)1 << button;
		return GetButtons() & buttonBit;
	}
    // returns a bool to see if the specified button is pressed
	bool GetButton(uint8_t button) { return GetButtonAsByte(button) != 0; }
		
	
private:
    // a pointer to the TM1638 module
    TM1638* m_Module;

};
