#include <SPI.h>
#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

// #define OLED_RESET -1
#define DISPLAY_WIDTH 128
#define DISPLAY_HEIGHT 64
#define DISPLAY_CENTREX 64
#define DISPLAY_CENTREY 32

Adafruit_SSD1306 display(DISPLAY_WIDTH, DISPLAY_HEIGHT);

#define LINE_LENGTH 32

void setup()   {                
  Serial.begin(115200);

  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC, 0x3C);  // initialize with the I2C addr 0x3C (for the 128x64)
  // init done
  
  // Show image buffer on the display hardware.
  // Since the buffer is intialized with an Adafruit splashscreen
  // internally, this will display the splashscreen.
  display.display();
  delay(2000);

  // Clear the buffer.
  display.clearDisplay();
}


void loop() {

  // get the raw input from the analog potentiometer
  int sensorValue = analogRead(A0);

  // convert this into radians
  float angle = DEG_TO_RAD * ((float)sensorValue / 2.8444f + 90);
  
  int endX = DISPLAY_CENTREX + LINE_LENGTH * cos(angle);
  int endY = DISPLAY_CENTREY + LINE_LENGTH * sin(angle);

  // RENDERING
  display.clearDisplay();

  display.drawLine(DISPLAY_CENTREX, DISPLAY_CENTREY, endX, endY, 1);

  display.display();
}


