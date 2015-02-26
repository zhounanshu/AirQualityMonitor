#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Avoid avoid(2);
void setup(){
    Serial.begin(115200);
}
void loop(){
    Serial.println("Avoid------test");
    Serial.println(avoid.getPin());
    delay(500);  
}
