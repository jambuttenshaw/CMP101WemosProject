#pragma once

#include <glm/glm.hpp>

class Car
{
public:
    Car();
    Car(const glm::vec2& position, const glm::vec2& direction);
    ~Car();

    inline const glm::vec2& GetPosition() const { return m_Position; }
    inline const glm::vec2& GetDirection() const { return m_Direction; }

private:
    glm::vec2 m_Position;
    glm::vec2 m_Direction;
};
