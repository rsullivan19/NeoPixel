#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif


#define PIN            6


#define NUMPIXELS      16

const int whitePin = 1;
int rgbPin = 2;
int redPin = 3;
int greenPin = 4;
int bluePin = 5;
int buttonState = 0;

Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30; // delay for half a second

void clear_pixels() {
  for (int i = 0; i < 16; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show();
}

void setup() {
  pinMode(whitePin, INPUT);
  pinMode(rgbPin, INPUT);
  pinMode(redPin, INPUT);
  pinMode(greenPin, INPUT);
  pinMode(bluePin, INPUT);
  pixels.begin(); // This initializes the NeoPixel library.
  clear_pixels();
}

void loop() {

  if ( digitalRead(whitePin) == HIGH ) {
    white();
  }

  if ( digitalRead(rgbPin) == HIGH ) {
    rgb();
  }
  
  if ( digitalRead(redPin) == HIGH ) {
    red();
  }

  if ( digitalRead(greenPin) == HIGH ) {
    green();
  }

  if ( digitalRead(bluePin) == HIGH ) {
    blue();
  }
}

void white() {
  buttonState = digitalRead(whitePin);
  if (buttonState == HIGH )
  {
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(83, 83, 83));
      delay(delayval);
      pixels.show();
    }
  }
}

void rgb() {
  buttonState = digitalRead(rgbPin);
  if (buttonState == HIGH )
  {
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(83, 0, 0));
      delay(delayval);
      pixels.show();
    }
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 83, 0));
      delay(delayval);
      pixels.show();
    }
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 83));
      delay(delayval);
      pixels.show();
    }
  }
}

void red() {
  buttonState = digitalRead(redPin);
  if (buttonState == HIGH )
  {
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(83, 0, 0));
      delay(delayval);
      pixels.show();
    }
  }
}

void green() {
  buttonState = digitalRead(greenPin);
  if (buttonState == HIGH )
  {
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 83, 0));
      delay(delayval);
      pixels.show();
    }
  }
}

void blue() {
  buttonState = digitalRead(bluePin);
  if (buttonState == HIGH )
  {
    for (int i = 0; i < 16; i++) {
      pixels.setPixelColor(i, pixels.Color(0, 0, 83));
      delay(delayval);
      pixels.show();
    }
  }
}

