#ifndef WifiOTA_h
#define WifiOTA_h

#include <WiFi.h>  
#include <WebServer.h>
#include <DNSServer.h>
#include <WiFiManager.h>  //https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git

#include <WiFiUdp.h>
#include "ArduinoOTA.h"   //https://github.com/esp8266/Arduino/tree/master/libraries/ArduinoOTA

#include <Button.h>       //https://github.com/meirarc/Button.git

class WifiOTA
{
  public:
    WifiOTA(Button button);
    void begin();
    void handle();

  private:
    Button _button;
};

#endif
