#include "Car.h"

#include "Input.h"

Car::Car()
    : m_Position(Point()), m_Direction(Rotation())
{

}

Car::Car(Point position, Rotation direction)
    : m_Position(position), m_Direction(direction)
{

}

Car::~Car()
{

}

void Car::Update()
{
    // get the raw analogue input
    int rawInput = Input::GetAnalogueIn();

    // convert the analogue input to radians
    float rads = DEG_TO_RAD * ((float)rawInput / 2.8444f + 90);
    // set the rotation
    SetRotation(Rotation().FromEulerAngles(0, 0, rads));
}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    Point dir = GetDirectionVector();
    int endX = posX + (int)(m_ViewLineLength * dir.X());
    int endY = posY + (int)(m_ViewLineLength * dir.Y());

    display.drawLine(posX, posY, endX, endY, 1);
}

Point Car::GetDirectionVector()
{
    Point p({ 1, 0, 0 });
    return m_Direction * p;
}
