#include <IOXGD.h>

void setup() {
  Serial.begin(115200);
  
  RTC.begin();
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
