
#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN            6


#define NUMPIXELS      16


Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 100; // delay for half a second

void setup() {

  pixels.begin(); // This initializes the NeoPixel library.
}

void loop() {



  for (int i = 0; i < NUMPIXELS; i++) {


    pixels.setPixelColor(i, pixels.Color(250, 250, 250)); // Moderately bright green color.

    pixels.show(); // This sends the updated pixel color to the hardware.

    delay(delayval); // Delay for a period of time (in milliseconds).

  }
}
