#include  "SensorLib.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>

HallMagentic       HM(2);

void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("HallMagentic------Test");
    Serial.println(HM.getPin());
    delay(1000);
}
