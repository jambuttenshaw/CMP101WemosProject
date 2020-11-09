#include "Car.h"

#include "core/Input.h"
#include "core/MathsUtility.h"

#include <Streaming.h>

Car::Car()
    : m_Position(Point()), m_SteeringDirection(Point({0, 0, 0}))
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
    m_Velocity = Point({0, 1, 0});
    
    m_InitialPos = m_Position;
}

void Car::Update(Timestep ts)
{
    // Get a float in radians from -PI to PI representing how hard the steering has been turned
    float rawSteeringIn = PI * (Input::GetAnalogueIn() - Input::AnalogueMid) / (float)Input::AnalogueMid;

    angle += rawSteeringIn * ts;
    
    m_Velocity = Point({cos(angle), sin(angle), 1});

}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    int endX = posX + (int)(m_ViewLineLength * m_Velocity.X());
    int endY = posY + (int)(m_ViewLineLength * m_Velocity.Y());

    display.drawLine(posX, posY, endX, endY, WHITE);
}

void Car::SetDirection(Rotation rot)
{
    
}
