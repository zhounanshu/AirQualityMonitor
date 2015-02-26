#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

DigitalTemp dt(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("digitaltemp------test");
    Serial.println(dt.getPin());
    delay(500);  
}
