#pragma once

#include "core/Timestep.h"
#include "Camera.h"

#include <Adafruit_SSD1306.h>
#include <Geometry.h>

class Car
{
public:
    // constructors of the car
    // a default constructor + one to specify initial position
    Car();
    Car(Point position);
    // destructor
    ~Car();

    // set the position of the car to a specific point
    inline void SetPosition(Point position) { m_Position = position; }
    // move the position of the car by a vector
    inline void Translate(Point translation) { m_Position += translation; }

    // get the position of the car in world space
    inline Point GetPosition() { return m_Position; }

    // get the magnitude of the cars velocity
    inline float GetSpeed() { return m_Speed; }
    // get the magnitude of the cars velocity on a scale from 0 to 1
    // where 1 is the theoretical top speed of the car
    inline float GetSpeedNormalized() { return m_Speed / m_MaxSpeed; }

    // get the direction that the car is currently pointing in
    inline float GetAngularDisplacement() { return m_AngularDisplacement; }

    // sets whether the car is considered to be on the track or off the track
    inline void SetOnTrack(bool onTrack) { m_OnTrack = onTrack; }

    // the big update function
    void Update(Timestep ts);

    // draw the car onto the screen
    void Draw(Adafruit_SSD1306& display, Camera& camera);
private:
    // init the car
    void Init();

private:

    // DYNAMICS ATTRIBUTES - MESS WITH THESE

    // how fast the car can go
    float m_EngineForce = 75; 

    // how much slower reverse is than forwards
    float m_ReverseCoefficient = 0.5f;

    // how quickly the car gets slowed down by friction
    float m_TrackCoefficient = 1.5f;
    float m_OffTrackCoefficient = 5;

    // how quickly the car is slowed angularly by friction
    float m_AngularDragCoefficient = 5;

    // steering attributes
    float m_MaxWheelAngle = 15 * DEG_TO_RAD; // the wheels of the car can point a maximum of x degrees from the vertical
    float m_MaxTyreFriction = 5; // the biggest friction force that the tyres can provide
                                 // if you attempt to corner faster than this then you will understeer

    // physical attributes of the car (these can be unstable... tread carefully)
    float m_Mass = 1; 
    float m_Radius = 1; // how far the steering wheels are from the center of gravity of the car


    // MOTION OF THE CAR - DO NOT TOUCH
    float m_WheelAngle = 0; // the angle the wheels point at
    float m_TurnRadius = 0; // the radius of the turn the car would make with this wheel angle, without considering velocity
    float m_CentripetalForce = 0; // the centripital force produced by the friction from the tyres
    float m_Torque = 0; // the rotational force produced by the centripetal force
    float m_DragTorque = 0; // the opposing rotational force produced by drag
    float m_MomentOfIntertia = 0; // the moment of inertia of the car; its resistance to being accelerated angularly

    float m_AngularAcceleration = 0; // the angular acceleration of the car
    float m_AngularVelocity = 0; // the angular velocity of the car
    float m_AngularDisplacement = -HALF_PI; // the angular displacement of the car

    Point m_Thrust; // the forward force produced by the engine of the car
    Point m_DragForce; // the opposing force produced by friction
    Point m_UnbalancedForce; // the resultant force acting on the car

    Point m_Acceleration; // the acceleration of the car
    Point m_Velocity; // the velocity of the car
    float m_Speed = 0; // the speed of the car
    float m_MaxSpeed = 0; // the theoretical maximum speed of the car
    Point m_Position; // the position of the car

    Rotation m_Rotation; // the rotation of the car in matrix form

    Point m_InitialPos; // the initial position of the car, where it starts on screen

    bool m_OnTrack = true; // if the car is on track or not

    // Graphics

    // the dimensions of the car
    int carWidth = 6;
    int carLength = 12;
};
