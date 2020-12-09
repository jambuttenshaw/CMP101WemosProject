#include "GameManager.h"

// create a game manager
GameManager gameManager;

void setup()   {        

  // start up the serial connection
  // use 115200 as the baud rate        
  Serial.begin(115200);

  // initialize the game manager
  gameManager.Init();

  delay(2000);

  // start the countdown for the race to being...
  gameManager.Countdown();
}


void loop() {
  // update the game
  gameManager.Update();

  // draw everything to the OLED screen
  gameManager.Draw();
}


