#include "Car.h"

#include "core/Input.h"

Car::Car()
    : m_Position(Point()), m_Direction(Point({0, 0, 1}))
{

}

Car::Car(Point position, Point direction)
    : m_Position(position), m_Direction(direction)
{

}

Car::Car(Point position, Rotation rot)
    : m_Position(position)
{
    SetDirection(rot);
}

Car::~Car()
{

}

void Car::Update(Timestep ts)
{
    // get the raw analogue input
    int rawInput = Input::GetAnalogueIn();

    // convert the analogue input to radians
    float rads = DEG_TO_RAD * ((float)rawInput / 2.8444f + 90);
    // set the direction
    SetDirection(Rotation().FromEulerAngles(0, 0, rads));


    // CAR MOTION
    
    // update position

    // update velocity

    // update acceleration

}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    int endX = posX + (int)(m_ViewLineLength * m_Direction.X());
    int endY = posY + (int)(m_ViewLineLength * m_Direction.Y());

    display.drawLine(posX, posY, endX, endY, 1);
}

void Car::SetDirection(Rotation rot)
{
    // take the vector that points right
    // and rotate it by the transformation matrix rot
    Point p({ 1, 0, 0 });
    m_Direction = rot * p;
}
