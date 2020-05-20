#include <IOXGD.h>
#include <PubSubClient.h>

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
  }
  Serial.println();
}

WiFiClient wifiClient;
PubSubClient client(wifiClient);

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("64bb32c4-de89-40a0-a647-2885fca8fb2d", "SFiBPmwT7j3SJXg9C8RbfaSD9avG7DAV", "L_m6joH1JDx3pDsirzxTS7XZ*kdfn~Lb")) {
      Serial.println("connected");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

void setup() {
  Serial.begin(115200);

  ESP32.begin();
  WiFi.connect("MaxHome3BB", "987654321");

  Serial.print("Connect");
  while (!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");

  client.setServer("mqtt.netpie.io", 1883);
  client.setCallback(callback);
}

void loop() {
  int humidity = random(1, 100);
  int temperature = random(1, 100);
  if (!client.connected()) {
    reconnect();
  }
  client.loop();
  String data = "{\"data\": {\"humidity\":" + String(humidity) + ", \"temperature\":" +
                String(temperature) + "}}";
  Serial.println(data);
  client.publish("@shadow/data/update", data.c_str());
  delay(2000);
}
