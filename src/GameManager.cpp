#include "GameManager.h"

#include "core/Timestep.h"
#include "core/Input.h"

#include <Geometry.h>

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
    delete m_Car;
    delete m_Track;
}

void GameManager::Init()
{
    // set up the display
    m_Display = new Adafruit_SSD1306(128, 64);
    m_Display->begin(SSD1306_SWITCHCAPVCC, 0x3c);

    // display the splash screen
    m_Display->display();

    // initialize
    Input::Init();

    Point initCarPos = Point({64, 60, 0});

    m_Track = new Track(initCarPos);
    m_Car = new Car(initCarPos, Rotation());
}

void GameManager::Update()
{
    // get delta time
    unsigned long newTime = millis();
    Timestep dt((float)(newTime - m_LastFrameTime) / 1000.0f);
    m_LastFrameTime = newTime;

    // update the game objects
    m_Car->Update(dt);
    m_Track->Update(dt);

    /* ------- to be revisited -----------
    // scroll the screen
    Point translation = -m_Car->GetDisplacement();
    m_Car->Translate(translation);
    m_Track->Translate(translation);


    // rotate the screen
    Rotation rot = m_Car->GetInverseRotation();
    // rotating car by the inverse of its rotation will rotate it back to where it started
    m_Car->SetDirection(m_DefaultCarRotation);
    m_Track->SetRotation(rot);
    */
}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(*m_Display);
    m_Car->Draw(*m_Display);

    m_Display->display();
}
