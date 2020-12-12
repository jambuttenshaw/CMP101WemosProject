#include "GameManager.h"

#include "core/Timestep.h"
#include "core/IO.h"

#include "core/Clock.h"

#include "core/ServoIO.h"

#include <Geometry.h>
#include <string>

GameManager::GameManager()
{
    // everything that needs to be done for setup is executed in the init method
}

GameManager::~GameManager()
{
    // delete the objects we are pointing at
    delete m_Car;
    delete m_Track;
    delete m_Camera;
}

void GameManager::Init()
{
    // set up the display
    // the specific version of the library I have takes in the width and height of the display for the constructor
    m_Display = new Adafruit_SSD1306(128, 64);
    // start up the display
    // takes in the voltage from the vcc and the screens i2p address
    m_Display->begin(SSD1306_SWITCHCAPVCC, 0x3c);

    // display the splash screen
    // helpful to know the screens working
    m_Display->display();

    // initialize all of the project subsystems
    IO::Init(); // io to and from the expansion board
    Clock::Init(); // the rtc system
    ServoIO::Init(); // the servo control system



    // initialize game objects

    // define where the car originates
    Point initCarPos = Point({0, 0, 0});

    // set the camera offset
    m_CameraOffset = initCarPos;
    // create the camera object
    m_Camera = new Camera(initCarPos);

    // create the track and car
    m_Track = new Track(initCarPos);
    m_Car = new Car(initCarPos);


}

void GameManager::Countdown()
{
    // does a nice 3 2 1 GO on the 7 segment display to start the project off

    // display the car and the track on the OLED
    Draw();

    // a short delay before the countdown starts
    delay(1000);

    // 3
    // activate the first 2 LEDs
    // place a 3 onto the 7 segment display string and then display that string on the 7 seg
    IO::SetLEDs(IO::LED1 | IO::LED2);
    IO::SetPositionsToString(0, "3 ");
    IO::SetDisplayToString();

    // wait 1 second
    delay(1000);

    // 2
    // similar for 2, except turn on more LEDs and place the 2 next to the 3
    IO::SetLEDs(IO::LED1 | IO::LED2 | IO::LED3 | IO::LED4);
    IO::SetPositionsToString(2, "2 ");
    IO::SetDisplayToString();

    // wait 1 second
    delay(1000);

    // 1
    // this should be fairly self explanatory by this point
    IO::SetLEDs(IO::LED1 | IO::LED2 | IO::LED3 | IO::LED4 | IO::LED5 | IO::LED6);
    IO::SetPositionsToString(4, "1 ");
    IO::SetDisplayToString();

    // wait 1 second
    delay(1000);

    // GO
    // turn on all the LEDs
    IO::SetLEDs(255);
    // place go on the last 2 7 seg displays
    IO::SetPositionsToString(6, "GO");
    IO::SetDisplayToString();
    // flag that we want to display go
    m_DisplayingGo = true;

    // start game loop

    // set the last frame time to the current time
    // since this is when the game loop is starting
    m_LastFrameTime = millis();
    // reset the lap timer
    Clock::Reset();

    // we always want a dot between the seconds and minutes
    // which will be the second dot
    IO::SetDotActive(2);
    // we always want the first 3 digits to read "LAP"
    // the first 3 digits wont get overwritten
    // we dont actually display this string yet since we still want to flash GO
    IO::SetPositionsToString(0, "LAP 0000");
}

