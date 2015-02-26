#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

SmallSound smallsound(2,3);
void setup(){
    Serial.begin(115200);
}

void loop(){
   Serial.println("smallsound------test");
   Serial.println(smallsound.getAO());
   Serial.println(smallsound.getDO());
   delay(500);  
}
