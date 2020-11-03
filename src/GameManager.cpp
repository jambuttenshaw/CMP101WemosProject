#include "GameManager.h"

GameManager::GameManager()
{

}

GameManager::~GameManager()
{
    delete m_Display;
    
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

    m_Car = new Car();
    m_Track = new Track();
}

void GameManager::Update()
{
    m_Car->Update();
    m_Track->Update();
}

void GameManager::Draw()
{
    m_Display->clearDisplay();

    m_Track->Draw(*m_Display);
    m_Car->Draw(*m_Display);

    m_Display->display();
}
