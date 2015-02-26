#include "SensorLib.h"
#include <Adafruit_GFX.h>
#include <Wire.h>
LinearHall	LH(2);

void setup(){
    Serial.begin(115200);
}
void loop(){
	Serial.println("LinearHall------Test");
	Serial.println(LH.getPin());
	delay(100);    
}
