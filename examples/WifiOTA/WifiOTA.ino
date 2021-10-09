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
