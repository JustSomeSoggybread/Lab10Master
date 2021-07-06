/******************************************************/
//       THIS IS A GENERATED FILE - DO NOT EDIT       //
/******************************************************/

#include "Particle.h"
#line 1 "c:/Users/evanh/OneDrive/Desktop/CTD/InternetOfThings/Lab10Master/src/Lab10Master.ino"
void setup();
void loop();
#line 1 "c:/Users/evanh/OneDrive/Desktop/CTD/InternetOfThings/Lab10Master/src/Lab10Master.ino"
SYSTEM_MODE(MANUAL);
SYSTEM_THREAD(ENABLED);

#include <Wire.h>
#include "oled-wing-adafruit.h"


/*
      ## MASTER ##
*/
void setup() {
  // Put initialization like pinMode and begin functions here.
  Serial.begin(9600);

  
  //char value = Serial.read();

  while (!Serial.isConnected());

  Wire.begin();
}

void loop() {
  // The core of your code will likely live here.
  
  if (Serial.available()){
    char inputC = Serial.read();

    Wire.beginTransmission(0x2A);
    Wire.write(inputC);
    Wire.endTransmission();

    delay(1000);

    Wire.requestFrom(0x2A, 1);
    //while (Wire.available() == 0);
    char value = Wire.read();

    Serial.println(value);
  }
}