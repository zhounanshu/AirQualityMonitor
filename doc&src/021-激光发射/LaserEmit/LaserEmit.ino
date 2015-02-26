#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

LaserEmit laseremit(2);

void setup(){
}

void loop(){
        laseremit.on();
        delay(500);
        laseremit.off();
        delay(500);    
}
