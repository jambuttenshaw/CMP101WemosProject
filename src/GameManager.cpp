#include "GameManager.h"

#include "core/Timestep.h"

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

    m_Car = new Car(Point({96, 32, 0}), Rotation().FromEulerAngles(0, 0, -DEG_TO_RAD * 90));
    m_Track = new Track();
}

void GameManager::Update()
{
    // get delta time
    unsigned long newTime = millis();
    Timestep dt((float)(newTime - m_TotalTime) / 1000.0f);
    m_TotalTime += newTime;

    // update the game objects
    m_Car->Update(dt);
    m_Track->Update();
}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(*m_Display);
    m_Car->Draw(*m_Display);

    m_Display->display();
}
