#pragma once

#include <Geometry.h>

/*
What is a camera?

Maybe naming it a camera is an unfortunate convention, as it connotates caputing a picture.
But in a game, cameras rarely have anything to do with capturing a picture.

But really, a camera is more like an eye into the game world. It changes only the relative position,
rotation and size of objects in the game world. In a game as simple as this we only need to use the
attributes of the camera when rendering objects onto the screen to make sure theyre positioned as
the player is expecting to percieve them
*/

class Camera
{
public:
    // default constructor and constructor to take init pos
    Camera() : m_Position(Point()) {}
    Camera(Point initPos) : m_Position(initPos) {}
    // destructor
    ~Camera() {}

    // get the position of the camera
    inline Point GetPosition() { return m_Position; }

    // set the position of the camera to a specific position
    inline void SetPosition(Point pos) { m_Position = pos; }
    // move the camera by a vector
    inline void Translate(Point translation) { m_Position += translation; }

    // set the rotation of the camera as an euler angle
    inline void SetRotation(float angle) { m_RotationAngle = angle; SetMatrix(); }
    // set the rotation of the camera as a rotation matrix
    inline void SetRotation(Rotation rot) { m_Rotation = rot; }

    // get the rotation matrix of the camera
    inline Rotation GetRotation() { return m_Rotation; }

private:
    // updates the matrix of the camera to use the stored angle
    inline void SetMatrix() { m_Rotation = Rotation().FromEulerAngles(0, 0, m_RotationAngle); }

private:
    // the position of the camera
    Point m_Position;

    // the angle the camera is pointed at
    float m_RotationAngle;
    // the rotation matrix of the camera
    Rotation m_Rotation;
};