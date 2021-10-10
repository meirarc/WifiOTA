# WifiOTA

Wifi connection integrated with Over The Air (OTA) updates for ESP32

## Install

1. Download the code
2. Add the folder under `Arduino/libraries`
3. Restart Arduino IDE

## Library details

Public functions:

- `WifiOTA(char* ssid, char* password)`

    Contructor, inform the `ssid` and wifi `password`to initiate the connection 

- `void begin()`

    Initiate the connection and OTA setup

- `void handle()`

    lookup for OTA updates

## Example

```c++
#include <WifiOTA.h>

char* ssid = "ssid";
char* password = "password";

WifiOTA wifi(ssid, password);

void setup() {
  Serial.begin(9600);
  wifi.begin();
}

void loop() {
  wifi.handle();
}
```
