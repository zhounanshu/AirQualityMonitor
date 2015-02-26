#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

BigSound bigsound(2,3);

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("bigsound----test");
    Serial.println(bigsound.getAO());
    Serial.println(bigsound.getDO());
    delay(500);  
}
