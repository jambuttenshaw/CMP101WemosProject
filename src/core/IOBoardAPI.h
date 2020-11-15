#pragma once

#include <TM1638plus.h>

class IOBoardAPI
{
public:
    void Init();

	void SetBrightness(uint8_t brightness);

	uint8_t ReadButtons(void);
	
    void DisplayText(const char *text);
	void DisplayHex(uint8_t position, uint8_t hex);
	void DisplayIntNum(unsigned long number, boolean leadingZeros = true);
	void DisplayDecNumNibble(uint16_t numberUpper, uint16_t numberLower, boolean leadingZeros = true);

    void SetLEDs(uint16_t greenred);
	void SetLED(uint8_t position, uint8_t value);

private:
    TM1638plus* m_Module;

};
