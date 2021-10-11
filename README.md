# WifiOTA

Wifi connection integrated with Over The Air (OTA) updates for ESP32

## Install

1. Download the code
2. Add the folder under `Arduino/libraries`
3. Add the additional libraries below under `Arduino/libraries`

    * https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git
    * https://github.com/zhouhan0126/DNSServer---esp32.git
    * https://github.com/zhouhan0126/WebServer-esp32.git

4. Restart Arduino IDE

## Library details

Public functions:

- `void begin()`

    Initiate the connection and OTA setup

- `void handle()`

    lookup for OTA updates

- `void reset()`

    Reset the wifi saved and enter on the configuration AP module

## Example

```c++
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
```
