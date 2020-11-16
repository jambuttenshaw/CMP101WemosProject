#include "Car.h"

#include "core/IO.h"
#include "core/MathsUtility.h"

#include <Streaming.h>

Car::Car()
    : m_InitialPos(Point())
{
    Init();
}

Car::Car(Point position)
    : m_InitialPos(position)
{
    Init();
}

Car::~Car()
{

}

void Car::Init()
{
    m_Thrust = Point();
    m_DragForce = Point();
    m_UnbalancedForce = Point();

    m_Acceleration = Point();
    m_Velocity = Point();
    m_Position = m_InitialPos;

    m_Rotation = Rotation();

    // I = mr^2
    m_MomentOfIntertia = m_Mass * m_Radius * m_Radius;
}

void Car::Update(Timestep ts)
{
    // magnitude is expensive to compute, so well make sure to only do it once each frame
    float velocityMagnitude = m_Velocity.Magnitude();


    // Calculate the angle that the front wheels are pointing in, between -max wheel angle and +wheel angle
    m_WheelAngle = m_MaxWheelAngle * ((float)(IO::GetAnalogueIn()) / (float)(IO::AnalogueMid) - 1);
    // calculate the radius of turn this wheel angle would produce at this speed
    m_TurnRadius = 0;
    if (m_WheelAngle != 0) // dont divide by 0 kids
    {
        for (int i = 0; i < ceil(PI / (m_WheelAngle < 0 ? -m_WheelAngle : m_WheelAngle)); i++)
        {
            m_TurnRadius += sin(i * m_WheelAngle);
        }
        m_TurnRadius *= 0.5f; // the actual turn radius is this value scaled by the velocity magnitude
                              // however we dont do that right now as you shall see...
    }
    
    // calculate the centripetal force
    // F = (mv^2) / r
    // however, since we have not scaled r by the velocity magnitude as we should have:
    // F = mv / r
    if (m_TurnRadius == 0)
    {
        m_CentripetalForce = 0;
    }
    else
    {
        m_CentripetalForce = m_Mass * velocityMagnitude / m_TurnRadius;
    }

    if (m_CentripetalForce > m_MaxTyreFriction)
    {
        m_CentripetalForce = m_MaxTyreFriction;
    }

    m_DragTorque = m_AngularDragCoefficient * m_AngularVelocity * m_Radius;
    m_Torque = m_CentripetalForce * m_Radius - m_DragTorque;
    m_AngularAcceleration = m_MomentOfIntertia * m_Torque;

    m_AngularDisplacement += m_AngularVelocity * ts + m_AngularAcceleration * 0.5f * ts * ts;
    m_AngularVelocity += m_AngularAcceleration * ts;

    m_Rotation = Rotation().FromEulerAngles(0, 0, m_AngularDisplacement);

    // Calculate the unbalanced force on the car
    m_Thrust = m_Rotation * Point({1, 0, 0}) * m_EngineForce * (int)IO::GetButton(IO::BUTTON5); // thrust acts in the direction that the car is turning
    m_DragForce = m_Velocity * (m_OnTrack ? m_TrackCoefficient : m_OffTrackCoefficient); // model drag as directly proportional to velocity
    m_UnbalancedForce = m_Thrust - m_DragForce;

    m_Acceleration = m_UnbalancedForce / m_Mass;
    
    m_Position += m_Velocity * ts + m_Acceleration * ts * ts * 0.5f;
    m_Velocity += m_Acceleration * ts;
}

void Car::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    Point screenPos = InverseTransformPoint(m_Position, camera.GetPosition(), camera.GetRotation());
    screenPos = Point({64 + screenPos.X(), 32 - screenPos.Y(), 0});

    display.fillRect(screenPos.X() - carWidth * 0.5f, screenPos.Y() - carLength * 0.5f, carWidth, carLength, INVERSE);
}
