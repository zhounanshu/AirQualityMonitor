#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>
#include "DHT22.h"

DHT22 DHT(7);//digital pin(7)
void setup(){
  Serial.begin(115200);
}
void loop(){
  Serial.print("the humidity is : ");
  //get humidity value
  Serial.println( DHT.getHum());
  //get temperature value
  Serial.print("the temperature is :");
  Serial.println( DHT.getTem());
  Serial.println(" ");
  delay(1000);
}
