#include <Adafruit_CircuitPlayground.h>
#include <Servo.h> 

// modified and untested 

Servo servo1;
uint8_t pixeln = 0;
int capsense[10];
int pos = 0; 

void setup() {
  CircuitPlayground.begin();
  servo1.attach(3);
  Serial.begin(9600);
}

void loop() {
  int servoposition;   
   
  //capsense[0] = CircuitPlayground.readCap(3);
  capsense[1] = CircuitPlayground.readCap(2);
  capsense[2] = CircuitPlayground.readCap(0);
  capsense[3] = CircuitPlayground.readCap(1);
  capsense[4] = CircuitPlayground.readCap(12);
  capsense[5] = CircuitPlayground.readCap(6);
  capsense[6] = CircuitPlayground.readCap(9);
  capsense[7] = CircuitPlayground.readCap(10);

  int frequency = 0;
  int randPosition = random(360);
  
 if  (capsense[0] > 100) {
    frequency = 523;
    CircuitPlayground.setPixelColor(0,75,0,130);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  } else if  (capsense[1] > 100) {
    frequency = 587;
    CircuitPlayground.setPixelColor(1, 0,0,255);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  } else if  (capsense[2] > 100) {
    frequency = 659;
    CircuitPlayground.setPixelColor(3, 138,43,226);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
 // } else if  (capsense[3] > 100) {
    //frequency = 698;
    //CircuitPlayground.setPixelColor(4, 216,191,216);
    //moveServo();
  } else if  (capsense[4] > 100) {
    frequency = 784;
    CircuitPlayground.setPixelColor(5, 238,130,238);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  } else if  (capsense[5] > 100) {
    frequency = 880;
    CircuitPlayground.setPixelColor(6, 0,191,255);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  } else if  (capsense[6] > 100) {
    frequency = 988;
    CircuitPlayground.setPixelColor(8, 199,21,133);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  } else if  (capsense[7] > 100) {
    frequency = 1046;
    CircuitPlayground.setPixelColor(9, 138,43,226);
    moveServo(randPosition);
    Serial.println("randPosition: ");Serial.println(randPosition);
  }
  delay(10);
  CircuitPlayground.clearPixels();
  moveServo(360);
  Serial.println("Out of main code loop");
  //CircuitPlayground.playTone(frequency, 200);
  //servo1.write(randPosition);
/*
   if  (capsense[0] < 99){
    CircuitPlayground.setPixelColor(0, 75,0,130);
    CircuitPlayground.setPixelColor(1, 0,0,255);
    CircuitPlayground.setPixelColor(3, 138,43,226);
    CircuitPlayground.setPixelColor(4, 216,191,216);
    CircuitPlayground.setPixelColor(5, 238,130,238);
    CircuitPlayground.setPixelColor(6, 0,191,255);
    CircuitPlayground.setPixelColor(8, 199,21,133);
    CircuitPlayground.setPixelColor(9, 138,43,226);
   }
*/
  
}

void moveServo(int startPosition){
  for (pos = startPosition; pos <= 359; pos += 1) { // goes from 0 degrees to 180 degrees
    // in steps of 1 degree
    servo1.write(pos);              // tell servo to go to position in variable 'pos'
    delay(15);                       // waits 15ms for the servo to reach the position
    Serial.println("running moveServo Code");
    Serial.println(pos);
     } 
}

/*
  CircuitPlayground.setPixelColor(0, capsense[0], capsense[0], capsense[0]);
  CircuitPlayground.setPixelColor(1, capsense[1], capsense[1], capsense[1]);
  CircuitPlayground.setPixelColor(3, capsense[2], capsense[2], capsense[2]);
  CircuitPlayground.setPixelColor(4, capsense[3], capsense[3], capsense[3]);
  CircuitPlayground.setPixelColor(5, capsense[4], capsense[4], capsense[4]);
  CircuitPlayground.setPixelColor(6, capsense[5], capsense[5], capsense[5]);
  CircuitPlayground.setPixelColor(8, capsense[6], capsense[6], capsense[6]);
  CircuitPlayground.setPixelColor(9, capsense[7], capsense[7], capsense[7]);
  */
