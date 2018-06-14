#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h>
#endif
#define PIN            8
#define NUMPIXELS      16

boolean on = true;
int buttonState = 0;
int a = 0;
int b = 0;
int c = 0;
int x1 = 255;
int x2 = 0;
int x3 = 255;
int x4 = 0;
int x5 = 255;
int x6 = 0;



Adafruit_NeoPixel pixels = Adafruit_NeoPixel(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

int delayval = 30; // delay for half a second

void clear_pixels() {
  for (int i = 0; i < 16; i++) {
    pixels.setPixelColor(i, pixels.Color(0, 0, 0)); // Moderately bright green color.
  }
  pixels.show();
}

#include <Adafruit_MPR121.h>
#include <Wire.h>
Adafruit_MPR121 cap = Adafruit_MPR121();

uint16_t lasttouched = 0;
uint16_t currtouched = 0;

void setup() {

  pinMode(3, OUTPUT);

  pixels.begin(); // This initializes the NeoPixel library.
  clear_pixels();

  while (!Serial);        // needed to keep leonardo/micro from starting too fast!

  Serial.begin(9600);
  Serial.println("Adafruit MPR121 Capacitive Touch sensor test");

  // Default address is 0x5A, if tied to 3.3V its 0x5B
  // If tied to SDA its 0x5C and if SCL then 0x5D
  if (!cap.begin(0x5A)) {
    Serial.println("MPR121 not found, check wiring?");
    while (1);
  }
  Serial.println("MPR121 found!");

}

void loop() {

  currtouched = cap.touched();
  if (cap.touched() & (1 << 8)) {
    for (uint8_t i = 0; i < 16; i++) {
      // it if *is* touched and *wasnt* touched before, alert!
      if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
        a = (x1 + x2) - a;
        Serial.print(i); Serial.println(" touched");
        for (int i = 0; i < 16; i++) {
          pixels.setPixelColor(i, pixels.Color(a, b, c));
          pixels.show();
        }
      }
    }
  }
  if (cap.touched() & (1 << 6)) {
    for (uint8_t i = 0; i < 16; i++) {
      // it if *is* touched and *wasnt* touched before, alert!
      if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
        b = (x3 + x4) - b;
        Serial.print(i); Serial.println(" touched");
        for (int i = 0; i < 16; i++) {
          pixels.setPixelColor(i, pixels.Color(a, b, c));
          pixels.show();
        }
      }
    }
  }
    if (cap.touched() & (1 << 4)) {
    for (uint8_t i = 0; i < 16; i++) {
      // it if *is* touched and *wasnt* touched before, alert!
      if ((currtouched & _BV(i)) && !(lasttouched & _BV(i)) ) {
        c = (x5 + x6) - c;
        Serial.print(i); Serial.println(" touched");
        for (int i = 0; i < 16; i++) {
          pixels.setPixelColor(i, pixels.Color(a, b, c));
          pixels.show();
        }
      }
    }
  }
  // reset our state
  lasttouched = currtouched;

  // comment out this line for detailed data from the sensor!
  return;

  // debugging info, what
  Serial.print("\t\t\t\t\t\t\t\t\t\t\t\t\t 0x"); Serial.println(cap.touched(), HEX);
  Serial.print("Filt: ");
  for (uint8_t i = 0; i < 12; i++) {
    Serial.print(cap.filteredData(i)); Serial.print("\t");
  }
  Serial.println();
  Serial.print("Base: ");
  for (uint8_t i = 0; i < 12; i++) {
    Serial.print(cap.baselineData(i)); Serial.print("\t");
  }
  Serial.println();

  // put a delay so it isn't overwhelming
  delay(1000);
}
