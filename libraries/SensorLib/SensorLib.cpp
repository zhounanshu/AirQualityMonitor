#include "SensorLib.h"
#include <math.h>


#include <avr/pgmspace.h>
#include <util/delay.h>
#include <stdlib.h>
#include <Wire.h>
#include "Adafruit_GFX.h"




#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

/**************************************************************/
/* introdude the author,vison,etc.
/*
/*
/*
/*
/*
/*
/*
/*
/**************************************************************/



/**************************************************************/
// define the constants of the DHT22
#define TIMEOUT (F_CPU/1600)
#define DHTLIB_OK 0
#define DHTLIB_ERROR_CHECKSUM 1
#define DHTLIB_ERROR_TIMEOUT 2                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                                n
/**************************************************************/


/**************************************************************/
// define the cnstants of the OLED
static uint8_t buffer[SSD1306_LCDHEIGHT * SSD1306_LCDWIDTH / 8] = { 
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80,
0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x80, 0x80, 0xC0, 0xC0, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF8, 0xFC, 0xF8, 0xE0, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80,
0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x80, 0x00, 0xFF,
0xFF, 0xFF, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00,
0x80, 0xFF, 0xFF, 0x80, 0x80, 0x00, 0x80, 0x80, 0x00, 0x80, 0x80, 0x80, 0x80, 0x00, 0x80, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x80, 0x80, 0x00, 0x00, 0x8C, 0x8E, 0x84, 0x00, 0x00, 0x80, 0xF8,
0xF8, 0xF8, 0x80, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xF0, 0xE0, 0xE0, 0xC0, 0x80,
0x00, 0xE0, 0xFC, 0xFE, 0xFF, 0xFF, 0xFF, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFF, 0xC7, 0x01, 0x01,
0x01, 0x01, 0x83, 0xFF, 0xFF, 0x00, 0x00, 0x7C, 0xFE, 0xC7, 0x01, 0x01, 0x01, 0x01, 0x83, 0xFF,
0xFF, 0xFF, 0x00, 0x38, 0xFE, 0xC7, 0x83, 0x01, 0x01, 0x01, 0x83, 0xC7, 0xFF, 0xFF, 0x00, 0x00,
0x01, 0xFF, 0xFF, 0x01, 0x01, 0x00, 0xFF, 0xFF, 0x07, 0x01, 0x01, 0x01, 0x00, 0x00, 0x7F, 0xFF,
0x80, 0x00, 0x00, 0x00, 0xFF, 0xFF, 0x7F, 0x00, 0x00, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0x01, 0xFF,
0xFF, 0xFF, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x03, 0x0F, 0x3F, 0x7F, 0x7F, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xE7, 0xC7, 0xC7, 0x8F,
0x8F, 0x9F, 0xBF, 0xFF, 0xFF, 0xC3, 0xC0, 0xF0, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFC, 0xFC, 0xFC,
0xFC, 0xFC, 0xFC, 0xFC, 0xFC, 0xF8, 0xF8, 0xF0, 0xF0, 0xE0, 0xC0, 0x00, 0x01, 0x03, 0x03, 0x03,
0x03, 0x03, 0x01, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01,
0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x03, 0x03, 0x03, 0x01, 0x01, 0x03, 0x03, 0x00, 0x00,
0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x03, 0x03, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x01,
0x03, 0x03, 0x03, 0x03, 0x03, 0x01, 0x00, 0x00, 0x00, 0x01, 0x03, 0x01, 0x00, 0x00, 0x00, 0x03,
0x03, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
#if (SSD1306_LCDHEIGHT == 64)
0x00, 0x00, 0x00, 0x80, 0xC0, 0xE0, 0xF0, 0xF9, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x3F, 0x1F, 0x0F,
0x87, 0xC7, 0xF7, 0xFF, 0xFF, 0x1F, 0x1F, 0x3D, 0xFC, 0xF8, 0xF8, 0xF8, 0xF8, 0x7C, 0x7D, 0xFF,
0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x3F, 0x0F, 0x07, 0x00, 0x30, 0x30, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0xFC, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xE0, 0xC0, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x30, 0x30, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0xC0, 0xFE, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0x7F, 0x7F, 0x3F, 0x1F,
0x0F, 0x07, 0x1F, 0x7F, 0xFF, 0xFF, 0xF8, 0xF8, 0xFF, 0xFF, 0xFF, 0xFF, 0xFF, 0xFE, 0xF8, 0xE0,
0x00, 0x00, 0x00, 0x01, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00,
0x00, 0xFC, 0xFE, 0xFC, 0x0C, 0x06, 0x06, 0x0E, 0xFC, 0xF8, 0x00, 0x00, 0xF0, 0xF8, 0x1C, 0x0E,
0x06, 0x06, 0x06, 0x0C, 0xFF, 0xFF, 0xFF, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0x00, 0x00, 0xFC,
0xFE, 0xFC, 0x00, 0x18, 0x3C, 0x7E, 0x66, 0xE6, 0xCE, 0x84, 0x00, 0x00, 0x06, 0xFF, 0xFF, 0x06,
0x06, 0xFC, 0xFE, 0xFC, 0x0C, 0x06, 0x06, 0x06, 0x00, 0x00, 0xFE, 0xFE, 0x00, 0x00, 0xC0, 0xF8,
0xFC, 0x4E, 0x46, 0x46, 0x46, 0x4E, 0x7C, 0x78, 0x40, 0x18, 0x3C, 0x76, 0xE6, 0xCE, 0xCC, 0x80,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x01, 0x07, 0x0F, 0x1F, 0x1F, 0x3F, 0x3F, 0x3F, 0x3F, 0x1F, 0x0F, 0x03,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00,
0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x03, 0x07, 0x0E, 0x0C,
0x18, 0x18, 0x0C, 0x06, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x01, 0x0F, 0x0E, 0x0C, 0x18, 0x0C, 0x0F,
0x07, 0x01, 0x00, 0x04, 0x0E, 0x0C, 0x18, 0x0C, 0x0F, 0x07, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00,
0x00, 0x0F, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x0F, 0x0F, 0x00, 0x00, 0x00, 0x07,
0x07, 0x0C, 0x0C, 0x18, 0x1C, 0x0C, 0x06, 0x06, 0x00, 0x04, 0x0E, 0x0C, 0x18, 0x0C, 0x0F, 0x07,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00,
0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00
#endif
};
/**************************************************************/





