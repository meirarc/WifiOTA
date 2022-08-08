# ⚙ WifiOTA

Library to Arduino IDE and Platform IO to do a Wifi connection integrated with Over The Air (OTA) updates for ESP32.

How does OTA Web Updater Work?
- The first sketch should be uploaded via serial port. This sketch should contain the code to create the OTA Web Updater, so that you are able to upload code later using your browser.
- The OTA Web Updater sketch creates a web server you can access to upload a new sketch via web browser.
- Then, you need to implement OTA routines in every sketch you upload, so that you’re able to do the next updates/uploads over-the-air.
- If you upload a code without a OTA routine you’ll no longer be able to access the web server and upload a new sketch over-the-air.

## ⚡ Install

1. Download the code
2. Add the folder under `Arduino/libraries`
3. Add the additional libraries below under `Arduino/libraries`

    * https://github.com/zhouhan0126/WIFIMANAGER-ESP32.git
    * https://github.com/zhouhan0126/DNSServer---esp32.git
    * https://github.com/zhouhan0126/WebServer-esp32.git

4. Restart Arduino IDE

## 🔧 Library details

Public functions:

- `void begin()`

    Initiate the connection and OTA setup

- `void handle()`

    lookup for OTA updates

- `void reset()`

    Reset the wifi saved and enter on the configuration AP module

## 🖌 Example

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

## 🙋‍♂️ Support & Contributing

Contributions are welcome! Feel free to open an issue or submit a pull request if you have a way to improve this project.

Make sure your request is meaningful and you have tested the app locally before submitting a pull request.

💙 If you like this project, give it a ⭐ and share it with friends!
