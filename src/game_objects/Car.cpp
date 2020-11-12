#include "Car.h"

#include "core/Input.h"
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
    m_Force = Point();
    m_Acceleration = Point();
    m_Velocity = Point();
    m_Position = m_InitialPos;
}

void Car::Update(Timestep ts)
{
    /*
    // Get a float in radians from -PI to PI representing how hard the steering has been turned
    m_AngularVelocity = PI * (Input::GetAnalogueIn() - Input::AnalogueMid) / (float)Input::AnalogueMid;
    m_AngularDisplacement += m_AngularVelocity * ts;
    
    // point the car in the direction of the angular displacement
    m_Velocity = Point({cos(m_AngularDisplacement), sin(m_AngularDisplacement), 1});
    
    // calculate the magnitude of the velocity
    bool buttonPress = Input::GetButtonPress();
    m_InputThreshold = Lerp(m_InputThreshold, buttonPress ? 1 : 0, ts * m_Acceleration);

    m_Speed = m_InputThreshold * m_TopSpeed;

    m_Position += m_Velocity * m_Speed * ts;
    */


    m_Thrust = m_EngineForce * Input::GetButtonPress();
    m_DragForce = (m_OnTrack ? m_TrackCoefficient : m_OffTrackCoefficient) * m_Velocity.DotProduct(m_Velocity);

    // ADD ANGULAR ACCELERATION
    m_AngularVelocity = PI * (Input::GetAnalogueIn() - Input::AnalogueMid) / (float)Input::AnalogueMid;
    m_AngularDisplacement += m_AngularVelocity * ts;

    m_Force = Point({cos(m_AngularDisplacement), sin(m_AngularDisplacement), 1}) * (m_EngineForce - m_DragForce);

    m_Acceleration = m_Force / m_Mass;
    m_Velocity += m_Acceleration * ts;
    m_Position += m_Velocity * ts + m_Acceleration * ts * ts * 0.5f;
}

void Car::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    Point screenPos = InverseTransformPoint(m_Position, camera.GetPosition(), camera.GetRotation());
    screenPos = Point({64 + screenPos.X(), 32 - screenPos.Y(), 0});

    display.fillRect(screenPos.X() - carWidth * 0.5f, screenPos.Y() - carLength * 0.5f, carWidth, carLength, INVERSE);
}
