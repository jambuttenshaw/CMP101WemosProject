#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "Car.h"
#include "Track.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Init();

    void Update();
    void Draw();
private:
    Adafruit_SSD1306* m_Display;

    Car* m_Car;
    Track* m_Track;
};
