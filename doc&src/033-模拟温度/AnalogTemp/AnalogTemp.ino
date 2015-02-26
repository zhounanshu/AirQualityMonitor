#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

AnalogTemp at(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Analogtemp------test");
    Serial.println(at.getPin());
    delay(500);
}

