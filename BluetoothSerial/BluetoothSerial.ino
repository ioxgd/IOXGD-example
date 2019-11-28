#include <IOXGD.h>

void setup() {
  Serial.begin(115200);
  
  ESP32.begin();
  BT.begin("IOXGD4");
}

void loop() {
  if (BT.available()) {
    Serial.write(BT.read());
  }
  if (Serial.available()) {
    BT.write(Serial.read());
  }
  delay(1);
}
