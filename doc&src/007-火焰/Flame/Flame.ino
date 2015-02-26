#include  "SensorLib.h"
#include  "DHT22.h"
#include  "DHT11.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>

Flame	flame(1);//define digital pin

void setup(){
  Serial.begin(115200);
}

void loop(){
  Serial.print("flame: ");
  Serial.println(flame.getPin());
}
