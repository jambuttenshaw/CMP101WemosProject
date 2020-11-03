#pragma once

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
    void SetDirection(Rotation rot);

    inline Point GetPosition() { return m_Position; }
    // inline Rotation GetRotation() { return m_Direction; }
    inline Point GetDirection() { return m_Direction; }

    void Update();
    void Draw(Adafruit_SSD1306& display);

private:
    Point m_Position;
    // unit vector representing the direction the car is facing
    Point m_Direction;

    int m_ViewLineLength = 16;
};
