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
    float rawSteeringIn = (Input::GetAnalogueIn() - Input::AnalogueMid) / (float)Input::AnalogueMid;
    float steeringAngle = PI * rawSteeringIn;

    m_SteeringAngle += rawSteeringIn * ts;
    
    m_Velocity = Point({cos(m_SteeringAngle), sin(m_SteeringAngle), 1});

}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    int endX = posX + (int)(m_ViewLineLength * m_Velocity.X());
    int endY = posY + (int)(m_ViewLineLength * m_Velocity.Y());

    display.drawLine(posX, posY, endX, endY, WHITE);
}
