#include <Adafruit_NeoPixel.h>
#include <Adafruit_CircuitPlayground.h>

bool leftButtonPressed;
bool rightButtonPressed;

#define CPLAY_NEOPIXELPIN 6
#define NUMPIXELS 12
  
void setup() {
  Serial.begin(9600);
  CircuitPlayground.begin();
  CircuitPlayground.strip.begin();
  
  CircuitPlayground.strip = Adafruit_CPlay_NeoPixel();
  CircuitPlayground.strip.updateType(NEO_GRB + NEO_KHZ800);
  CircuitPlayground.strip.updateLength(NUMPIXELS);
  CircuitPlayground.strip.setPin(CPLAY_NEOPIXELPIN);

  CircuitPlayground.strip.show();
  CircuitPlayground.strip.setBrightness(50);
  CircuitPlayground.strip.clear();
}

void loop() {
   Serial.println("loop");
   CircuitPlayground.strip.setPixelColor(5, 0, 150, 0);
  
   for(int i=0; i<NUMPIXELS; i++) { // For each pixel...
    Serial.println("for");
    CircuitPlayground.strip.setPixelColor(i, CircuitPlayground.strip.Color(0, 150, 0));
    CircuitPlayground.strip.show();
    delay(50);
   }
  delay(1000);
}
