#include "SensorLib.h"
#include <Wire.h>
#include <Adafruit_GFX.h>

LED7Flash led7flash(2);

void setup(){
    Serial.begin(115200);
}

void loop(){
    led7flash.on();
    delay(2000);
    led7flash.off();
    delay(2000);    
}
