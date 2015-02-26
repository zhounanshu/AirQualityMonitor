#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

AnalogHall ah(2);
void setup(){
  Serial.begin(115200);
}
void loop(){
  Serial.print("AnalogHall------test");
  Serial.println(ah.getPin());
  delay(500);
}
