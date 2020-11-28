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
    void DebugLogKinematics();

private:

    // DYNAMICS ATTRIBUTES - MESS WITH THESE

    // how fast the car can go
    float m_EngineForce = 75; 

    // how quickly the car gets slowed down by friction
    float m_TrackCoefficient = 1.5f;
    float m_OffTrackCoefficient = 5;

    float m_AngularDragCoefficient = 5;

    // steering attributes
    float m_MaxWheelAngle = 15 * DEG_TO_RAD; // the wheels of the car can point a maximum of x degrees from the vertical
    float m_MaxTyreFriction = 5;
    
    // physical attributes of the car
    float m_Mass = 1;
    float m_Radius = 1; // how far the steering wheels are from the center of gravity of the car


    // MOTION OF THE CAR - DO NOT TOUCH
    float m_WheelAngle = 0;
    float m_TurnRadius = 0;
    float m_CentripetalForce = 0;
    float m_Torque = 0;
    float m_DragTorque = 0;
    float m_MomentOfIntertia = 0;


    float m_AngularAcceleration = 0;
    float m_AngularVelocity = 0;
    float m_AngularDisplacement = -HALF_PI;

    Point m_Thrust;
    Point m_DragForce;
    Point m_UnbalancedForce;

    Point m_Acceleration;
    Point m_Velocity;
    Point m_Position;

    Rotation m_Rotation;

    Point m_InitialPos;

    bool m_OnTrack = true;

    // Graphics
    int carWidth = 6;
    int carLength = 12;
};
