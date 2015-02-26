#ifndef WIFI_H
#define WIFI_H

#include <aJSON.h>
#include  <Wire.h>
#include  <Adafruit_GFX.h>

#if ARDUINO >= 100
 #include "Arduino.h"
 #include "Print.h"
#else
 #include "WProgram.h"
#endif

#define req  "POST /api/3/action/datastore_upsert HTTP/1.1\r\nHost: 202.121.178.242\r\nContent-Length: "
#define req_head  "\r\nConnection: close\r\nContent-Type: application/x-www-form-urlencoded\r\nAuthorization: "

class WiFi{
public:
    WiFi();
    aJsonObject*  PackData(aJsonObject* data, char* resource_id);
    void PostData(aJsonObject*  msg, char* api_key);

private:
    char* request;
    char* request_head;
};

#endif