/*************************************************************/




/*************************************************************/
/*************************************************************/
/*    Sensor    :JoyStick              
/*		Class name:JoyStick
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
JoyStick::JoyStick(int x, int y, int z){
  Xpin=x;
  Ypin=y;
  Zpin=z;
  pinMode(Xpin,INPUT);
  pinMode(Ypin,INPUT);
  pinMode(Zpin,INPUT);
}
int JoyStick::getX(){
  return analogRead(Xpin);
  delay(400);
}

int JoyStick::getY(){
  return analogRead(Ypin);
  delay(400);
}

int JoyStick::getZ(){
  return digitalRead(Zpin);
  delay(400);
}


/*************************************************************/
/*************************************************************/
/*    Sensor    :Flame             
/*		Class name:Flame
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

Flame::Flame(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,INPUT);
}
int  Flame::getPin(){
    return digitalRead(SensorPin);
}


/*************************************************************/
/*************************************************************/
/*    Sensor    :LED3clr             
/*		Class name:LED3clr
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

LED3clr::LED3clr(int redpin,int greenpin,int bluepin){    //构造函数的实现、注意  LED3clr::  
                              //这是用来表明本函数实现的是类LED3clr中的构造函数LED3clr（）
  
  Redpin = redpin;           //将参数值传给类的变量
  Greenpin = greenpin;
  Bluepin = bluepin;

  pinMode(Redpin, OUTPUT);    //定义Arduino板子的对应端口
  pinMode(Bluepin, OUTPUT);
  pinMode(Greenpin, OUTPUT);
}

void LED3clr::RLED(int val){      
  analogWrite(Redpin, val);      
}             
void LED3clr::GLED(int val){
  analogWrite(Greenpin, val);
}
void LED3clr::BLED(int val){
  analogWrite(Bluepin, val);
}





/*************************************************************/
/*************************************************************/
/*    Sensor    :Pulse            
/*		Class name:Pulse
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Pulse::Pulse(int sensorpin){

 SensorPin = sensorpin;
  oldValue = 0;
  oldChange = 0;
  
  alpha = 0.75;
  period = 20;
  change = 0.0;
}
void Pulse::Pulse_test(int sensorpin){
    oldValue = 0;
    oldChange = 0;
  
    for (int i = 0;i<10000000;++i){

    int rawValue = analogRead(SensorPin);
    double value = alpha * oldValue + (1 - alpha) * rawValue;
    
    Serial.print(rawValue);
    Serial.print(",");
    Serial.println(value);

    oldValue = value;
    delay(period);
  }
}

void Pulse::set(int x){
  alpha = x;
}
double Pulse::getPin(){

  oldValue=0;
  int rawValue=analogRead(SensorPin);
  double value= alpha*oldValue+(1 - alpha) *rawValue;
  oldValue=value;
  return value;

}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LightCup            
/*		Class name:LightCup
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/	



LightCup::LightCup(int ledPinA,int ledPinB,int buttonPinA,int buttonPinB){
	
    LedPinA    = ledPinA;
    LedPinB    = ledPinB;
    ButtonPinA = buttonPinA;     
    ButtonPinB = buttonPinB;
	
	  buttonStateA = 0; 
    buttonStateB = 0;
	  int brightness  ;
	  pinMode(LedPinA, OUTPUT); 
    pinMode(LedPinB, OUTPUT);  
    pinMode(ButtonPinA, INPUT); 
    pinMode(ButtonPinB, INPUT);  
	
}
	
	
void LightCup::on(){
		
	buttonStateA = digitalRead(ButtonPinA);
  if (buttonStateA == HIGH && brightness != 255){ 
   brightness ++;
  } 
   buttonStateB = digitalRead(ButtonPinB);
   if (buttonStateB == HIGH && brightness != 0){ 
   brightness --;
  } 
      analogWrite(LedPinA, brightness);  //  A慢慢变亮
      analogWrite(LedPinB, 255 - brightness);  // B慢慢变凉
      delay(25);
}

void LightCup::off(){
		
      analogWrite(LedPinA,0);  
      analogWrite(LedPinB,0);  
 }


/*************************************************************/
/*************************************************************/
/*    Sensor    :HallMagentic            
/*		Class name:HallMagentic
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/	


HallMagentic::HallMagentic(int SensorPinpin){
	
	SensorPin = SensorPinpin;
	pinMode(SensorPin,INPUT);
}

	int  HallMagentic::getPin(){
	return digitalRead(SensorPin);
}
	

/*************************************************************/
/*************************************************************/
/*    Sensor    :Relay            
/*		Class name:Relay
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

Relay::Relay(int sensorpin){
    SensorPin=sensorpin;
    pinMode(SensorPin,OUTPUT);
}
 
void Relay::on(){
    digitalWrite(SensorPin,HIGH); 
}
void Relay::off(){
    digitalWrite(SensorPin,LOW);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LinearHall            
/*		Class name:LinearHall
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

LinearHall::LinearHall(int sensorpin){
    SensorPin=sensorpin;
    pinMode(SensorPin,INPUT);
}
 
int LinearHall::getPin(){
	return digitalRead(SensorPin);	
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LED3Fclr            
/*		Class name:LED3Flcr
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
LED3Fclr::LED3Fclr(int redpin,int greenpin,int bluepin){    //构造函数的实现、注意  LED3clr::  
                              //这是用来表明本函数实现的是类LED3clr中的构造函数LED3clr（）
  
  Redpin = redpin;           //将参数值传给类的变量
  Greenpin = greenpin;
  Bluepin = bluepin;

  pinMode(Redpin, OUTPUT);    //定义Arduino板子的对应端口
  pinMode(Bluepin, OUTPUT);
  pinMode(Greenpin, OUTPUT);
}

void LED3Fclr::RLED(int val){      
  analogWrite(Redpin, val);      
}             
void LED3Fclr::GLED(int val){
  analogWrite(Greenpin, val);
}
void LED3Fclr::BLED(int val){
  analogWrite(Bluepin, val);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LED7Flash            
/*		Class name:LED7Flash
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
LED7Flash::LED7Flash(int led){
	Led = led;
	pinMode(Led,OUTPUT);

}
void LED7Flash::on(){
	digitalWrite(Led, HIGH);   // set the LED on
}

void LED7Flash::off(){
	digitalWrite(Led, LOW);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :MerSwitch            
/*		Class name:MerSwitch
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
MerSwitch::MerSwitch(int buttonpin){
		ButtonPin = buttonpin;
        pinMode(ButtonPin, INPUT);    
}

int MerSwitch::getPin(){
	return digitalRead(ButtonPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Temp            
/*		Class name:Temp
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		










/*************************************************************/
/*************************************************************/
/*    Sensor    :BigSound            
/*		Class name:BigSound
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
BigSound::BigSound(int aout,int dout){
  AO = aout;
  DO = dout;
  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
}
int BigSound::getAO(){
    return analogRead(AO);
}
int BigSound::getDO()
{
    return digitalRead(DO);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Touch            
/*		Class name:Touch
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Touch::Touch(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,INPUT);
}
int  Touch::getPin(){
    return digitalRead(SensorPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Twoclr5mm            
/*		Class name:Twoclr5mm
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Twoclr5mm::Twoclr5mm(int redpin,int bluepin){   
  Redpin  = redpin;           
  Bluepin = bluepin;

  pinMode(Redpin, OUTPUT);  
  pinMode(Bluepin, OUTPUT);
}
void Twoclr5mm::RLED(int val){      
  analogWrite(Redpin, val);      
}             

void Twoclr5mm::BLED(int val){
  analogWrite(Bluepin, val);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LaserEmit            
/*		Class name:LaserEmit
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
LaserEmit::LaserEmit(int pin ){
	Pin  = pin;
    pinMode(Pin, OUTPUT); 
}

void LaserEmit::on(){
	  digitalWrite(Pin, HIGH);
}


void LaserEmit::off(){
	  digitalWrite(Pin, LOW);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :SlopeSwitch            
/*		Class name:SlopeSwitch
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
SlopeSwitch::SlopeSwitch(int buttonpin){
	ButtonPin = buttonpin;
	pinMode(ButtonPin,OUTPUT);	
}
int SlopeSwitch::getPin(){
	return digitalRead(ButtonPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :AnalogTemp            
/*		Class name:AnalogTemp
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
AnalogTemp::AnalogTemp(int analog_temp){
  Analog_temp = analog_temp;
  pinMode(Analog_temp,INPUT);
}


double AnalogTemp::Thermister(int RawADC) {
    double Temp;
    Temp = log(((10240000/RawADC) - 10000));
    Temp = 1 / (0.001129148 + (0.000234125 + (0.0000000876741 * Temp * Temp ))* Temp );
    Temp = Temp - 273.15; // Convert Kelvin to Celcius
    return Temp;
}

double AnalogTemp::getPin(){
   return Thermister(analogRead(Analog_temp));
}



/*************************************************************/
/*************************************************************/
/*    Sensor    :SmallSound            
/*		Class name:SmallSound
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
SmallSound::SmallSound(int aout,int dout){
  AO =aout;
  DO = dout;
  pinMode(AO, INPUT);
  pinMode(DO, INPUT);
}
int SmallSound::getAO(){
    return analogRead(AO);
}
int SmallSound::getDO(){
    return digitalRead(DO);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :DigitalTemp            
/*		Class name:DigitalTemp
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
DigitalTemp::DigitalTemp(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,INPUT);
}
int  DigitalTemp::getPin(){
    return digitalRead(SensorPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LED3clr3mm            
/*		Class name:LED3clr3mm
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
LED3clr3mm::LED3clr3mm(int redpin,int bluepin){   
  Redpin = redpin;           
  Bluepin = bluepin;

  pinMode(Redpin, OUTPUT);  
  pinMode(Bluepin, OUTPUT);
}
void LED3clr3mm::RLED(int val){      
  analogWrite(Redpin, val);      
}             

void LED3clr3mm::BLED(int val){
  analogWrite(Bluepin, val);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Button          
/*		Class name:Button
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

Button::Button(int buttonpin){
	ButtonPin = buttonpin;
	pinMode(ButtonPin,INPUT);	
}
int Button::getPin(){
	return digitalRead(ButtonPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :PhotoResistor            
/*		Class name:PhotoResistor
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		


PhotoResistor::PhotoResistor(int sensorpin){
	SensorPin = sensorpin;
	pinMode(SensorPin,INPUT);
}
int PhotoResistor::getPin(){
	return analogRead(SensorPin); 
}
/*************************************************************/
/*************************************************************/
/*    Sensor    :IRemission            
/*		Class name:IRemission
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		





/*************************************************************/
/*************************************************************/
/*    Sensor    :Tracking            
/*		Class name:Tracking
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Tracking::Tracking(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,INPUT);
}
int  Tracking::getPin(){
    return digitalRead(SensorPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :ActiveBuzzer            
/*		Class name:ActiveBuzzer
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
ActiveBuzzer::ActiveBuzzer(int sensorpin){
    SensorPin = sensorpin;
    pinMode(SensorPin,OUTPUT);
  
}
void ActiveBuzzer::on(){
   
    digitalWrite(SensorPin, HIGH);
    
}
void ActiveBuzzer::off(){
   
  
    
    digitalWrite(SensorPin, LOW);
 
}


/*************************************************************/
/*************************************************************/
/*    Sensor    :ReedSwitch            
/*		Class name:ReedSwitch
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
ReedSwitch::ReedSwitch(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,OUTPUT);  
}
int ReedSwitch::getPin(){
  return digitalRead(SensorPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Shock            
/*		Class name:Shock
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Shock::Shock(int sensorpin){
	SensorPin  = sensorpin;
	pinMode (SensorPin , INPUT);
}

int Shock::getPin(){
	return digitalRead(SensorPin);
}



/*************************************************************/
/*************************************************************/
/*    Sensor    :IRreceiver            
/*		Class name:IRreceiver
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		




/*************************************************************/
/*************************************************************/
/*    Sensor    :Avoid            
/*		Class name:Avoid
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Avoid::Avoid(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,INPUT);  
}
int Avoid::getPin(){
  return digitalRead(SensorPin);
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :PassiveBuzzer            
/*		Class name:PassiveBuzzer
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
PassiveBuzzer::PassiveBuzzer(int sensorpin){
    SensorPin=sensorpin;
    pinMode(SensorPin,OUTPUT);
}
void PassiveBuzzer::on(){
   
}
void PassiveBuzzer::off(){
   
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :MiniReed            
/*		Class name:MiniReed
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/	
MiniReed::MiniReed(int sensorpin){
  SensorPin = sensorpin;
  pinMode(SensorPin,OUTPUT);  
}
int MiniReed::getPin(){
  return digitalRead(SensorPin);
}






/*************************************************************/
/*************************************************************/
/*    Sensor    :RotaryEncoders            
/*		Class name:RotaryEncoders
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		






/*************************************************************/
/*************************************************************/
/*    Sensor    :AnalogHall             
/*		Class name:AnalogHall 
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		

AnalogHall::AnalogHall(int sensorpin){
	 SensorPin = sensorpin;
	 pinMode(SensorPin,OUTPUT);
	 
}
		
int AnalogHall::getPin(){
	int SensorValue = analogRead(SensorPin);
	return SensorValue;
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :Tap            
/*		Class name:Tap
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
Tap::Tap(int sensorpin){
	SensorPin = sensorpin;
	pinMode(SensorPin,INPUT);
}


int Tap::getPin(){
	int sensorpin =  digitalRead(SensorPin);
	return sensorpin;
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :LightBlocking            
/*		Class name:LightBlocking
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
LightBlocking::LightBlocking(int sensorpin){
	SensorPin = sensorpin;
	pinMode(SensorPin,INPUT);
}	

int LightBlocking::getPin(){
	int sensorvlaue = digitalRead(SensorPin);
	return sensorvlaue;
}

/*************************************************************/
/************************************************************/
/*    Sensor    :Dust           
/*		Class name:Dust
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
  
Dust::Dust(int measurePin,int ledPower){
   MeasurePin = measurePin;
   LedPower   = ledPower;
    pinMode(LedPower,OUTPUT);
    pinMode(MeasurePin,INPUT);
}
/*
void Dust::on(){
  

    digitalWrite(LedPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);
    voMeasured = analogRead(MeasurePin); // read the dust value
  
    delayMicroseconds(deltaTime);
    digitalWrite(LedPower,HIGH); // turn the LED off
    delayMicroseconds(sleepTime);
 

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage

    
    calcVoltage = voMeasured * (5.0 / 1024.0);

// linear eqaution taken fromhttp://www.howmuchsnow.com/arduino/airquality/
// Chris Nafis (c) 2012

    
  dustDensity = (0.17 * calcVoltage - 0.1)*1000;
  
}*/

