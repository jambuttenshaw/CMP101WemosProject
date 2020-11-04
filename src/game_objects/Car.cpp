#include "Car.h"

#include "core/Input.h"
#include "core/MathsUtility.h"

#include <Streaming.h>

Car::Car()
    : m_Position(Point()), m_SteeringDirection(Point({0, 0, 1}))
{
    Init();
}

Car::Car(Point position, Point direction)
    : m_Position(position), m_SteeringDirection(direction)
{
    Init();
}

Car::Car(Point position, Rotation rot)
    : m_Position(position)
{
    SetDirection(rot);

    Init();
}

Car::~Car()
{

}

void Car::Init()
{
    // set the velocity and acceleration to 0 vectors
    m_Velocity = Point();
    m_InitialPos = m_Position;
}

void Car::Update(Timestep ts)
{
    // get the raw analogue input
    int rawInput = Input::GetAnalogueIn();

    // convert the analogue input to radians
    float rads = DEG_TO_RAD * ((float)rawInput / 2.8444f + 90);
    // set the direction
    SetDirection(Rotation().FromEulerAngles(0, 0, rads));

    // CAR INPUT
    // get input from the button
    // interpolate between current acceleration and the state of the button
    bool buttonPress = Input::GetButtonPress();
    m_InputThreshold = Lerp(m_InputThreshold, buttonPress ? 1 : 0, ts * m_Acceleration);

    // CAR MOTION
    
    // increment velocity
    m_Velocity += m_SteeringDirection * m_InputThreshold;
    float m = m_Velocity.Magnitude();
    if (m > m_TopSpeed)
        m_Velocity *= (m_TopSpeed / m);

    // move car
    Translate(m_Velocity * ts);
}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    int endX = posX + (int)(m_ViewLineLength * m_SteeringDirection.X());
    int endY = posY + (int)(m_ViewLineLength * m_SteeringDirection.Y());

    display.drawLine(posX, posY, endX, endY, WHITE);
}

void Car::SetDirection(Rotation rot)
{
    // take the vector that points right
    // and rotate it by the transformation matrix rot
    Point p({ 1, 0, 0 });
    m_SteeringDirection = rot * p;
}
