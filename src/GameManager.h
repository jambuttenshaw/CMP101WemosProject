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
    // constructor and destructor
    GameManager();
    ~GameManager();

    // sets up the game
    void Init();

    // begins the countdown
    void Countdown();

    // update is called each frame and makes everything happen
    void Update();
    // draw renders everything onto the OLED screen
    void Draw();
private:
    // the time (since the start of the project) that the last frame began at
    // this is used to calculate the time elapsed for each frame
    // to make the physics of the game framerate independent
    unsigned long m_LastFrameTime = 0UL;

    // a pointer to the display
    Adafruit_SSD1306* m_Display;

    // a pointer to a camera object
    Camera* m_Camera;

    // a pointer to the car
    Car* m_Car;
    // a pointer to the track
    Track* m_Track;

    // the rotation of the car
    Rotation m_DefaultCarRotation;
    // how the camera is offset from the car
    Point m_CameraOffset;

    // bools to control the state of the game

    // passed halfway is used to check that the car actually goes
    // all the way round the track before completing a lap
    // you dont get away with just reversing back over the start line
    bool m_PassedHalfway = false;

    // these bools tell the game manager what should currently be displayed on the 7 segment displays
    bool m_DisplayingLastLapTime = false;
    bool m_DisplayingGo = false;

    // how long to display the last lap time for
    float m_DurationToDisplayLastLap = 4;
    // how quickly the last lap time should flash
    float m_LapTimeFlashThreshold = 0.3f;

    // how long to display go for
    float m_DurationToDisplayGo = 3;
    // how quickly the LEDs should flash when its go time
    float m_GoFlashThreshold = 0.1f;
    // if the LEDs are on or off
    int m_GoFlashState = true;

    // a timer to keep track of when to flash things on and off
    float m_FlashTimer = 0;
};
