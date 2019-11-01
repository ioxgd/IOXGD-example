#include <IOXGD.h>

void setup() {
  Serial.begin(115200);
  
  WiFi.begin();
  WiFi.connect("e-tech good net", "987654321");
  
  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");

  NTP.begin(7);
  RTC.begin();

  if (RTC.syncFromNTP()) {
    Serial.println("Sync from NTP !");
  } else {
    Serial.println("Sync error");
  }
}

void loop() {
  if (RTC.get()) {
    Serial.print("Datetime: ");
    Serial.print(RTC.hour());
    Serial.print(':');
    Serial.print(RTC.minute());
    Serial.print(':');
    Serial.print(RTC.second());
    Serial.print(' ');
    Serial.print(RTC.day());
    Serial.print('/');
    Serial.print(RTC.month());
    Serial.print('/');
    Serial.print(RTC.year());
    Serial.println();
  } else {
    Serial.println("Error !");
  }
  delay(1000);
}
