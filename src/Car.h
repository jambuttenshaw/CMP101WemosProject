#pragma once

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

class Car
{
public:
    Car();
    Car(Point position, Rotation direction);
    ~Car();

    inline void SetPosition(Point position) { m_Position = position; }
    inline void SetRotation(Rotation rot) { m_Direction = rot; }

    inline Point GetPosition() { return m_Position; }
    inline Rotation GetRotation() { return m_Direction; }
    inline Point GetDirection() { return GetDirectionVector(); }

    void Update();
    void Draw(Adafruit_SSD1306& display);

private:
    Point GetDirectionVector();
private:
    Point m_Position;
    // the rotation matrix that would rotate the direction vector (1, 0)
    // to the direction that the car is facing in
    Rotation m_Direction;

    int m_ViewLineLength = 16;
};
