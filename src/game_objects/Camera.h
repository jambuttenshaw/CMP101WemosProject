#pragma once

#include <Geometry.h>

class Camera
{
public:
    Camera();
    Camera(Point initPos);
    ~Camera();

    inline Point GetPosition() { return m_Position; }

    inline void SetPosition(Point pos) { m_Position = pos; }
    inline void Translate(Point translation) { m_Position += translation; }

private:
    Point m_Position;
};