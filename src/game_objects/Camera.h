#pragma once

#include <Geometry.h>

class Camera
{
public:
    Camera();
    Camera(Point initPos);
    ~Camera();

private:
    Point m_Position;
};