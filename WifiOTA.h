#ifndef WifiOTA_h
#define WifiOTA_h

#include <WiFi.h>
#include <ESPmDNS.h>
#include <WiFiUdp.h>
#include <ArduinoOTA.h>

class WifiOTA
{
  public:
    WifiOTA(char* ssid, char* password);
    void handle();
    
  private:
    char* _ssid;
    char* _password;
};

#endif
