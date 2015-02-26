#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

PhotoResistor photoresistor(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("PhotoResistor------test");
    Serial.println(photoresistor.getPin());
    delay(500);     
}
