#include "GameManager.h"


/*
Wemos Racing Game
For CMP101 module assessment
By Jamie Buttenshaw
1900658

-----------------------------
How the hardware is connected
-----------------------------

OLED display:
  SCL pin on OLED connected to D1/SCL pin on Wemos
  SDA pin on OLED connected to D2/SDA pin on Wemos

Expansion board:
  Strobe (STB) pin on Expansion board connected to D5 on Wemos
  Clock (CLK) pin on Expansion board connected to D6 on Wemos
  Data IO (DIO) pin on Expansion board connected to D7 on Wemos

Potentiometer:
  The ouput of the potentiometer is connected to pin A0 on the Wemos
  With the pins on the potentiometer facing downwards,
  the leftmost pin is connected to the +ve and the rightmost pin connected to the -ve

Real Time Clock:
  SCL pin on RTC connected to SCL pin on Wemos
  SDA pin on RTC connected to SDA pin on Wemos


Servo motor:
  The input pin of the servo is connected to D3 on the Wemos


--------------
Libraries Used
--------------

platformio/Streaming
  - For making Serial IO neater and easier

adafruit/Adafruit_SSD1306
  - For interacting with the OLED screen

tomstewart89/Geometry
  - For implementations of Vectors and Matrices that are core to maths for games
  - Essential for constructing a 2D world in which objects had positions and rotations

rjbatista/TM1638
  - For interacting with the Wemos expansion board

northernwidget/DS3231
  - For interacting with the Real Time Clock

*/


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


