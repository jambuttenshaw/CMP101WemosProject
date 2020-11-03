#pragma once

#include <Adafruit_SSD1306.h>

class Track
{
public:
    Track();
    ~Track();

    void Update();
    void Draw(Adafruit_SSD1306& display);

private:

};
