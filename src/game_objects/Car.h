#pragma once

#include "core/Timestep.h"
#include "Camera.h"

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

class Car
{
public:
    Car();
    Car(Point position);
    ~Car();

    inline void SetPosition(Point position) { m_Position = position; }
    inline void Translate(Point translation) { m_Position += translation; }

    inline Point GetPosition() { return m_Position; }

    inline float GetAngularDisplacement() { return m_AngularDisplacement; }

    inline void SetOnTrack(bool onTrack) { m_OnTrack = onTrack; }

    void Update(Timestep ts);
    void Draw(Adafruit_SSD1306& display, Camera& camera);
private:
    void Init();

private:
/*
    float m_TopSpeed = 25;
    float m_Acceleration = 8;

    Point m_Position;
    Point m_Velocity;

    float m_Speed = 0;

    float m_AngularDisplacement = -HALF_PI;
    float m_AngularVelocity = 0;

    float m_InputThreshold = 0.0f; // how much of the speed the input is letting through
*/

    float m_Thrust = 0;
    float m_DragForce = 0;

    float m_EngineForce = 25;

    float m_TrackCoefficient = 15;
    float m_OffTrackCoefficient = 20;
    
    float m_AngularAcceleration = 0;
    float m_AngularVelocity = 0;
    float m_AngularDisplacement = -HALF_PI;

    float m_Mass = 1;

    Point m_Force;
    Point m_Acceleration;
    Point m_Velocity;
    Point m_Position;

    Point m_InitialPos;

    bool m_OnTrack = true;

    // Graphics
    int carWidth = 6;
    int carLength = 12;
};
