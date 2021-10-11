/**
 * @file WifiOTA.cpp
 * @author meirarc
 * @brief Wifi Manager and OTA update library
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021
 * 
 */
#include <WifiOTA.h>

/**
 * @brief begin(). to initiate the Wifi and OTA setup
 * 
 */
void WifiOTA::begin(){
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
}

/**
 * @brief reset(). to reset the wifi network.
 * 
 */
void WifiOTA::reset(){
    WiFiManager wifiManager;
    if (!wifiManager.startConfigPortal(_APName)) {
        Serial.println("failed to connect and hit timeout");
        delay(3000);
        ESP.restart();
        delay(5000);
    }
    Serial.println("connected...yeey :)");
}

/**
 * @brief handle(). to be added on the loop() to trigger OTA updates.
 * 
 */
void WifiOTA::handle(){
    ArduinoOTA.handle();
}
  