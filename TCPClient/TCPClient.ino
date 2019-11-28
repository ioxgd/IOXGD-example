#include <IOXGD.h>

WiFiClient client;

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

  Serial.println("connecting...");
  
  if (client.connect("192.168.1.7", 8080)) {
    Serial.println("connected");
    client.println("GET /search?q=arduino HTTP/1.0");
    client.println();
  } else {
    Serial.println("connection failed");
  }
}

void loop()
{
  if (client.available()) {
    char c = client.read();
    Serial.print(c);
  }

  if (!client.connected()) {
    Serial.println();
    Serial.println("disconnecting.");
    client.stop();
    for(;;)
      ;
  }
}
