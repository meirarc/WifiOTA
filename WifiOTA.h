/**
 * @file WifiOTA.h
 * @author meirarc
 * @brief Wifi Manager and OTA update library
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */

#ifndef WifiOTA_h
#define WifiOTA_h

#include <WiFi.h>               // https://github.com/esp8266/Arduino
#include <WebServer.h>          // https://github.com/zhouhan0126/WebServer-esp32.git
#include <DNSServer.h>          // https://github.com/zhouhan0126/DNSServer---esp32.git
#include <WiFiManager.h>        // https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git

#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class WifiOTA{
    public:
        void begin();
        void reset();
        void handle();
    private:
        char* _APName = "OnDemandAP";
};

#endif