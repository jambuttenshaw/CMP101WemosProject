#pragma once

#include <Adafruit_SSD1306.h>

class Car
{
public:
    Car();
    ~Car();

    void Update();
    void Draw(Adafruit_SSD1306& display);

private:

};
