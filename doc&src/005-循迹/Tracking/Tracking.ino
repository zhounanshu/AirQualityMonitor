#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Tracking tracking(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Tracking------test");
    Serial.println(tracking.getPin());
    delay(500);   
}
