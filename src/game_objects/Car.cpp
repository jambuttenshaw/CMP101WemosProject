#include "Car.h"

#include "core/Input.h"
#include "core/MathsUtility.h"

#include <Streaming.h>

Car::Car()
    : m_Position(Point())
{
    Init();
}

Car::Car(Point position, Point direction)
    : m_Position(position)
{
    Init();
}

Car::Car(Point position, Rotation rot)
    : m_Position(position)
{
    Init();
}



Car::~Car()
{

}




void Car::Init()
{
    m_Velocity = Point({0, 1, 0});
    
    m_InitialPos = m_Position;
}

void Car::Update(Timestep ts)
{
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
}

void Car::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    Point screenPos = InverseTransformPoint(m_Position, camera.GetPosition(), camera.GetRotation());
    screenPos = Point({64 + screenPos.X(), 32 - screenPos.Y(), 0});

    display.fillRect(screenPos.X() - carWidth * 0.5f, screenPos.Y() - carLength * 0.5f, carWidth, carLength, BLACK);
}
