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
}

void loop() {
  NTP.get();
  
  Serial.print("Datetime: ");
  Serial.print(NTP.hour());
  Serial.print(':');
  Serial.print(NTP.minute());
  Serial.print(':');
  Serial.print(NTP.second());
  Serial.print(' ');
  Serial.print(NTP.day());
  Serial.print('/');
  Serial.print(NTP.month());
  Serial.print('/');
  Serial.print(NTP.year());
  Serial.println();
  delay(1000);
}
