#pragma once

#include <Servo.h>

/*
Servo motor should be attached to pin D3 of the Wemos



ServoIO is simply a static interface to the servo motor,
which serves the main purpose of taking ownership over the servo motor object

By doing this I can access the servo motor from anywhere else in the program
without worrying about having an instance of the servo
since I can interface with it using these static methods
*/
class ServoIO
{
public:

    // set up the servo
    static void Init()
    {
        // attatch the servo object to the pin D3
        s_Servo->attach(D3);
        // move the servo to 180 degrees by default
        Write(180);
    }

    // set the servo to an angle between 0 and 180
    static void Write(int pos)
    {
        s_Servo->write(pos);
    }

private:
    static Servo* s_Servo;
};