#pragma once

/*
a small class that is mainly used for debugging purposes
when i needed to output information about the time elapsing
*/

class Timestep
{
public:
    // constructor that takes in a float and stores it
    Timestep(float time = 0.0f)
        : m_Time(time)
    {
    }

    // it can be implicitly converted back to a float
    operator float() const { return m_Time; }

    // get the stored time as seconds
    float GetSeconds() const { return m_Time; }
    // get the stored time as milliseconds
    float GetMilliseconds() const { return m_Time * 1000.0f; }
private:
    // the stored time of this timestep
    float m_Time;
};
