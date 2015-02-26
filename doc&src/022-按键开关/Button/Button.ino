#include "SensorLib.h"
#include "Adafruit_GFX.h"
#include <Wire.h>

Button button(2);
void setup(){
    Serial.begin(115200);
}

void loop(){
    Serial.println("Button------test");
    Serial.println(button.getPin());
    delay(500);
}
