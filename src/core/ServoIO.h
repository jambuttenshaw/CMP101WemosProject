#pragma once

#include <Servo.h>

class ServoIO
{
public:

    static void Init()
    {
        s_Servo->attach(D3);
    }

    static void Write(int pos)
    {
        s_Servo->write(pos);
    }

private:
    static Servo* s_Servo;
};