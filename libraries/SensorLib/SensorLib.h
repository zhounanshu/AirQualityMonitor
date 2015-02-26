#ifndef SensorLib_H
#define SensorLib_H
#include <aJSON.h>


#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#include <Adafruit_GFX.h>
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


/**************************************************************/


/**************************************************************/
// define the constants of the Dust
#define  samplingTime  280
#define  deltaTime     40
#define  sleepTime     9680
/**************************************************************/


/*************************************************************/
//define the constants of the IR
#define NEC 1
#define SONY 2
#define RC5 3
#define RC6 4
#define UNKNOWN -1
// Decoded value for NEC when a repeat code is received
#define REPEAT 0xffffffff

// Only used for testing; can remove virtual for shorter code
#ifdef TEST
#define VIRTUAL virtual
#else
#define VIRTUAL
#endif


#define USECPERTICK 50  // microseconds per clock interrupt tick
#define RAWBUF 76 // Length of raw duration buffer

// Marks tend to be 100us too long, and spaces 100us too short
// when received due to sensor lag.
#define MARK_EXCESS 100

/*************************************************************/


/*************************************************************/
//define the constants of the IR
#define NEC 1
#define SONY 2
#define RC5 3
#define RC6 4
#define UNKNOWN -1
// Decoded value for NEC when a repeat code is received
#define REPEAT 0xffffffff

// Only used for testing; can remove virtual for shorter code
#ifdef TEST
#define VIRTUAL virtual
#else
#define VIRTUAL
#endif


#define USECPERTICK 50  // microseconds per clock interrupt tick
#define RAWBUF 76 // Length of raw duration buffer

// Marks tend to be 100us too long, and spaces 100us too short
// when received due to sensor lag.
#define MARK_EXCESS 100





/************************Hardware Related Macros************************************/

#define         DC_GAIN                      8.5   //define the DC gain of amplifier


/***********************Software Related Macros************************************/
#define         READ_SAMPLE_INTERVAL         50    //define how many samples you are going to take in normal operation
#define         READ_SAMPLE_TIMES            5     //define the time interval(in milisecond) between each samples in 
                                                     //normal operation

/**********************Application Related Macros**********************************/
//These two values differ from sensor to sensor. user should derermine this value.
#define         ZERO_POINT_VOLTAGE           0.324 //define the output of the sensor in volts when the concentration of CO2 is 400PPM
#define         REACTION_VOLTGAE             0.020 //define the voltage drop of the sensor when move the sensor from air into 1000ppm CO2



/**************************************************************/
//define the constants of the OLED

#define BLACK 0
#define WHITE 1

#define SSD1306_I2C_ADDRESS   0x3C  // 011110+SA0+RW - 0x3C or 0x3D

   #define SSD1306_128_64

#if defined SSD1306_128_64 && defined SSD1306_128_32
  #error "Only one SSD1306 display can be specified at once in SSD1306.h"
#endif
#if !defined SSD1306_128_64 && !defined SSD1306_128_32
  #error "At least one SSD1306 display must be specified in SSD1306.h"
#endif

#if defined SSD1306_128_64
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 64
#endif
#if defined SSD1306_128_32
  #define SSD1306_LCDWIDTH                  128
  #define SSD1306_LCDHEIGHT                 32
#endif

#define SSD1306_SETCONTRAST 0x81
#define SSD1306_DISPLAYALLON_RESUME 0xA4
#define SSD1306_DISPLAYALLON 0xA5
#define SSD1306_NORMALDISPLAY 0xA6
#define SSD1306_INVERTDISPLAY 0xA7
#define SSD1306_DISPLAYOFF 0xAE
#define SSD1306_DISPLAYON 0xAF

#define SSD1306_SETDISPLAYOFFSET 0xD3
#define SSD1306_SETCOMPINS 0xDA

#define SSD1306_SETVCOMDETECT 0xDB

#define SSD1306_SETDISPLAYCLOCKDIV 0xD5
#define SSD1306_SETPRECHARGE 0xD9

#define SSD1306_SETMULTIPLEX 0xA8

#define SSD1306_SETLOWCOLUMN 0x00
#define SSD1306_SETHIGHCOLUMN 0x10

#define SSD1306_SETSTARTLINE 0x40

#define SSD1306_MEMORYMODE 0x20

#define SSD1306_COMSCANINC 0xC0
#define SSD1306_COMSCANDEC 0xC8

#define SSD1306_SEGREMAP 0xA0

#define SSD1306_CHARGEPUMP 0x8D

#define SSD1306_EXTERNALVCC 0x1
#define SSD1306_SWITCHCAPVCC 0x2

