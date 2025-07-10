#include<Adafruit_NeoPixel.h>

#define PIN 6
#define tPixel 4
Adafruit_NeoPixel strip =  Adafruit_NeoPixel (tPixel, PIN, NEO_GRB + NEO_KHZ800);
void setup() {
 strip.begin();
}

void loop() {
  int d1 = random(0, 255);
  int d2 = random(0, 255);
  int d3 = random(0, 255);

  for(int r = 0; r < tPixel; r++)
  {
   strip.setPixelColor(r, strip.Color(d1, d2, d3));
    
  strip.show();
  delay(200);
    }
  }