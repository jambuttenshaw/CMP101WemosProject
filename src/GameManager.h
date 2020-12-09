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

    void Countdown();

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
    bool m_PassedHalfway = false;
    bool m_DisplayingLastLapTime = false;
    bool m_DisplayingGo = false;

    float m_DurationToDisplayLastLap = 4;
    float m_LapTimeFlashThreshold = 0.3f;

    float m_DurationToDisplayGo = 3;
    float m_GoFlashThreshold = 0.1f;
    int m_GoFlashState = true;

    float m_FlashTimer = 0;
};
