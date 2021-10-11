#ifndef WifiOTA_h
#define WifiOTA_h

#include <WiFi.h>          //https://github.com/esp8266/Arduino
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>          //https://github.com/tzapu/WiFiManager

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