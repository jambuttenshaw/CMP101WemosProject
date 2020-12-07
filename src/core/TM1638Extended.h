#include <TM1638.h>

// I needed to extend the functionality of the TM1638 library for my own purposes
// such as displaying a character at a specific position on the 7 segment display

// to get access to the protected members of TM1638 I had to create a class that inherits from it

class TM1638Extended : public TM1638
{
public:
    TM1638Extended(byte dataPin, byte clockPin, byte strobePin, boolean activateDisplay = true, byte intensity = 7)
            : TM1638(dataPin, clockPin, strobePin, activateDisplay, intensity)
        {}

    void displayDecNumberAt(unsigned long number, byte dots, byte startingPos, boolean leadingZeros, const byte numberFont[])
    {
        setDisplayToDecNumberAt(number, dots, startingPos, leadingZeros, numberFont);
    }

};
