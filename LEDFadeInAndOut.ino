//#include "FastLED.h"
//#define NUM_LEDS 145
//#define PIN 2
//
//CRGB leds[NUM_LEDS];
//
//void setup()
//{
//  FastLED.addLeds<WS2812, PIN, RGB>(leds, NUM_LEDS).setCorrection( TypicalLEDStrip );
//  FastLED.setMaxPowerInVoltsAndMilliamps(5,500);
//}
//
//void loop() {
//  RGBLoop();
//}
//
//void RGBLoop(){
//  for(int j = 0; j < 3; j++ ) {
//    // Fade IN
//    for(int k = 0; k < 256; k++) {
//      switch(j) {
//        case 0: setAll(k,0,0); break;
//        case 1: setAll(0,k,0); break;
//        case 2: setAll(0,0,k); break;
//      }
//      showStrip();
//      delay(3);
//    }
//    // Fade OUT
//    for(int k = 255; k >= 0; k--) {
//      switch(j) {
//        case 0: setAll(k,0,0); break;
//        case 1: setAll(0,k,0); break;
//        case 2: setAll(0,0,k); break;
//      }
//      showStrip();
//      delay(3);
//    }
//  }
//}
//
//
//
//
//void showStrip() {
// #ifdef ADAFRUIT_NEOPIXEL_H
//   // NeoPixel
//   strip.show();
// #endif
// #ifndef ADAFRUIT_NEOPIXEL_H
//   // FastLED
//   FastLED.show();
// #endif
//}
//
//void setPixel(int Pixel, byte red, byte green, byte blue) {
// #ifdef ADAFRUIT_NEOPIXEL_H
//   // NeoPixel
//   strip.setPixelColor(Pixel, strip.Color(red, green, blue));
// #endif
// #ifndef ADAFRUIT_NEOPIXEL_H
//   // FastLED
//   leds[Pixel].r = red;
//   leds[Pixel].g = green;
//   leds[Pixel].b = blue;
// #endif
//}
//
//void setAll(byte red, byte green, byte blue) {
//  for(int i = 0; i < NUM_LEDS; i++ ) {
//    setPixel(i, red, green, blue);
//  }
//  showStrip();
//}