// Scrolling #defines
#define SSD1306_ACTIVATE_SCROLL 0x2F
#define SSD1306_DEACTIVATE_SCROLL 0x2E
#define SSD1306_SET_VERTICAL_SCROLL_AREA 0xA3
#define SSD1306_RIGHT_HORIZONTAL_SCROLL 0x26
#define SSD1306_LEFT_HORIZONTAL_SCROLL 0x27
#define SSD1306_VERTICAL_AND_RIGHT_HORIZONTAL_SCROLL 0x29
#define SSD1306_VERTICAL_AND_LEFT_HORIZONTAL_SCROLL 0x2A
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
class JoyStick{
public:
    JoyStick(int x, int y, int z);
    int getX();
    int getY();
    int getZ(); 
private:
  int Xpin;
  int Ypin;
  int Zpin;
};


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

class Flame{
public:
    Flame(int sensorpin);
    int getPin();
private:
    int SensorPin;
};




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
//将三色ＬＥＤ程序以类的形式打包
//类里面定义 （1）构造函数（2）功能函数（3）变量
class LED3clr{
public:  //打算给用户使用的函数、变量在public下
  LED3clr(int redpin,int greenpin,int bluepin);           //类的构造函数，通过函数参数初始化对象的一些变量，
                              //构造函数不用指定函数返回类型
                              //我们的这个项目用于初始化传感器引脚


  void RLED(int val);             //  val 取值0~255  表示LED亮暗程度
  void GLED(int val);
  void BLED(int val);

private:   //与用户无关的函数、变量在private下 
       //这些函数一般是传感器因为本身测量原因而需要的一些转换函数
       //比如dth22的read函数，只用于读取传感器的输入，用来计算温湿度，用户不需要知道怎样计算的所以read函数在private下
       //这个程序太简单 没有private类型的函数（类可以只有public函数，不写private）

  int Redpin;     //定义本传感器管脚对应的变量，因为用户是通过构造函数设置管脚的，所以将这些变量放在private下
  int Greenpin;
  int Bluepin;
};         //不要忘记这里的分号

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
class Pulse{
public:
Pulse(int sensorpin);
void Pulse_test(int sensorpin);
void set(int x);
double getPin();

private:
double oldValue ;
double oldChange ;
int SensorPin ;
double alpha ;
int period ;
double change ;

};


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

class LightCup{
  
  public:
    LightCup(int ledPinA,int ledPinB,int buttonPinA,int buttonPinB);
    void on();
    void off();
    
  private:
    int LedPinA ;
    int LedPinB;

    int ButtonPinA ;     //digital
    int ButtonPinB ;
  
    int buttonStateA; 
    int buttonStateB;
    int brightness  ;
};

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

class HallMagentic{
  public:
  HallMagentic( int sensorpin);
  int  getPin();
  
  private:

    int SensorPin;
    
};


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
class Relay{
public:
    Relay(int sensorpin);
    void on();
    void off();
private:
    int SensorPin;
};


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
class LinearHall{
public:
    LinearHall(int sensorpin);
    int getPin(); 
private:
    int SensorPin;
};


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

class LED3Fclr{
public:  //打算给用户使用的函数、变量在public下
  LED3Fclr(int redpin,int greenpin,int bluepin);           //类的构造函数，通过函数参数初始化对象的一些变量，
                              //构造函数不用指定函数返回类型
                              //我们的这个项目用于初始化传感器引脚


  void RLED(int val);             //  val 取值0~255  表示LED亮暗程度
  void GLED(int val);
  void BLED(int val);

private:   //与用户无关的函数、变量在private下 
       //这些函数一般是传感器因为本身测量原因而需要的一些转换函数
       //比如dth22的read函数，只用于读取传感器的输入，用来计算温湿度，用户不需要知道怎样计算的所以read函数在private下
       //这个程序太简单 没有private类型的函数（类可以只有public函数，不写private）

  int Redpin;     //定义本传感器管脚对应的变量，因为用户是通过构造函数设置管脚的，所以将这些变量放在private下
  int Greenpin;
  int Bluepin;
};         //不要忘记这里的分号



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


class LED7Flash{
  public:
  LED7Flash(int led);
  void on();
  void off();
  private:
  
  int Led;
};

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

class MerSwitch{
  public:
  MerSwitch(int buttonpin);
  int getPin();
  
  private:
  int ButtonPin;

};


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
class BigSound {
public:
    BigSound(int aout,int dout);
    int getAO();
    int getDO();
  
private:
    int AO;
    int DO;
};



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

class Touch{
public:
    Touch(int sensorpin);
    int getPin();
private:
    int SensorPin;
};


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

class Twoclr5mm{
public:  
  Twoclr5mm(int redpin,int bluepin);           

  void RLED(int val);             
  void BLED(int val);
private:   
  int Redpin;   
  int Bluepin;
};         

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
class LaserEmit{
  public :
  LaserEmit(int pin); 
  void on();
  void off();
  
  private:
  int Pin;
};


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
class SlopeSwitch{
  public :
    SlopeSwitch(int buttonpin);
    int  getPin();
  private:
    int ButtonPin;
};


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

class AnalogTemp{
  public :
  AnalogTemp(int analog_temp);
  double getPin();
  private:
  double Thermister(int RawADC);
  int Analog_temp;

};


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
class SmallSound {
public:
    SmallSound(int aout,int dout);
    int getAO();
    int getDO();
  
private:
    int AO;
    int DO;
};



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

