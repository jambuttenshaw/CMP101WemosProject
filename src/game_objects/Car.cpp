#include "Car.h"

#include "core/IO.h"
#include "core/MathsUtility.h"

#include <Streaming.h>

// default constructor places car at 0, 0
Car::Car()
    : m_InitialPos(Point())
{
    Init();
}

// constructor takes in an initial position for the car
Car::Car(Point position)
    : m_InitialPos(position)
{
    Init();
}

// destructor
Car::~Car()
{

}

// set up the car
void Car::Init()
{
    // most properties of the car can be initialized as null vectors
    m_Thrust = Point();
    m_DragForce = Point();
    m_UnbalancedForce = Point();

    m_Acceleration = Point();
    m_Velocity = Point();
    // position initialised as the init pos
    m_Position = m_InitialPos;

    /*
    by newtons first law, max speed when unbalanced force = 0
    therefore:
        engine force = drag force
        engine force = velocity * drag coefficient
        velocity = engine force / drag coefficient
    */
    m_MaxSpeed = m_EngineForce / m_TrackCoefficient;

    // initialise as identity matrix
    m_Rotation = Rotation();

    // I = mr^2
    m_MomentOfIntertia = m_Mass * m_Radius * m_Radius;
}

// simulate the car physics
void Car::Update(Timestep ts)
{
    // magnitude is expensive to compute, so well make sure to only do it once each frame
    m_Speed = m_Velocity.Magnitude();

    // get the engine force
    // will be equal to m_EngineForce if Button1 is held down
    // otherwise 0
    // flag as not reversing
    float engine = m_EngineForce * (int)IO::GetButton(IO::BUTTON1);
    bool reversing = false;

    // if the reverse pedal is held down
    if (IO::GetButton(IO::BUTTON2))
    {
        // engine force is backwards and scaled by reverese coefficient
        engine = -m_EngineForce * m_ReverseCoefficient;
        // flag as reversing
        reversing = true;
    }


    // Calculate the angle that the front wheels are pointing in, between -max wheel angle and +wheel angle
    // if the car is reversing, then the steering will be inverted
    m_WheelAngle = m_MaxWheelAngle * ((float)(IO::GetAnalogueIn()) / (float)(IO::AnalogueMid) - 1) * (reversing ? -1 : 1);

    // calculate the radius of turn this wheel angle would produce at this speed
    m_TurnRadius = 0;
    if (m_WheelAngle != 0) // dont divide by 0 kids
    {
        for (int i = 0; i < ceil(PI / (m_WheelAngle < 0 ? -m_WheelAngle : m_WheelAngle)); i++)
        {
            m_TurnRadius += sin(i * m_WheelAngle);
        }
        m_TurnRadius *= 0.5f; // the actual turn radius is this value scaled by the velocity magnitude (real turn radius = m_TurnRadius * m_Speed)
                              // however we dont do that right now as you shall see...
    }
    
    // calculate the centripetal force
    // F = (mv^2) / r
    // however, since we have not scaled r by the velocity magnitude as we should have:
    // F = mv / r
    if (m_TurnRadius == 0) // again, dont divide by 0 kids
    {
        m_CentripetalForce = 0;
    }
    else
    {
        m_CentripetalForce = m_Mass * m_Speed / m_TurnRadius;
    }

    // if the centripetal force required to make this turn is greater than the maximum amount of friction the tyres can provide
    // then cap the centripetal force at the max friction
    // this is the cause of understeer
    if (m_CentripetalForce > m_MaxTyreFriction)
    {
        m_CentripetalForce = m_MaxTyreFriction;
    }

    // calculate the drag torque
    m_DragTorque = m_AngularDragCoefficient * m_AngularVelocity * m_Radius;

    // calculate the resulatent torque on the car
    m_Torque = m_CentripetalForce * m_Radius - m_DragTorque;
    // calculate angular acceleration
    m_AngularAcceleration = m_MomentOfIntertia * m_Torque;

    // calculate the angular displacement and velocity
    m_AngularDisplacement += m_AngularVelocity * ts + m_AngularAcceleration * 0.5f * ts * ts;
    m_AngularVelocity += m_AngularAcceleration * ts;

    // construct the rotation matrix
    // we want to rotate by m_AngularDisplacement radians counter clockwise about the Z axis
    m_Rotation = Rotation().FromEulerAngles(0, 0, m_AngularDisplacement);

    // Calculate the unbalanced force on the car   
    m_Thrust = m_Rotation * Point({1, 0, 0}) * engine; // thrust acts in the direction that the car is turning
    m_DragForce = m_Velocity * (m_OnTrack ? m_TrackCoefficient : m_OffTrackCoefficient); // model drag as directly proportional to velocity
    m_UnbalancedForce = m_Thrust - m_DragForce; // unbalanced force is the resultant

    // calculate acceleration
    m_Acceleration = m_UnbalancedForce / m_Mass;
    
    // calculate position and velocity
    m_Position += m_Velocity * ts + m_Acceleration * ts * ts * 0.5f;
    m_Velocity += m_Acceleration * ts;
}

void Car::Draw(Adafruit_SSD1306& display, Camera& camera)
{
    // draw the car on the screen

    // transform the centre of the car by the position of the car and the inverse of the cameras transform
    Point screenPos = InverseTransformPoint(m_Position, camera.GetPosition(), camera.GetRotation());
    // transform to screen coordinates
    screenPos = Point({64 + screenPos.X(), 32 - screenPos.Y(), 0});

    // draw the car as a rectangle on screen
    // use the dimensions of the car to get the size of the rectangle
    // draw it as the color INVERSE so it will stand out against the track and the offtrack
    display.fillRect(screenPos.X() - carWidth * 0.5f, screenPos.Y() - carLength * 0.5f, carWidth, carLength, INVERSE);
}
