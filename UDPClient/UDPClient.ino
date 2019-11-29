#include <IOXGD.h>

WiFiUDP Udp;

void setup() {
  Serial.begin(115200);
  
  ESP32.begin();
  WiFi.connect("MaxHome3BB", "987654321");
  
  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");
  
  Udp.begin(8888);
}

void loop() {
  Udp.beginPacket("192.168.1.7", 999);
  Udp.println(millis() / 1000.0);
  Udp.endPacket();
  delay(500);
}
