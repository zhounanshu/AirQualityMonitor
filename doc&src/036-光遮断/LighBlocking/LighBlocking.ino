#include "SensorLib.h"
#include <Adafruit_GFX.h>
#include <Wire.h>

LightBlocking lb(2);
void setup(){
    Serial.begin(115200);
}
void loop(){
    Serial.print("LightBlocking------test");
    Serial.println(lb.getPin());
    delay(500);    
}
