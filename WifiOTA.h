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
        void begin(){
            WiFiManager wifiManager;
            if(!wifiManager.autoConnect(_APName)) {
                Serial.println("failed to connect and hit timeout");
                ESP.restart();
                delay(1000);
            } 

            ArduinoOTA
                .onStart([]() {
                String type;
                if (ArduinoOTA.getCommand() == U_FLASH)
                    type = "sketch";
                else // U_SPIFFS
                    type = "filesystem";

                // NOTE: if updating SPIFFS this would be the place to unmount SPIFFS using SPIFFS.end()
                Serial.println("Start updating " + type);
                })
                .onEnd([]() {
                Serial.println("\nEnd");
                })
                .onProgress([](unsigned int progress, unsigned int total) {
                Serial.printf("Progress: %u%%\r", (progress / (total / 100)));
                })
                .onError([](ota_error_t error) {
                Serial.printf("Error[%u]: ", error);
                if (error == OTA_AUTH_ERROR) Serial.println("Auth Failed");
                else if (error == OTA_BEGIN_ERROR) Serial.println("Begin Failed");
                else if (error == OTA_CONNECT_ERROR) Serial.println("Connect Failed");
                else if (error == OTA_RECEIVE_ERROR) Serial.println("Receive Failed");
                else if (error == OTA_END_ERROR) Serial.println("End Failed");
                });

            ArduinoOTA.begin();

            Serial.println("connected...yeey :)");
        };

        void reset(){
            WiFiManager wifiManager;
            if (!wifiManager.startConfigPortal(_APName)) {
                Serial.println("failed to connect and hit timeout");
                delay(3000);
                ESP.restart();
                delay(5000);
            }
            Serial.println("connected...yeey :)");
        };

        void handle(){
            ArduinoOTA.handle();
        };
    private:
        char* _APName = "OnDemandAP";
};

#endif