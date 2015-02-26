#include "SensorLib.h"
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>
#include <Wire.h>
#include "DHT22.h"

DHT22 DHT(5);

static unsigned char PROGMEM logo16_glcd_bmp[] =
{ B00000000, B11000000,
  B00000001, B11000000,
  B00000001, B11000000,
  B00000011, B11100000,
  B11110011, B11100000,
  B11111110, B11111000,
  B01111110, B11111111,
  B00110011, B10011111,
  B00011111, B11111100,
  B00001101, B01110000,
  B00011011, B10100000,
  B00111111, B11100000,
  B00111111, B11110000,
  B01111100, B11110000,
  B01110000, B01110000,
  B00000000, B00110000 };
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

OLED Oled(10,11,8,9);//SDA,SCL,DC,RST
void setup(){
    Serial.begin(115200);
    Oled.begin(SSD1306_SWITCHCAPVCC);
    Oled.display(); // show splashscreen
    delay(2000);
    Oled.clearDisplay();   // clears the screen and buffer
}

void loop(){
    // init done  used to show the logo of the vender  
    Oled.setTextSize(2);
    Oled.setTextColor(WHITE);
    Oled.setCursor(0,0);
    Oled.print("H: ");
    //display humidity
    Oled.print(DHT.getHum(), 1);
    Oled.println(" %");
    Oled.print("T: ");
    //display temperature
    Oled.print(DHT.getTem(), 1);
    Oled.println(" C");
    Oled.display();
    delay(100);
    Oled.clearDisplay();   // clears the screen and buffer 
}
