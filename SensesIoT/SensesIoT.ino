#include <IOXGD.h>
#include "Senses_wifi.h"

#define WIFI_NAME "MaxHome3BB"
#define WIFI_PASS "987654321"
#define SENSES_UID "120"
#define SENSES_KEY "dj4bnndq310w"

Senses_wifi myiot;

void setup() {
  Serial.begin(115200);
  gd.begin(SETUP_LVGL);
  ESP32.begin();

  WiFi.connect(WIFI_NAME, WIFI_PASS);

  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print('.');
    delay(500);
  }
  Serial.println("Connected");

  myiot.connect(SENSES_UID, SENSES_KEY);
}

void loop() {
  int n = random(0, 100);
  Serial.print("Send ");
  Serial.print(n);
  Serial.print(" to SENSES IoT...");
  if (myiot.send(1, n)) { // Send n into slot data 1
    Serial.print("OK !");
  } else {
    Serial.print("fail, error code ");
    Serial.print(HTTP.httpCode);
  }
  Serial.println();
  delay(10000);
}
