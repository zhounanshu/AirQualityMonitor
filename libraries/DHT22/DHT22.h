#ifndef DHT22_H
#define DHT22_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif


#define DHT_LIB_VERSION "Hackathon -- For Electronics Enthusiasts By Omni-Lab "

#define DHTLIB_OK              0
#define DHTLIB_ERROR_CHECKSUM -1
#define DHTLIB_ERROR_TIMEOUT  -2
#define DHTLIB_INVALID_VALUE  -999

class DHT22{
  public:
   	DHT22(int pin);   
    double getHum();
    double getTem();
    
 
  private:
  	int read22(uint8_t pin);
  	double humidity;
    double temperature;
    int DHT22_PIN ;
    uint8_t bits[5];  // buffer to receive data
    int read(uint8_t pin);
};


#endif // dht22_H
