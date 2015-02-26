#include <aJSON.h>
#include "SensorLib.h"
#include "DHT22.h"
#include  <Wire.h>
#include  <Adafruit_GFX.h>
#include  <WiFi.h>

#define group_num "0"

//define sensor
//DHT22  DHT(7);
//Dust dust(0,6);

WiFi   wifi;
//set the web api, you can change this with your own
char* api = "bc70f62c-09d5-4849-8de7-cc83d2c35f70";
char* resource = "e61d17f4-390a-47a6-8b92-c7a6334c4eed";

//定义wifi模块所需常量
long previousMillis = 0;
long previousMillis2 = 0;
long previousMillis3 = 0;

int  interval1=10;  //4
int  interval2=700;  //500
int  interval3=1000;  //10000

unsigned long currentMillis;
double temperature=0;
double humidity=0;
double du = 0;

aJsonObject *add_data(float T, float H,float D, char* num)
{
    aJsonObject* data = aJson.createArray();
    aJsonObject* guid = aJson.createObject();
    
    aJson.addItemToArray(data,guid); 
    
    aJson.addNumberToObject(guid,"temperature", T);
    aJson.addNumberToObject(guid,"humidity", H);
    aJson.addNumberToObject(guid,"pm2.5", 20);
    aJson.addStringToObject(guid,"group_number", num);
    return data;
}

void setup(){
    Serial.begin(115200); 
}


void loop(){ 
    currentMillis = millis(); 
    //pseudo thread one to handle serial comminication
    if(currentMillis - previousMillis > interval1) {
        previousMillis = currentMillis; 
       // display the message received from the web server
        while(Serial.available())
        Serial.write(Serial.read());  
    }   
    //pseudo thread two to update sensor value
    if(currentMillis - previousMillis2 > interval2){
        previousMillis2 = currentMillis; 
   
        temperature = 20; //DHT.getTem();
        humidity  = 20;//DHT.getHum();
        du = 20;//dust.getDust();
    }
  //pseudo thread three to post request
    if(currentMillis - previousMillis3 > interval3){
        previousMillis3 = currentMillis;
    
        // create a blank aJson object
        aJsonObject* root = aJson.createObject();
        aJsonObject* data = aJson.createArray();
       
        data = add_data(temperature, humidity,du, group_num);
        //post the data
        root = wifi.PackData(data, resource);
        wifi.PostData(root, api);
        //post_request(result);
    
        Serial.println("*************************");
        Serial.println(Serial.read());
        Serial.println("*************************");
        //clean the memory to avoid overflow
        aJson.deleteItem(root);
    }
    delay(1000);
}


