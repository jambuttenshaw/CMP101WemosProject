#pragma once

#include <TM1638plus.h>

class IOBoardAPI
{
public:
    void Init();

	void SetBrightness(uint8_t brightness);

	inline uint8_t ReadButtons(void) { return m_Module->readButtons(); }
	
    inline void DisplayText(const char *text) { m_Module->displayText(text); }
	inline void DisplayHex(uint8_t position, uint8_t hex) { m_Module->displayHex(position, hex); }
	inline void DisplayIntNum(unsigned long number, boolean leadingZeros = true) { m_Module->displayIntNum(number, leadingZeros); }
	inline void DisplayDecNumNibble(uint16_t numberUpper, uint16_t numberLower, boolean leadingZeros = true) { m_Module->DisplayDecNumNibble(numberUpper, numberLower, leadingZeros); }

    inline void SetLEDs(uint16_t greenred) { m_Module->setLEDs(greenred); }
	inline void SetLED(uint8_t position, uint8_t value) {m_Module->setLED(position, value); }

private:
    TM1638plus* m_Module;

};
