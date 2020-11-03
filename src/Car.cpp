#include "Car.h"

Car::Car()
    : m_Position(glm::vec2(0)), m_Direction(glm::vec2(0, -1))
{

}

Car::Car(const glm::vec2& position, const glm::vec2& direction)
    : m_Position(position), m_Direction(direction)
{

}

Car::~Car()
{

}

void Car::Update()
{

}

void Car::Draw()
{
    
}
