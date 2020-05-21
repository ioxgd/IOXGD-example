#include <IOXGD.h>
#include <PubSubClient.h>

extern lv_obj_t* temp;
extern lv_obj_t* humi;
extern lv_obj_t* chart1;
extern lv_obj_t* lamp;

extern lv_obj_t* loadingBox;

WiFiClient wifiClient;
PubSubClient client(wifiClient);

lv_chart_series_t *ser1;
lv_chart_series_t *ser2;

void callback(char* topic, byte* payload, unsigned int length) {
  Serial.print("Message arrived [");
  Serial.print(topic);
  Serial.print("] ");
  String strTopic = topic;
  String strPayload;
  for (int i = 0; i < length; i++) {
    Serial.print((char)payload[i]);
    strPayload += (char)payload[i];
  }
  Serial.println();

  if (strTopic == "@msg/temp") {
    label_set_text(temp, strPayload);
    lv_chart_set_next(chart1, ser1, strPayload.toFloat());
  } else if (strTopic == "@msg/humi") {
    label_set_text(humi, strPayload);
    lv_chart_set_next(chart1, ser2, strPayload.toFloat());
  } else if (strTopic == "@msg/led") {
    switch_set_value(lamp, strPayload == "1");
  }
}

void reconnect() {
  // Loop until we're reconnected
  while (!client.connected()) {
    Serial.print("Attempting MQTT connection...");
    // Attempt to connect
    if (client.connect("64bb32c4-de89-40a0-a647-2885fca8fb2d", "SFiBPmwT7j3SJXg9C8RbfaSD9avG7DAV", "L_m6joH1JDx3pDsirzxTS7XZ*kdfn~Lb")) {
      Serial.println("connected");
      client.subscribe("@msg/temp");
      client.subscribe("@msg/humi");
      client.subscribe("@msg/led");
    } else {
      Serial.print("failed, rc=");
      Serial.print(client.state());
      Serial.println(" try again in 5 seconds");
      // Wait 5 seconds before retrying
      delay(5000);
    }
  }
}

bool lampPushFlag = false;

void lamp_on_value() {
  lampPushFlag = true;
}

void setup() {
  Serial.begin(115200);

  gd.begin(SETUP_LVGL);

  xTaskCreate([](void*) {
    // put your setup code here, to run once:
    load_page();

    object_set_hidden(loadingBox, false);

    lv_chart_set_series_width(chart1, 8);
    lv_chart_set_point_count(chart1, 30);

    ser1 = lv_chart_add_series(chart1, lv_color_hex(0x1ABC9C));
    ser2 = lv_chart_add_series(chart1, lv_color_hex(0xF1C40F));

    label_set_text(temp, "LOAD");
    label_set_text(humi, "LOAD");

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

    switch_set_on_value(lamp, lamp_on_value);

    while (1) {
      if (lampPushFlag) {
        Serial.println("Start push");
        char txt[2] = { 0, 0 };
        txt[0] = switch_get_value(lamp) ? '1' : '0';
        Serial.print("Lamp: ");
        Serial.println(txt);
        client.publish("@msg/led", txt);
        lampPushFlag = false;
      }

      if (!client.connected()) {
        object_set_hidden(loadingBox, false);
        reconnect();
      } else {
        object_set_hidden(loadingBox, true);
      }
      client.loop();

      delay(10);
    }
  }, "mainTask", 1024, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() { }
