#pragma once

#include <Streaming.h>
#include <TM1638.h>

class IOBoardAPI
{
public:
    void Init();

	void SetBrightness(uint8_t brightness);
	
    inline void SetLEDs(uint16_t greenred) { Serial << "Calling setLEDS" << endl; m_Module->setLEDs(greenred); }
	inline void SetLED(uint8_t position, uint8_t value) {m_Module->setLED(position, value); }
	
private:
    TM1638* m_Module;

};