float Dust::getPin(){
	digitalWrite(LedPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);
    voMeasured = analogRead(MeasurePin); // read the dust value
	return voMeasured;
}

float Dust::getDust(){
	digitalWrite(LedPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);
    voMeasured = analogRead(MeasurePin); // read the dust value
  
    delayMicroseconds(deltaTime);
    digitalWrite(LedPower,HIGH); // turn the LED off
    delayMicroseconds(sleepTime);
 

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage

    
    calcVoltage = voMeasured * (5.0 / 1024.0);

// linear eqaution taken fromhttp://www.howmuchsnow.com/arduino/airquality/
// Chris Nafis (c) 2012

    
   dustDensity = (0.17 * calcVoltage - 0.1)*1000;
	return dustDensity;
}
float Dust::getvol(){
	digitalWrite(LedPower,LOW); // power on the LED
    delayMicroseconds(samplingTime);
    voMeasured = analogRead(MeasurePin); // read the dust value
  
    delayMicroseconds(deltaTime);
    digitalWrite(LedPower,HIGH); // turn the LED off
    delayMicroseconds(sleepTime);
 

  // 0 - 5V mapped to 0 - 1023 integer values
  // recover voltage

    
    calcVoltage = voMeasured * (5.0 / 1024.0);
 
	return calcVoltage;
}

