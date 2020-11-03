#include "Car.h"

Car::Car()
{

}


Car::~Car()
{

}

void Car::Update()
{

}

void Car::Draw(Adafruit_SSD1306& display)
{
    display.drawLine(0, 0, 63, 32, 1);
}
