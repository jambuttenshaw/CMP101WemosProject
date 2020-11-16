#pragma once

#include <Streaming.h>
#include <TM1638.h>

class IOBoardAPI
{
public:
    void Init();

	void SetBrightness(uint8_t brightness);

    void SetDisplayToHexNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToHexNumber(number, dots, leadingZeros); }
    void SetDisplayToDecNumber(unsigned long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToDecNumber(number, dots, leadingZeros); }
    void SetDisplayToSignedDecNumber(signed long number, uint8_t dots, bool leadingZeros = true) { m_Module->setDisplayToSignedDecNumber(number, dots, leadingZeros); }
    void SetDisplayToBinNumber(uint8_t number, uint8_t dots) { m_Module->setDisplayToBinNumber(number, dots); }

    void SetLED(uint8_t pos, bool active) { m_Module->setLED(active ? TM1638_COLOR_RED : TM1638_COLOR_NONE, pos); }
    void SetLEDs(uint8_t led) { m_Module->setLEDs(led); }

    uint8_t GetButtons() { return m_Module->getButtons(); }
	bool GetButton(uint8_t button)
	{
		uint8_t buttonBit = (uint8_t)1 << button;
		return (GetButtons() & buttonBit) != 0;
	}
	
private:
    TM1638* m_Module;

};