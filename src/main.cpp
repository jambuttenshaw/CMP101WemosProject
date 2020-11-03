#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#include "GameManager.h"

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define DISPLAY_CENTREX 64
#define DISPLAY_CENTREY 32

GameManager gameManager;

void setup()   {                
  Serial.begin(115200);

}


void loop() {
  gameManager.Update();

  gameManager.Draw();
}


