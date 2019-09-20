#include <IOXGD.h>



void setup() {
  Serial.begin(115200);
  
  gd.begin();

  uint8_t i = EEPROM.read(0);
  EEPROM.write(0, i + 1);
}

void loop() {
  Serial.print("Value at 0 is ");
  Serial.println(EEPROM.read(0));
  delay(500);
}
