#include <IOXGD.h>
#include "Senses_wifi.h"

#define WIFI_NAME "MaxHome3BB"
#define WIFI_PASS "987654321"
#define SENSES_UID "120"
#define SENSES_KEY "dj4bnndq310w"

Senses_wifi myiot;

extern lv_obj_t* txtStatus;
extern lv_obj_t* slider;
extern lv_obj_t* txtValue;

int sendData = -1;

void send_handler(lv_obj_t * obj, lv_event_t event) {
  if(event == LV_EVENT_CLICKED) {
    sendData = lv_slider_get_value(slider);
  }
}

void slider_handler(lv_obj_t * obj, lv_event_t event) {
  if(event == LV_EVENT_VALUE_CHANGED) {
    char buf[4];
    snprintf(buf, 4, "%u", lv_slider_get_value(slider));
    lv_label_set_text(txtValue, buf);
  }
}

void setup() {
  Serial.begin(115200);
  gd.begin(SETUP_LVGL);
  ESP32.begin();

  load_page();

  xTaskCreate([](void*) {
    WiFi.connect(WIFI_NAME, WIFI_PASS);

    lv_label_set_text(txtStatus, "WiFi Connecting");
    Serial.print("Connect");
    while(!WiFi.isConnected()) {
      Serial.print('.');
      delay(500);
    }
    Serial.println("Connected");
    lv_label_set_text(txtStatus, "WiFi Connected");

    myiot.connect(SENSES_UID, SENSES_KEY);

    while(1) {
      if (sendData == -1) {
        delay(50);
        continue;
      }
      
      lv_label_set_text(txtStatus, "Sending");
      Serial.print("Send ");
      Serial.print(sendData);
      Serial.print(" to SENSES IoT...");
      if (myiot.send(1, sendData)) { // Send value in sendData into slot data 1
        Serial.print("OK !");
      } else {
        Serial.print("fail, error code ");
        Serial.print(HTTP.httpCode);
      }
      Serial.println();
      lv_label_set_text(txtStatus, "Send OK!");
      
      sendData = -1;
    }
  }, "wifiTask", 512, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() {

}
