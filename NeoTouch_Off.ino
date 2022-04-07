#include <Adafruit_NeoPixel.h>
#ifdef __AVR__
#include <avr/power.h> // Required for 16 MHz Adafruit Trinket
#endif


// Which pin on the Arduino is connected to the NeoPixels?
#define PIN        6 // On Trinket or Gemma, suggest changing this to 1

// How many NeoPixels are attached to the Arduino?
#define NUMPIXELS 10 // Popular NeoPixel ring size
 
Adafruit_NeoPixel pixels(NUMPIXELS, PIN, NEO_GRB + NEO_KHZ800);

#define DELAYVAL 500 // Time (in milliseconds) to pause between pixels
#include "ADCTouch.h"

int ref0;
int touchPin1 = A0;
int val0constrained = 0;

int val0high = 350;
int val0low = 0;

int threshold = 10;
int pos = 0;

void setup() {

  pixels.begin(); // INITIALIZE NeoPixel strip object (REQUIRED)

  {
     Serial.begin(9600);
     ref0 = ADCTouch.read(touchPin1, 200);
  }

}
 

void loop() {
  pixels.clear(); // Set all pixel colors to 'off'
  // The first NeoPixel in a strand is #0, second is 1, all the way up
  // to the count of pixels minus one.
  int value0 = ADCTouch.read(touchPin1);
  value0 -= ref0;

  Serial.println(value0);
  
  for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
            // Here we're using a moderately bright green color:
            pixels.setPixelColor(i, pixels.Color(0, 0, 0));
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(10); // Pause before next pass through loop
          }
 
    if (value0 > 50) { // CHANGE THIS VALUE TO REFLECT WHAT YOUR SENSING LEVEL IS?
    colorChange();
    Serial.println(value0);
    }
  delay(10);
 }


void colorChange(){
        for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
            // pixels.Color() takes RGB values, from 0,0,0 up to 255,255,255
            // Here we're using a moderately bright green color:
            pixels.setPixelColor(i, pixels.Color(0, 150, 0));
            pixels.show();   // Send the updated pixel colors to the hardware.
            delay(DELAYVAL); // Pause before next pass through loop
          }
}
 
