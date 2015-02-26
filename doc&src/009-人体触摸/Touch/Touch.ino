#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Touch touch(2);

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Touch------test");
    Serial.println(touch.getPin());
    delay(500); 
}
