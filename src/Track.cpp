#include "Track.h"

Track::Track()
{

}

Track::~Track()
{

}

void Track::Update()
{

}

void Track::Draw(Adafruit_SSD1306& display)
{
    display.drawLine(0, 64, 64, 32, 1);
}
