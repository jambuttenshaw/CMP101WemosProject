#pragma once

#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "game_objects/Car.h"
#include "game_objects/Track.h"
#include "game_objects/Camera.h"

class GameManager
{
public:
    GameManager();
    ~GameManager();

    void Init();

    void Update();
    void Draw();
private:
    unsigned long m_LastFrameTime = 0UL;

    Adafruit_SSD1306* m_Display;
    Camera* m_Camera;
    Car* m_Car;
    Track* m_Track;

    Rotation m_DefaultCarRotation;
    Point m_CameraOffset;

    // bools to control the state of the game
    bool m_MovedOff = false;
    bool m_PassedHalfway = false;
    bool m_DisplayingLastLapTime = false;

    float m_DurationToDisplayLastLap = 5;
    float m_FlashTimer = 0;
    float m_FlashThreshold = 0.3f;
};
