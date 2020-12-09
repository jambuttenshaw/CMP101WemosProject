#include "GameManager.h"

GameManager gameManager;

void setup()   {                
  Serial.begin(115200);

  gameManager.Init();

  delay(2000);

  gameManager.Countdown();
}


void loop() {
  gameManager.Update();

  gameManager.Draw();
}


