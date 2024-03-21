
#include <Wire.h>
#include "Adafruit_MCP9808.h"

Adafruit_MCP9808 tempsensor = Adafruit_MCP9808();

#include <Adafruit_NeoPixel.h>

#include <avr/power.h>


#define PIN            9

#define NUMPIXELS      8

int temperature = 20;


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);


void setup() {
  Serial.begin(9600);

  pixels.begin();

  if (!tempsensor.begin(0x18)) {
    Serial.println("Couldn't find MCP9808! Check your connections and verify the address is correct.");
    while (1);
  }

  tempsensor.setResolution(3);

}


void loop() {

  tempsensor.wake();

  float c = tempsensor.readTempC();
  Serial.print("Temp: "); 
  Serial.print(c, 4); Serial.print("*C\t and ");
  
  temperature = c*100;

  if (temperature > 2666) {
    for (int x = 0; x < 85; x++) {

      pixels.setPixelColor(0, pixels.Color(150, x, 0));
      pixels.setPixelColor(1, pixels.Color(150, x, 0));
      pixels.setPixelColor(2, pixels.Color(150, x, 0));
      pixels.setPixelColor(3, pixels.Color(150, x, 0));
      pixels.setPixelColor(4, pixels.Color(150, x, 0));
      pixels.setPixelColor(5, pixels.Color(150, x, 0));
      pixels.setPixelColor(6, pixels.Color(150, x, 0));
      pixels.setPixelColor(7, pixels.Color(150, x, 0));

      pixels.show();

      delay(50);

    }
  } else {
    for (int x = 0; x < 250; x++) {

      pixels.setPixelColor(0, pixels.Color(0, 150, x));
      pixels.setPixelColor(1, pixels.Color(0, 150, x));
      pixels.setPixelColor(2, pixels.Color(0, 150, x));
      pixels.setPixelColor(3, pixels.Color(0, 150, x));
      pixels.setPixelColor(4, pixels.Color(0, 150, x));
      pixels.setPixelColor(5, pixels.Color(0, 150, x));
      pixels.setPixelColor(6, pixels.Color(0, 150, x));
      pixels.setPixelColor(7, pixels.Color(0, 150, x));

      pixels.show();

      delay(25);

    }
  }

  tempsensor.shutdown_wake(1);

}
