#include "DHT11.h"

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif


DHT11::DHT11(int sensorpin){
	SensorPin = sensorpin;
	pinMode(SensorPin,OUTPUT);
	digitalWrite(SensorPin,HIGH);

}
void DHT11::ReadDHT(){
	bGlobalErr=0;
	byte dht_in;
	byte i;
	digitalWrite(SensorPin,LOW);
	delay(20);

	digitalWrite(SensorPin,HIGH);
	delayMicroseconds(40);
	pinMode(SensorPin,INPUT);
	//delayMicroseconds(40);
	dht_in=digitalRead(SensorPin);

	if(dht_in){
	bGlobalErr=1;
	return;
	}
	delayMicroseconds(80);
	dht_in=digitalRead(SensorPin);

	if(!dht_in){
		bGlobalErr=2;
		return;
	}
	delayMicroseconds(80);
	for (i=0; i<5; i++)
		dht_dat[i] = read_dht_dat();
		pinMode(SensorPin,OUTPUT);
		digitalWrite(SensorPin,HIGH);
		byte dht_check_sum =
        dht_dat[0]+dht_dat[1]+dht_dat[2]+dht_dat[3];
		if(dht_dat[4]!= dht_check_sum)
		{	bGlobalErr=3;}
}

byte DHT11::read_dht_dat(){
  byte i = 0;
  byte result=0;
  for(i=0; i< 8; i++){
      while(digitalRead(SensorPin)==LOW);
      delayMicroseconds(30);
      if (digitalRead(SensorPin)==HIGH)
     result |=(1<<(7-i));
    while (digitalRead(SensorPin)==HIGH);
    }
  return result;

}
double DHT11::getHum(){
	ReadDHT();
	switch (bGlobalErr){
	 case 0:
        break;
     case 1:
        Serial.println("Error 1: DHT11 start condition 1 not met.");
        break;
     case 2:
        Serial.println("Error 2: DHT11 start condition 2 not met.");
        break;
     case 3:
        Serial.println("Error 3: DHT11 checksum error.");
        break;
     default:
        Serial.println("Error: Unrecognized code encountered.");
        break;
      }
	  
	int count = 0;
	while(dht_dat[1]){
		dht_dat[1] = dht_dat[1]/10;
		count++;
	}
    return double(dht_dat[0])+double(dht_dat[1])/10.0;
    delay(500);
}
double DHT11::getTem(){
	ReadDHT();
	switch (bGlobalErr){
	 case 0:
        break;
     case 1:
        Serial.println("Error 1: DHT11 start condition 1 not met.");
        break;
     case 2:
        Serial.println("Error 2: DHT11 start condition 2 not met.");
        break;
     case 3:
        Serial.println("Error 3: DHT11 checksum error.");
        break;
     default:
        Serial.println("Error: Unrecognized code encountered.");
        break;
      }
	  
	int count = 0;
	while(dht_dat[3]){
		dht_dat[3] = dht_dat[3]/10;
		count++;
	}
    return double(dht_dat[2])+double(dht_dat[3])/10.0;
    delay(500);
}

