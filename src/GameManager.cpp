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

    m_Track = new Track();
    m_Car = new Car(m_Track, Point({64, 32, 0}), Rotation().FromEulerAngles(0, 0, -DEG_TO_RAD * 90));
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
}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(*m_Display);
    m_Car->Draw(*m_Display);

    m_Display->display();
}
