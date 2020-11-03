#include "GameManager.h"

#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define DISPLAY_CENTREX 64
#define DISPLAY_CENTREY 32

GameManager gameManager;

void setup()   {                
  Serial.begin(115200);

  gameManager.Init();

  delay(2000);

}


void loop() {
  gameManager.Update();

  gameManager.Draw();
}


