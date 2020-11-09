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

    inline void SetRotation(float angle) { m_RotationAngle = angle; SetMatrix(); }
    inline void SetRotation(Rotation rot) { m_Rotation = rot; }

private:
    inline void SetMatrix() { m_Rotation = Rotation().FromEulerAngles(0, 0, m_RotationAngle); }

private:
    Point m_Position;

    float m_RotationAngle;
    Rotation m_Rotation;
};