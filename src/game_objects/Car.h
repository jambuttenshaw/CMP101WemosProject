#pragma once

#include "core/Timestep.h"
#include "game_objects/Track.h"

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

class Car
{
public:
    Car();
    Car(Point position, Point direction);
    Car(Point position, Rotation rot);
    ~Car();

    inline void SetPosition(Point position) { m_Position = position; }
    inline void Translate(Point translation) { m_Position += translation; }

    void SetDirection(Rotation rot);

    inline Point GetPosition() { return m_Position; }
    inline Point GetDisplacement() { return m_Position - m_InitialPos; }

    inline Point GetDirection() { return m_SteeringDirection; }

    inline Rotation GetRotation() { return Rotation().FromEulerAngles(0, 0, atanf(m_SteeringDirection.Y() / m_SteeringDirection.X())); }
    inline Rotation GetInverseRotation() { return GetRotation().Inverse(); }

    void Update(Timestep ts);
    void Draw(Adafruit_SSD1306& display);
private:
    void Init();

private:
    float m_TopSpeed = 15;
    float m_Acceleration = 8;

    Point m_Position;
    Point m_Velocity;
    Point m_SteeringDirection;
    
    // unit vector representing the direction the car is facing
    Point m_FacingDirection;

    float m_InputThreshold = 0.0f; // how much of the speed the input is letting through

    Point m_InitialPos;

    int m_ViewLineLength = 16;
};
