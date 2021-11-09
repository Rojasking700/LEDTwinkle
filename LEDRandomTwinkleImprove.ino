#include "FastLED.h"
#define NUM_LEDS 145
#define PIN 2


CRGB leds[NUM_LEDS];

void setup()
{
  FastLED.addLeds<WS2812, PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
  FastLED.setMaxPowerInVoltsAndMilliamps(5, 500);
}


void loop() {
  int randomInts[] = {5,25,74,111,46,68,94,1,140,134,100,60,16,34,20,63,130,37,91,56}; // starts an array with random variables
  TwinkleRandom(20, 500, false, randomInts); // turns on the leds according to the array
  
  while(true){
      RandomNew(randomInts); // updates the list 
      delay(10);
  }
  
}

void RandomNew(int randomInts[]){ 
  setPixel(randomInts[0],0,0,0); // turns the first led of the array off
  showStrip(); //shows the led being turned off

  for(int i =0; i<19; i++){ // this for loop goes through the array
    randomInts[i]= randomInts[i+1]; // updates the array by moving all the values forward
    leds[randomInts[i]].fadeToBlackBy(random(0,150));
    showStrip();
  }
  
  int nInt = random(NUM_LEDS); //nInt is set to random integer between 0-145
  randomInts[19] = nInt; // updates index 19 ro nInt
  setPixel(randomInts[19],random(0, 255),random(0, 255),random(0, 255));// turns index 19 on and to a random color
  showStrip();
}


void TwinkleRandom(int Count, int SpeedDelay, boolean OnlyOne, int RIs[]) {
  setAll(0, 0, 0);// sets them all off
  
  for (int i = 0; i < Count; i++) { 
    setPixel(RIs[i], random(0, 255), random(0, 255), random(0, 255)); //turns on the leds 
    showStrip();
    delay(SpeedDelay);
    if (OnlyOne) {
      setAll(0, 0, 0);
    }
  }

  delay(SpeedDelay);
}

void showStrip() {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.show();
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  FastLED.show();
#endif
}

void setPixel(int Pixel, byte red, byte green, byte blue) {
#ifdef ADAFRUIT_NEOPIXEL_H
  // NeoPixel
  strip.setPixelColor(Pixel, strip.Color(red, green, blue));
#endif
#ifndef ADAFRUIT_NEOPIXEL_H
  // FastLED
  leds[Pixel].r = red;
  leds[Pixel].g = green;
  leds[Pixel].b = blue;
#endif
}

void setAll(byte red, byte green, byte blue) {
  for (int i = 0; i < NUM_LEDS; i++ ) {
    setPixel(i, red, green, blue);
  }
  showStrip();
}
