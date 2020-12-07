#include "GameManager.h"

#include "core/Timestep.h"
#include "core/IO.h"

#include "core/Clock.h"

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



    // initialize game objects

    Point initCarPos = Point({0, 0, 0});

    m_CameraOffset = initCarPos;

    m_Camera = new Camera(initCarPos);

    m_Track = new Track(initCarPos);
    m_Car = new Car(initCarPos);


    // we always want a dot between the seconds and minutes
    // which will be the second dot
    IO::SetDotActive(2);
    // we always want the first 3 digits to read "LAP"
    IO::SetPositionsToString(0, "LAP ");

}

void GameManager::Update()
{
    // get delta time
    unsigned long newTime = millis();
    Timestep dt((float)(newTime - m_LastFrameTime) / 1000.0f);
    m_LastFrameTime = newTime;

    IO::SetLEDs(IO::GetButtons());

    // pre-update settings
    // we need the car to know if it is on the track
    bool carOnTrack = m_Track->PointOnTrack(m_Car->GetPosition());
    m_Car->SetOnTrack(carOnTrack);

    // update the game objects
    m_Car->Update(dt);
    m_Track->Update(dt);

    m_Camera->SetPosition(m_CameraOffset - m_Car->GetPosition());
    m_Camera->SetRotation(HALF_PI - m_Car->GetAngularDisplacement());

    
    if (IO::GetButton(IO::BUTTON8))
        Clock::Reset();

    // add minutes onto the 7 segment display
    uint8_t minutes = Clock::GetElapsedMinutes();
    if (minutes < 10)
        IO::SetPositionsToString(5, String(minutes));
    else
        IO::SetPositionsToString(4, String(minutes));

    // add seconds onto the 7 segment display
    uint8_t seconds = Clock::GetElapsedSeconds();
    if (seconds < 10)
        IO::SetPositionsToString(7, String(seconds));
    else
        IO::SetPositionsToString(6, String(seconds));

    IO::SetDisplayToString();
}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(Track::DrawMode::Fill, *m_Display, *m_Camera);
    m_Car->Draw(*m_Display, *m_Camera);

    m_Display->display();
}
