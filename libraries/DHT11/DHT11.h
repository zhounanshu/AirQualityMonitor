#ifndef DHT11_H
#define DHT11_H

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

class DHT11{
	public:
	DHT11(int sensorpin);
	double getHum();
	double getTem();
	
	private:
	
	void ReadDHT();
	byte read_dht_dat();
	int SensorPin;
	byte bGlobalErr;
	byte dht_dat[5];
};





#endif