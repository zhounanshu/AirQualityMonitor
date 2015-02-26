#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Shock shock(2);
int val = 0;
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.print("Shock------test");
    val=shock.getPin();
    if(val==HIGH){
        digitalWrite(13,LOW);
     }
    else{
        digitalWrite(13,HIGH);
    } 
}
