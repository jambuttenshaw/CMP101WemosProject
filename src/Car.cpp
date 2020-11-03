#include "Car.h"

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

}

void Car::Draw(Adafruit_SSD1306& display)
{
    int posX = (int)m_Position.X();
    int posY = (int)m_Position.Y();

    Point dir = GetDirectionVector();
    int endX = posX + m_ViewLineLength * (int)dir.X();
    int endY = posY + m_ViewLineLength * (int)dir.Y();

    display.drawLine(posX, posY, endX, endY, 1);
}

Point Car::GetDirectionVector()
{
    Point p({ 1, 0, 0 });
    return m_Direction * p;
}
