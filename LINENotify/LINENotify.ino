#include <IOXGD.h>
#include <LINE.h>

#define LINE_TOKEN "LD5yNaFsUgeFGBlw4J6KJxTwJ3DuhJdb0CCWo3AAqDG"

void setup() {
  Serial.begin(115200);
  
  ESP32.begin();
  WiFi.connect("e-tech good net", "987654321");
  
  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");

  LINE.setToken(LINE_TOKEN);
}

void loop() {
  Serial.print("Send notify...");
  if (LINE.notify("สวัสดีจ้า")) {
    Serial.print("OK !");
  } else {
    Serial.print("fail");
  }
  Serial.println();
  delay(30000);
}
