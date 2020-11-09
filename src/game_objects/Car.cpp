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
    m_Velocity = Point({0, 0, 0});
    m_FacingDirection = Point({0, 1, 0});
    
    m_InitialPos = m_Position;
}

void Car::Update(Timestep ts)
{

}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    int endX = posX + (int)(m_ViewLineLength * m_FacingDirection.X());
    int endY = posY + (int)(m_ViewLineLength * m_FacingDirection.Y());

    display.drawLine(posX, posY, endX, endY, WHITE);
}

void Car::SetDirection(Rotation rot)
{
    
}
