#include "SensorLib.h"
#include <Wire.h>
#include  <Adafruit_GFX.h>

Dust dust(0,6);//(anolog pin, digital pin) 

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("the dust is:");
    Serial.println(dust.getDust());
   delay(2000); 
}

