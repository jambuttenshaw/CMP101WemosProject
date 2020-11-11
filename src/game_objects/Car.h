#pragma once

#include "core/Timestep.h"
#include "Camera.h"

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

    inline Point GetPosition() { return m_Position; }
    inline Point GetDisplacement() { return m_Position - m_InitialPos; }

    inline float GetAngularDisplacement() { return m_AngularDisplacement; }

    void Update(Timestep ts);
    void Draw(Adafruit_SSD1306& display, Camera& camera);
private:
    void Init();

private:
    float m_TopSpeed = 25;
    float m_Acceleration = 8;

    Point m_Position;
    Point m_Velocity;

    float m_Speed = 0;

    float m_AngularDisplacement = -HALF_PI;
    float m_AngularVelocity = 0;

    float m_InputThreshold = 0.0f; // how much of the speed the input is letting through

    Point m_InitialPos;

    // Graphics
    int carWidth = 6;
    int carLength = 12;
};