void GameManager::Update()
{
    // get delta time
    // new time since project start
    unsigned long newTime = millis();
    // find the difference between the time of start of last frame and time now
    // convert it into seconds from milliseconds
    Timestep dt((float)(newTime - m_LastFrameTime) / 1000.0f);
    // reset last frame time to the time of this frame
    m_LastFrameTime = newTime;

    // pre-update settings
    // we need the car to know if it is on the track
    // we can find that out by giving the track the cars position
    bool carOnTrack = m_Track->PointOnTrack(m_Car->GetPosition());
    m_Car->SetOnTrack(carOnTrack);

    // update the car
    m_Car->Update(dt);

    // we want to position the camera to always keep the car in the centre of the screen

    // set the cameras position relative to the car
    m_Camera->SetPosition(m_CameraOffset - m_Car->GetPosition());
    // set the cameras rotation based off of the cars rotation
    m_Camera->SetRotation(HALF_PI - m_Car->GetAngularDisplacement());

    // check if the car has made it at least halfway round the track
    if (!m_PassedHalfway)
    {
        // the track has a handy function for this
        m_PassedHalfway = m_Track->AtAngularHalfway(m_Car->GetPosition());
    }

    // Check if the car has crossed the start/finish line
    if (m_Track->CrossingFinishLine(m_Car->GetPosition()))
    {
        // car has just crossed the finish line
    
        // add more checcks to make sure the car has actually gone all the way around the track
        // if the car has been confirmed to have at least gone halfway then we will say it has finished the lap
        if (m_PassedHalfway)
        {
            // reset the lap timer
            Clock::Reset();
            // say that we want to display the last lap time
            m_DisplayingLastLapTime = true;
            // reset the pass halfway flag
            m_PassedHalfway = false;
        }
    }


    // -----------------------
    // 7 SEGMENT DISPLAY STUFF
    // -----------------------


    // we want to display the lap time from the last lap
    if (m_DisplayingLastLapTime)
    {
        // update the flag based on how much time has elapsed since the lap reset
        // when the elapsed time reaches the duration then we stop displaying the last lap time
        m_DisplayingLastLapTime = Clock::GetElapsedSeconds() < m_DurationToDisplayLastLap;

        // increase the timer by the time elapsed this frame
        m_FlashTimer += dt;
        // if the timer has exceeded the threshold
        if (m_FlashTimer > m_LapTimeFlashThreshold)
        {
            // toggle whether the 7 seg displays are on or off
            IO::ToggleActive();
            // reset the flash timer
            m_FlashTimer = 0;
        }
    }
    // we want to display GO on the 7 segs and flash the LEDs
    else if (m_DisplayingGo)
    {
        // same deal here, check if the time weve been displaying this for is more than
        // the max duration we should be
        m_DisplayingGo = Clock::GetElapsedSeconds() < m_DurationToDisplayGo;
        // when we stop displaying go we want to turn off the LEDs
        if (!m_DisplayingGo) IO::SetLEDs(0);

        // increase the timer by the time elapsed this frame
        m_FlashTimer += dt;
        // if the timer has exceeded the threshold
        if (m_FlashTimer > m_GoFlashThreshold)
        {
            // if the leds are currently on
            if (m_GoFlashState)
            {
                // turn them off
                IO::SetLEDs(0);
                m_GoFlashState = false;
            }
            else
            {
                // otherwise turn them back on
                IO::SetLEDs(255);
                m_GoFlashState = true;
            }
        }
    }
    else
    {
        // nothing special is happening, we just want to display the lap time

        // add minutes onto the 7 segment display
        // get the number of minutes since the lap start
        uint8_t minutes = Clock::GetElapsedMinutes();
        // we need to make sure that the string form of the minutes is 2 characters long
        // prepend a 0 if necessary
        if (minutes < 10)
            IO::SetPositionsToString(4, "0" + String(minutes));
        else
            IO::SetPositionsToString(4, String(minutes));

        // add seconds onto the 7 segment display
        // same deal here for the seconds, prepend with a 0 if the strings too short
        uint8_t seconds = Clock::GetElapsedSeconds();
        if (seconds < 10)
            IO::SetPositionsToString(6, "0" + String(seconds));
        else
            IO::SetPositionsToString(6, String(seconds));
        
        // send the string to the 7 segment display
        IO::SetDisplayToString();
    }

    // the speedometer
    // get the normalized speed from the car and use it to set the angle of the servo
    // when speed = 0, angle = 180. speed = 1, angle = 0
    // linear interpolate between those values
    ServoIO::Write(180 * (1 - m_Car->GetSpeedNormalized()));

}

void GameManager::Draw()
{
    // drawing everything to the display

    // clear the display of everything from the last frame
    m_Display->clearDisplay();

    // draw the track onto the screen
    // we can choose the draw mode, but use fill cause its the best
    m_Track->Draw(Track::DrawMode::Fill, *m_Display, *m_Camera);
    // draw the car onto the screen
    m_Car->Draw(*m_Display, *m_Camera);

    // and then update the display
    m_Display->display();
}
