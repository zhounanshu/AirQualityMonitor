#include <Wire.h>
#include <Adafruit_GFX.h>
#include <Adafruit_SSD1306.h>

#define OLED_DC 11
#define OLED_CS 12
#define OLED_CLK 10
#define OLED_MOSI 9
#define OLED_RESET 13  //ignore reset
Adafruit_SSD1306 display(OLED_MOSI, OLED_CLK, OLED_DC, OLED_RESET, OLED_CS);

#define NUMFLAKES 10
#define XPOS 0
#define YPOS 1
#define DELTAY 2

#define LOGO16_GLCD_HEIGHT 16 
#define LOGO16_GLCD_WIDTH  16 
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
static unsigned char s[]={'s','o','i','s','f'};
#if (SSD1306_LCDHEIGHT != 64)
#error("Height incorrect, please fix Adafruit_SSD1306.h!");
#endif

#include <dht.h>
dht DHT;
#define DHT22_PIN 5




void setup()   {                
    Serial.begin(9600);
  
  // by default, we'll generate the high voltage from the 3.3v line internally! (neat!)
  display.begin(SSD1306_SWITCHCAPVCC);
  display.display(); // show splashscreen
  delay(2000);
  display.clearDisplay();   // clears the screen and buffer
  
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
 
   display.println();
   

}    
  
void loop() {
   display.setTextSize(1);
   display.setTextColor(WHITE);
   display.setCursor(0,0);
    display.println();
    
    tempandhumi();
    display.display();
    display.clearDisplay();
    
}
void tempandhumi(){
    display.println("Humi(%),Temp(C)");
    uint32_t start = micros();
    int chk = DHT.read22(DHT22_PIN);
    uint32_t stop = micros();

    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    
    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    
    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    
    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    
    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    
    display.print(DHT.humidity, 1);   
    display.print(",   ");
    display.print(DHT.temperature, 1);
    display.println();   
    display.display();
    delay(3000);
    display.clearDisplay();
}


