#include "GameManager.h"

#include "core/Timestep.h"
#include "core/IO.h"

#include "core/Clock.h"

#include "core/ServoIO.h"

#include <Geometry.h>
#include <string>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
    delete m_Car;
    delete m_Track;
    delete m_Camera;
}

void GameManager::Init()
{
    // set up the display
    m_Display = new Adafruit_SSD1306(128, 64);
    m_Display->begin(SSD1306_SWITCHCAPVCC, 0x3c);

    // display the splash screen
    m_Display->display();

    // initialize
    IO::Init();
    Clock::Init();
    ServoIO::Init();



    // initialize game objects

    Point initCarPos = Point({0, 0, 0});

    m_CameraOffset = initCarPos;

    m_Camera = new Camera(initCarPos);

    m_Track = new Track(initCarPos);
    m_Car = new Car(initCarPos);


}

void GameManager::Countdown()
{
    // display the car and the track
    Draw();

    delay(1000);

    // 3
    IO::SetLEDs(IO::LED1 | IO::LED2);
    IO::SetPositionsToString(0, "3 ");
    IO::SetDisplayToString();

    delay(1000);

    // 2
    IO::SetLEDs(IO::LED1 | IO::LED2 | IO::LED3 | IO::LED4);
    IO::SetPositionsToString(2, "2 ");
    IO::SetDisplayToString();

    delay(1000);

    // 1
    IO::SetLEDs(IO::LED1 | IO::LED2 | IO::LED3 | IO::LED4 | IO::LED5 | IO::LED6);
    IO::SetPositionsToString(4, "1 ");
    IO::SetDisplayToString();

    delay(1000);

    // GO
    IO::SetLEDs(255);
    String text = "3 2 1 GO";
    IO::SetDisplayToString(text.c_str(), 0);
    m_DisplayingGo = true;

    // start game loop

    m_LastFrameTime = millis();
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
    unsigned long newTime = millis();
    Timestep dt((float)(newTime - m_LastFrameTime) / 1000.0f);
    m_LastFrameTime = newTime;

    // IO::SetLEDs(IO::GetButtons());

    // pre-update settings
    // we need the car to know if it is on the track
    bool carOnTrack = m_Track->PointOnTrack(m_Car->GetPosition());
    m_Car->SetOnTrack(carOnTrack);

    // update the game objects
    m_Car->Update(dt);
    m_Track->Update(dt);

    m_Camera->SetPosition(m_CameraOffset - m_Car->GetPosition());
    m_Camera->SetRotation(HALF_PI - m_Car->GetAngularDisplacement());

    if (!m_PassedHalfway)
    {
        m_PassedHalfway = m_Track->AtAngularHalfway(m_Car->GetPosition());
    }

    // Check if the car has crossed the start/finish line
    if (m_Track->CrossingFinishLine(m_Car->GetPosition()))
    {
        // car has just crossed the finish line
    
        // add more checcks to make sure the car has actually gone all the way around the track
        if (m_PassedHalfway)
        {
            Clock::Reset();
            m_DisplayingLastLapTime = true;
            m_PassedHalfway = false;
        }
    }

    if (m_DisplayingLastLapTime)
    {
        m_DisplayingLastLapTime = Clock::GetElapsedSeconds() < m_DurationToDisplayLastLap;

        m_FlashTimer += dt;
        if (m_FlashTimer > m_LapTimeFlashThreshold)
        {
            IO::ToggleActive();
            m_FlashTimer = 0;
        }
    }
    else if (m_DisplayingGo)
    {
        m_DisplayingGo = Clock::GetElapsedSeconds() < m_DurationToDisplayGo;
        if (!m_DisplayingGo) IO::SetLEDs(0);

        m_FlashTimer += dt;
        if (m_FlashTimer > m_GoFlashThreshold)
        {
            if (m_GoFlashState)
            {
                IO::SetLEDs(0);
                m_GoFlashState = false;
            }
            else
            {
                IO::SetLEDs(255);
                m_GoFlashState = true;
            }
        }
    }
    else
    {
        // add minutes onto the 7 segment display
        uint8_t minutes = Clock::GetElapsedMinutes();
        if (minutes < 10)
            IO::SetPositionsToString(4, "0" + String(minutes));
        else
            IO::SetPositionsToString(4, String(minutes));

        // add seconds onto the 7 segment display
        uint8_t seconds = Clock::GetElapsedSeconds();
        if (seconds < 10)
            IO::SetPositionsToString(6, "0" + String(seconds));
        else
            IO::SetPositionsToString(6, String(seconds));
        
        
        IO::SetDisplayToString();
    }

    ServoIO::Write(180 * (1 - m_Car->GetSpeedNormalized()));

}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(Track::DrawMode::Fill, *m_Display, *m_Camera);
    m_Car->Draw(*m_Display, *m_Camera);

    m_Display->display();
}
