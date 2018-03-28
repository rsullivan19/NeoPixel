#include <Adafruit_NeoPixel.h>

#define PIN 6
int whitePin = 1;
int rgbPin = 2;
int redPin = 3;
int greenPin = 4;
int bluePin = 5;
int buttonState = 0;

// Parameter 1 = number of pixels in strip
// Parameter 2 = pin number (most are valid)
// Parameter 3 = pixel type flags, add together as needed:
//   NEO_KHZ800  800 KHz bitstream (most NeoPixel products w/WS2812 LEDs)
//   NEO_KHZ400  400 KHz (classic 'v1' (not v2) FLORA pixels, WS2811 drivers)
//   NEO_GRB     Pixels are wired for GRB bitstream (most NeoPixel products)
//   NEO_RGB     Pixels are wired for RGB bitstream (v1 FLORA pixels, not v2)
Adafruit_NeoPixel strip = Adafruit_NeoPixel(16, PIN, NEO_GRB + NEO_KHZ800);

void setup() {
  strip.begin();
  strip.setBrightness(30); //adjust brightness here
  strip.show(); // Initialize all pixels to 'off'
  pinMode(whitePin, INPUT);
  pinMode(rgbPin, INPUT);
  pinMode(redPin, INPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin, INPUT);
}

void loop() {


  buttonState = digitalRead(whitePin);
  if (buttonState == HIGH) {
    colorWipe(strip.Color(250, 250, 250), 3); // Red
    colorWipe(strip.Color(250, 250, 250), 3); // Green
    colorWipe(strip.Color(250, 250, 250), 3); // Blue
  }
  else {
    digitalWrite(whitePin, LOW);
  }
}


// Fill the dots one after the other with a color
void colorWipe(uint32_t c, uint8_t wait) {
  for (uint16_t i = 0; i < strip.numPixels(); i++) {
    strip.setPixelColor(i, c);
    strip.show();
    delay(wait);
  }
}


