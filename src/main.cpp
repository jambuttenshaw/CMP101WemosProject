#include "GameManager.h"

GameManager gameManager;

void setup()   {                
  Serial.begin(115200);

  gameManager.Init();

  delay(2000);

  // do this right before the game loop starts
  gameManager.SetClock();
}


void loop() {
  gameManager.Update();

  gameManager.Draw();
}