class DigitalTemp{
public:
    DigitalTemp(int sensorpin);
    int getPin();
private:
    int SensorPin;
};


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

class LED3clr3mm{
public:  
  LED3clr3mm(int redpin,int bluepin);           

  void RLED(int val);             
  void BLED(int val);
private:   
  int Redpin;   
  int Bluepin;
};        

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

class Button{
  public :
  Button(int buttonpin);
  int  getPin();
  private:
  int ButtonPin;
};


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

class PhotoResistor{
  public :
  PhotoResistor(int sensorpin);
  int getPin();
  
  private:
  int SensorPin;
};
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
class Tracking{
public:
    Tracking(int sensorpin);
    int getPin();
private:
    int SensorPin;
};

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
class ActiveBuzzer{
public:
    ActiveBuzzer(int sensorpin);
    void on();
    void off();
private:
    int SensorPin;
};


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
class ReedSwitch{
  public :
  ReedSwitch(int sensorpin);
  int  getPin();
  private:
  int SensorPin;
};


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
class Shock{
  public:
  Shock(int sensorpin);
  int getPin();
  
  private:
  int SensorPin;
};



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
class Avoid{
  public:
  Avoid(int sensorpin);
  int  getPin();
  private:
  int SensorPin;
};



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
class PassiveBuzzer{
public:
    PassiveBuzzer(int SensorPin);
    void on();
    void off();
    
private:
  int SensorPin;
};



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
class MiniReed{
public:
    MiniReed(int sensorpin);
    int getPin();
private:
  int SensorPin;
};


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
class AnalogHall{
  
  public:
  AnalogHall(int sensorpin);
  int getPin();
  
  private:

  int SensorPin ;    // select the input pin for the potentiometer
};

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
class Tap{
  public:
  Tap(int sensorpin);
  int getPin();
  
  private:
  int SensorPin ;    // select the input pin for the potentiometer
};


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
class LightBlocking{
  public:
  LightBlocking(int sensorpin);
  int getPin();
  private:
  int SensorPin;
};




/*************************************************************/
/*************************************************************/
/*    Sensor    :Dust           
/*		Class name:Dust
/*		Function  :
/*
/*
/*
/*
/*		
/*************************************************************/		
class Dust{
public:
  Dust(int measurePin,int ledPower);
  
  float getPin();
  float getDust();
  float getvol();
private:
  float dustDensity;
  float voMeasured;
  float calcVoltage;
  int MeasurePin;
  int LedPower;
};



/*************************************************************/
/*************************************************************/
/*    Sensor    :CO2MG            
/*    Class name:CO2MG
/*    Function  :
/*
/*
/*
/*
/*    
/*************************************************************/   

class CO2MG{
  public:
  CO2MG(int MG_pin );
  double getPin();
  int getCO2();
  private:
  float MGRead(int mg_pin);
  int  MGGetPercentage(float volts);
  int MG_PIN;
  float voltage;
  int per;
};



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
class OLED : public Adafruit_GFX {
 public:
  OLED(int8_t SID, int8_t SCLK, int8_t DC, int8_t RST);
  OLED(int8_t RST);

  void begin(uint8_t switchvcc = SSD1306_SWITCHCAPVCC, uint8_t i2caddr = SSD1306_I2C_ADDRESS);
  void ssd1306_command(uint8_t c);
  void ssd1306_data(uint8_t c);

  void clearDisplay(void);
  void invertDisplay(uint8_t i);
  void display();

  void startscrollright(uint8_t start, uint8_t stop);
  void startscrollright(uint8_t start, uint8_t stop,uint8_t speed,uint8_t le = 0,uint8_t re = 127);

  void startscrollleft(uint8_t start, uint8_t stop);
  void startscrollleft(uint8_t start, uint8_t stop,uint8_t speed,uint8_t le = 0,uint8_t re = 127);


  void startscrolldiagright(uint8_t start, uint8_t stop);
  void startscrolldiagright(uint8_t start, uint8_t stop, uint8_t speed);

  void startscrolldiagleft(uint8_t start, uint8_t stop);
  void startscrolldiagleft(uint8_t start, uint8_t stop, uint8_t speed);

  void stopscroll(void);

  void drawPixel(int16_t x, int16_t y, uint16_t color);
  void drawPixel(int16_t x, int16_t y);

  void drawBitmap(int16_t x, int16_t y, const uint8_t *bitmap,
      int16_t w, int16_t h );
  void drawChar(int16_t x, int16_t y, unsigned char c,uint8_t size);
  
 private:
  int8_t _i2caddr, sid, sclk, dc, rst, cs;
  void fastSPIwrite(uint8_t c);
  void slowSPIwrite(uint8_t c);

  volatile uint8_t *mosiport, *clkport, *csport, *dcport;
  uint8_t mosipinmask, clkpinmask, cspinmask, dcpinmask;
};


#endif

