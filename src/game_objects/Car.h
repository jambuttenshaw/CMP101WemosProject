#pragma once

#include "core/Timestep.h"
#include "game_objects/Track.h"

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

class Car
{
public:
    Car(Track* track);
    Car(Track* track, Point position, Point direction);
    Car(Track* track, Point position, Rotation rot);
    ~Car();

    inline void SetPosition(Point position) { m_Position = position; }
    void SetDirection(Rotation rot);

    inline Point GetPosition() { return m_Position; }
    inline Point GetDirection() { return m_Direction; }
    inline Rotation GetRotation() { return Rotation().FromEulerAngles(0, 0, atanf(m_Direction.Y() / m_Direction.X())); }

    void Update(Timestep ts);
    void Draw(Adafruit_SSD1306& display);
private:
    void Init();

private:
    Track* m_Track;

    float m_TopSpeed = 25;
    float m_Acceleration = 5;

    Point m_Position;
    Point m_Velocity;
    float m_InputThreshold = 0.0f; // how much of the speed the input is letting through
    // unit vector representing the direction the car is facing
    Point m_Direction;

    int m_ViewLineLength = 16;
};
