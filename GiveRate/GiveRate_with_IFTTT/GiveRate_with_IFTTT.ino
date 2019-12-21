#include <IOXGD.h>

int send_rate = 0;

extern lv_obj_t* txt7;
extern lv_obj_t* rate1;
extern lv_obj_t* rate2;
extern lv_obj_t* rate3;
extern lv_obj_t* rate4;
extern lv_obj_t* rate5;

void setup() {
  Serial.begin(115200);

  gd.begin(SETUP_LVGL);

  load_page();

  xTaskCreate([](void*) {
    ESP32.begin();
    WiFi.connect("MaxHome3BB", "987654321");

    lv_label_set_text(txt7, "กำลังเชื่อมต่อ WiFi");
    lv_obj_set_hidden(txt7, false);
    while (!WiFi.isConnected()) {
      Serial.print(".");
      delay(500);
    }
    Serial.println("Connected");
    lv_obj_set_hidden(txt7, true);

    while (1) {
      if (send_rate > 0) {
        lv_label_set_text(txt7, "กำลังบันทึกข้อมูล");
        lv_obj_set_hidden(txt7, false);
    
        HTTPHeader header[2] = {
          {
            .name = "Content-Type",
            .value = "application/json"
          }
        };
        HTTP.post("https://maker.ifttt.com/trigger/add_rate/with/key/dxRDSdcd-gWwkT5pW8gefs", "{\"value1\":\"สนธยา\",\"value2\":\"" + String(send_rate) + "\",\"value3\":\"0\"}", header, 1);
        HTTP.end();

        send_rate = 0;
        lv_obj_set_hidden(txt7, true);
      }
      delay(10);
    }
  }, "mainTask", 1024, NULL, 1, NULL);

  lv_obj_set_click(rate1, true);
  lv_obj_set_click(rate2, true);
  lv_obj_set_click(rate3, true);
  lv_obj_set_click(rate4, true);
  lv_obj_set_click(rate5, true);

  lv_obj_set_event_cb(rate1, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      send_rate = 1;
    }
  });

  lv_obj_set_event_cb(rate2, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      send_rate = 2;
    }
  });

  lv_obj_set_event_cb(rate3, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      send_rate = 3;
    }
  });

  lv_obj_set_event_cb(rate4, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      send_rate = 4;
    }
  });

  lv_obj_set_event_cb(rate5, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      send_rate = 5;
    }
  });

  gd.startFreeRTOS();
}

void loop() { }
