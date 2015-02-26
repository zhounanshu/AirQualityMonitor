#include "SensorLib.h"
#include <Adafruit_GFX.h>
#include <Wire.h>

Relay  RY(1);

void setup(){
}
void loop(){
    RY.on();
    delay(1000);
    RY.off();
    delay(1000);
}
