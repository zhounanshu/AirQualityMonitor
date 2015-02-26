#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Tap tap(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.print("tap------test");
    Serial.println(tap.getPin());
    delay(500);
}
