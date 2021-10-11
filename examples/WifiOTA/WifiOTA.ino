/**
 * @file WifiOTA.ino
 * @author meirarc
 * @brief 
 *    To use the WIFI and OTA library use the additional libraries below are needed:
 *        https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git
 *        https://github.com/zhouhan0126/DNSServer---esp32.git
 *        https://github.com/zhouhan0126/WebServer-esp32.git
 *
 * @version 0.1
 * @date 2021-10-11
 * 
 * @copyright Copyright (c) 2021 
 */

#include <WifiOTA.h>

#define TRIGGER_PIN 0

WifiOTA wifi;

void setup() {
  Serial.begin(9200);
  pinMode(TRIGGER_PIN, INPUT);

  wifi.begin();
}

void loop() {
  wifi.handle();
  if ( digitalRead(TRIGGER_PIN) == LOW ) {
    wifi.reset();
  }
}