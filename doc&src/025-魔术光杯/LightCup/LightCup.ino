#include  "SensorLib.h"
#include<Wire.h>
#include  <Adafruit_GFX.h>

LightCup lightcup(8,9,10,11);//digtal pin

void setup(void){
    Serial.begin(115200);
}

void loop(){
    lightcup.on();
    delay(25);
}
