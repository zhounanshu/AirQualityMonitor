#include "WiFi.h"
#include <aJSON.h>
#include  <Wire.h>
#include  <Adafruit_GFX.h>

#if ARDUINO >= 100
#include "Arduino.h"
#include "Print.h"
#else
#include "WProgram.h"
#endif

WiFi::WiFi(){
    request = req;
    request_head = req_head;
}
aJsonObject* WiFi::PackData(aJsonObject* data, char* resource_id)
{
    aJsonObject* resource_dict = aJson.createObject();
    if(resource_dict == NULL){
      Serial.println("error");
      return resource_dict;
    }

    aJson.addStringToObject(resource_dict,"resource_id", resource_id);
    aJson.addTrueToObject(resource_dict,"force");
    aJson.addItemToObject(resource_dict,"records", data);
    aJson.addStringToObject(resource_dict,"method", "insert");

    return resource_dict;
}

void WiFi::PostData(aJsonObject*  msg, char* api_key)
{
    char temp[512];
    char data[256];
    char value[4];
    char* json=aJson.print(msg);
    strcpy(temp, request);
    strcpy(data,json);
    free(json);
    int length=strlen(data);
    strcat(temp,itoa(length, value,10));
    strcat(temp, request_head);
    strcat(temp, api_key);
    strcat(temp,"\r\n\r\n");
    strcat(temp,data);
    strcat(temp,"\r\n");
    Serial.write(temp);
}
