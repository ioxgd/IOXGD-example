#include <ESP32WiFi.h>
#include <ESP32HTTP.h>

void setup() {
  delay(2000);
  Serial.begin(115200);
  
  WiFi.begin();
  WiFi.connect("e-tech good net", "987654321");
  
  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");
}

void loop() {
  Serial.print("HTTP Get: ");
  Serial.println(HTTP.get("https://ioxhop.info/time.php"));
  delay(5000);
}