/*************************************************************/
/*************************************************************/
/*    Sensor    :CO2MG            
/*		Class name:CO2MG
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		



CO2MG::CO2MG(int MG_pin){
	 MG_PIN = MG_pin;
	 pinMode(MG_PIN,INPUT);
}


double CO2MG::getPin(){
	voltage = MGRead(MG_PIN);
	return voltage;
}
int CO2MG::getCO2(){
	voltage = MGRead(MG_PIN);
	per = MGGetPercentage(voltage);
	return per;
}

float CO2MG::MGRead(int mg_pin){
	int i;
    float v=0;
    for (i=0;i<READ_SAMPLE_TIMES;i++) {
        v += analogRead(mg_pin);
        delay(READ_SAMPLE_INTERVAL);
    }
    v = (v/READ_SAMPLE_TIMES) *5/1024 ;
    return v;  
}

int  CO2MG::MGGetPercentage(float volts){
	if ((volts/DC_GAIN )>=ZERO_POINT_VOLTAGE) {
      return -1;
   } else { 
      return pow(10, 2.602-((volts/8.5)-0.324)/0.05025) ;
   }
}






/*************************************************************/
/*************************************************************/
/*    Sensor    :OLED            
/*		Class name:OLED
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		


OLED::OLED(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST) : Adafruit_GFX(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT) {
  cs = 12;
  rst = RST;
  dc = DC;
  sclk = SCLK;
  sid = SID;
}

// initializer for I2C - we only indicate the reset pin!
OLED::OLED(int8_t reset) :
Adafruit_GFX(SSD1306_LCDWIDTH, SSD1306_LCDHEIGHT) {
  sclk = dc = cs = sid = -1;
  rst = reset;
}
  

void OLED::begin(uint8_t vccstate, uint8_t i2caddr) {
  _i2caddr = i2caddr;

  // set pin directions
  if (sid != -1)
  {
    // SPI
    pinMode(sid, OUTPUT);
    pinMode(sclk, OUTPUT);
    pinMode(dc, OUTPUT);
    pinMode(cs, OUTPUT);
    clkport     = portOutputRegister(digitalPinToPort(sclk));
    clkpinmask  = digitalPinToBitMask(sclk);
    mosiport    = portOutputRegister(digitalPinToPort(sid));
    mosipinmask = digitalPinToBitMask(sid);
    csport      = portOutputRegister(digitalPinToPort(cs));
    cspinmask   = digitalPinToBitMask(cs);
    dcport      = portOutputRegister(digitalPinToPort(dc));
    dcpinmask   = digitalPinToBitMask(dc);
  }
  else
  {
    // I2C Init
  Wire.begin(); // Is this the right place for this?
  }

  // Setup reset pin direction (used by both SPI and I2C)  
  pinMode(rst, OUTPUT);
  digitalWrite(rst, HIGH);
  // VDD (3.3V) goes high at start, lets just chill for a ms
  delay(1);
  // bring reset low
  digitalWrite(rst, LOW);
  // wait 10ms
  delay(10);
  // bring out of reset
  digitalWrite(rst, HIGH);
  // turn on VCC (9V?)

   #if defined SSD1306_128_32
    // Init sequence for 128x32 OLED module
    ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
    ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
    ssd1306_command(0x80);                                  // the suggested ratio 0x80
    ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
    ssd1306_command(0x1F);
    ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
    ssd1306_command(0x0);                                   // no offset
    ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
    ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
    if (vccstate == SSD1306_EXTERNALVCC) 
      { ssd1306_command(0x10); }
    else 
      { ssd1306_command(0x14); }
    ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
    ssd1306_command(0x00);                                  // 0x0 act like ks0108
  ssd1306_command(SSD1306_SEGREMAP | 0x1);
    ssd1306_command(SSD1306_COMSCANDEC);
    ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
    ssd1306_command(0x02);
    ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
    ssd1306_command(0x8F);
    ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
    if (vccstate == SSD1306_EXTERNALVCC) 
      { ssd1306_command(0x22); }
    else 
      { ssd1306_command(0xF1); }
    ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
    ssd1306_command(0x40);
    ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
    ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
  #endif

  #if defined SSD1306_128_64
    // Init sequence for 128x64 OLED module
    ssd1306_command(SSD1306_DISPLAYOFF);                    // 0xAE
    ssd1306_command(SSD1306_SETDISPLAYCLOCKDIV);            // 0xD5
    ssd1306_command(0x80);                                  // the suggested ratio 0x80
    ssd1306_command(SSD1306_SETMULTIPLEX);                  // 0xA8
    ssd1306_command(0x3F);
    ssd1306_command(SSD1306_SETDISPLAYOFFSET);              // 0xD3
    ssd1306_command(0x0);                                   // no offset
    ssd1306_command(SSD1306_SETSTARTLINE | 0x0);            // line #0
    ssd1306_command(SSD1306_CHARGEPUMP);                    // 0x8D
    if (vccstate == SSD1306_EXTERNALVCC) 
      { ssd1306_command(0x10); }
    else 
      { ssd1306_command(0x14); }
    ssd1306_command(SSD1306_MEMORYMODE);                    // 0x20
    ssd1306_command(0x00);                                  // 0x0 act like ks0108
    ssd1306_command(SSD1306_SEGREMAP | 0x1);
    ssd1306_command(SSD1306_COMSCANDEC);
    ssd1306_command(SSD1306_SETCOMPINS);                    // 0xDA
    ssd1306_command(0x12);
    ssd1306_command(SSD1306_SETCONTRAST);                   // 0x81
    if (vccstate == SSD1306_EXTERNALVCC) 
      { ssd1306_command(0x9F); }
    else 
      { ssd1306_command(0xCF); }
    ssd1306_command(SSD1306_SETPRECHARGE);                  // 0xd9
    if (vccstate == SSD1306_EXTERNALVCC) 
      { ssd1306_command(0x22); }
    else 
      { ssd1306_command(0xF1); }
    ssd1306_command(SSD1306_SETVCOMDETECT);                 // 0xDB
    ssd1306_command(0x40);
    ssd1306_command(SSD1306_DISPLAYALLON_RESUME);           // 0xA4
    ssd1306_command(SSD1306_NORMALDISPLAY);                 // 0xA6
  #endif
  
  ssd1306_command(SSD1306_DISPLAYON);//--turn on oled panel
}


// the most basic function, set a single pixel
void OLED::drawPixel(int16_t x, int16_t y, uint16_t color) {
  if ((x < 0) || (x >= width()) || (y < 0) || (y >= height()))
    return;

  // check rotation, move pixel around if necessary
  switch (getRotation()) {
  case 1:
    swap(x, y);
    x = WIDTH - x - 1;
    break;
  case 2:
    x = WIDTH - x - 1;
    y = HEIGHT - y - 1;
    break;
  case 3:
    swap(x, y);
    y = HEIGHT - y - 1;
    break;
  }  

  // x is which column
  if (color == WHITE) 
    buffer[x+ (y/8)*SSD1306_LCDWIDTH] |= _BV((y%8));  
  else
    buffer[x+ (y/8)*SSD1306_LCDWIDTH] &= ~_BV((y%8)); 
}

void OLED::invertDisplay(uint8_t i) {
  if (i) {
    ssd1306_command(SSD1306_INVERTDISPLAY);
  } else {
    ssd1306_command(SSD1306_NORMALDISPLAY);
  }
}

void OLED::ssd1306_command(uint8_t c) { 
  if (sid != -1)
  {
    // SPI
    //digitalWrite(cs, HIGH);
    *csport |= cspinmask;
    //digitalWrite(dc, LOW);
    *dcport &= ~dcpinmask;
    //digitalWrite(cs, LOW);
    *csport &= ~cspinmask;
    fastSPIwrite(c);
    //digitalWrite(cs, HIGH);
    *csport |= cspinmask;
  }
  else
  {
    // I2C
    uint8_t control = 0x00;   // Co = 0, D/C = 0
    Wire.beginTransmission(_i2caddr);
    Wire.write(control);
    Wire.write(c);
    Wire.endTransmission();
  }
}

void OLED::drawPixel(int16_t x, int16_t y){
  drawPixel(x,y,WHITE);
}

// startscrollright
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
void OLED::startscrollright(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
void OLED::startscrollright(uint8_t start, uint8_t stop, uint8_t speed,uint8_t le,uint8_t re){

  uint8_t Speed=0;
  switch (speed){
    case 0: Speed = 0x03;break;
    case 1: Speed = 0x02;break;
    case 2: Speed = 0x01;break;
    case 3: Speed = 0x06;break;
    case 4: Speed = 0x00;break;
    case 5: Speed = 0x05;break;
    case 6: Speed = 0x04;break;
    case 7: Speed = 0x07;break;
  }
  ssd1306_command(SSD1306_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(Speed);
  ssd1306_command(stop);
  ssd1306_command(le);
  ssd1306_command(re);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);

}



// startscrollleft
// Activate a right handed scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
void OLED::startscrollleft(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}
void OLED::startscrollleft(uint8_t start, uint8_t stop,uint8_t speed,uint8_t le,uint8_t re)
{
  uint8_t Speed=0;
  switch (speed){
    case 0: Speed = 0x03;break;
    case 1: Speed = 0x02;break;
    case 2: Speed = 0x01;break;
    case 3: Speed = 0x06;break;
    case 4: Speed = 0x00;break;
    case 5: Speed = 0x05;break;
    case 6: Speed = 0x04;break;
    case 7: Speed = 0x07;break;
  }
  ssd1306_command(SSD1306_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(Speed);
  ssd1306_command(stop);
  ssd1306_command(0X00);
  ssd1306_command(0XFF);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}



// startscrolldiagright
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
void OLED::startscrolldiagright(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);  
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}


void OLED::startscrolldiagright(uint8_t start, uint8_t stop,uint8_t speed){
  uint8_t Speed=0;
  switch (speed){
    case 0: Speed = 0x03;break;
    case 1: Speed = 0x02;break;
    case 2: Speed = 0x01;break;
    case 3: Speed = 0x06;break;
    case 4: Speed = 0x00;break;
    case 5: Speed = 0x05;break;
    case 6: Speed = 0x04;break;
    case 7: Speed = 0x07;break;
  }

  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);  
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(Speed);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

// startscrolldiagleft
// Activate a diagonal scroll for rows start through stop
// Hint, the display is 16 rows tall. To scroll the whole display, run:
// display.scrollright(0x00, 0x0F) 
void OLED::startscrolldiagleft(uint8_t start, uint8_t stop){
  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);  
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(0X00);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

void OLED::startscrolldiagleft(uint8_t start, uint8_t stop,uint8_t speed){
  uint8_t Speed = 0;
  switch (speed){
    case 0: Speed = 0x03;break;
    case 1: Speed = 0x02;break;
    case 2: Speed = 0x01;break;
    case 3: Speed = 0x06;break;
    case 4: Speed = 0x00;break;
    case 5: Speed = 0x05;break;
    case 6: Speed = 0x04;break;
    case 7: Speed = 0x07;break;
  }

  ssd1306_command(SSD1306_SET_VERTICAL_SCROLL_AREA);  
  ssd1306_command(0X00);
  ssd1306_command(SSD1306_LCDHEIGHT);
  ssd1306_command(SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL);
  ssd1306_command(0X00);
  ssd1306_command(start);
  ssd1306_command(Speed);
  ssd1306_command(stop);
  ssd1306_command(0X01);
  ssd1306_command(SSD1306_ACTIVATE_SCROLL);
}

void OLED::stopscroll(void){
  ssd1306_command(SSD1306_DEACTIVATE_SCROLL);
}

void OLED::ssd1306_data(uint8_t c) {
  if (sid != -1)
  {
    // SPI
    //digitalWrite(cs, HIGH);
    *csport |= cspinmask;
    //digitalWrite(dc, HIGH);
    *dcport |= dcpinmask;
    //digitalWrite(cs, LOW);
    *csport &= ~cspinmask;
    fastSPIwrite(c);
    //digitalWrite(cs, HIGH);
    *csport |= cspinmask;
  }
  else
  {
    // I2C
    uint8_t control = 0x40;   // Co = 0, D/C = 1
    Wire.beginTransmission(_i2caddr);
    Wire.write(control);
    Wire.write(c);
    Wire.endTransmission();
  }
}

void OLED::display(void) {
  ssd1306_command(SSD1306_SETLOWCOLUMN | 0x0);  // low col = 0
  ssd1306_command(SSD1306_SETHIGHCOLUMN | 0x0);  // hi col = 0
  ssd1306_command(SSD1306_SETSTARTLINE | 0x0); // line #0

  if (sid != -1)
  {
    // SPI
    *csport |= cspinmask;
    *dcport |= dcpinmask;
    *csport &= ~cspinmask;

    for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
      fastSPIwrite(buffer[i]);
      //ssd1306_data(buffer[i]);
    }
    // i wonder why we have to do this (check datasheet)
    if (SSD1306_LCDHEIGHT == 32) {
      for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
        //ssd1306_data(0);
        fastSPIwrite(0);
      }
    }
    *csport |= cspinmask;
  }
  else
  {
    // save I2C bitrate
    uint8_t twbrbackup = TWBR;
    TWBR = 12; // upgrade to 400KHz!

    //Serial.println(TWBR, DEC);
    //Serial.println(TWSR & 0x3, DEC);

    // I2C
    for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
      // send a bunch of data in one xmission
      Wire.beginTransmission(_i2caddr);
      Wire.write(0x40);
      for (uint8_t x=0; x<16; x++) {
  Wire.write(buffer[i]);
  i++;
      }
      i--;
      Wire.endTransmission();
    }
    // i wonder why we have to do this (check datasheet)
    if (SSD1306_LCDHEIGHT == 32) {
      for (uint16_t i=0; i<(SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8); i++) {
  // send a bunch of data in one xmission
  Wire.beginTransmission(_i2caddr);
  Wire.write(0x40);
  for (uint8_t x=0; x<16; x++) {
    Wire.write((uint8_t)0x00);
    i++;
  }
  i--;
  Wire.endTransmission();
      }
    }
    TWBR = twbrbackup;
  }
}

// clear everything
void OLED::clearDisplay(void) {
  memset(buffer, 0, (SSD1306_LCDWIDTH*SSD1306_LCDHEIGHT/8));
}


inline void OLED::fastSPIwrite(uint8_t d) {
  
  for(uint8_t bit = 0x80; bit; bit >>= 1) {
    *clkport &= ~clkpinmask;
    if(d & bit) *mosiport |=  mosipinmask;
    else        *mosiport &= ~mosipinmask;
    *clkport |=  clkpinmask;
  }
  //*csport |= cspinmask;
}



void OLED::drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h){
    Adafruit_GFX::drawBitmap(x,y,bitmap,w,h,WHITE);
}

void OLED::drawChar(int16_t x, int16_t y, unsigned char c,uint8_t size){
    Adafruit_GFX::drawChar(x,  y,   c, WHITE,1,size);
}



inline void OLED::slowSPIwrite(uint8_t d) {
 for (int8_t i=7; i>=0; i--) {
   digitalWrite(sclk, LOW);
   if (d & _BV(i)) {
     digitalWrite(sid, HIGH);
   } 
   else {
     digitalWrite(sid, LOW);
   }
   digitalWrite(sclk, HIGH);
 }
}