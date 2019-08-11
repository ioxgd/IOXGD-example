#include <IOXGD.h>
#include <lvgl.h>

#define BUZZER_PIN 8

static void event_handler(lv_obj_t * obj, lv_event_t event) {
  if (event == LV_EVENT_VALUE_CHANGED) {
    uint8_t value = lv_slider_get_value(obj);
    Serial.print("Value: ");
    Serial.println(value);

    tone(BUZZER_PIN, map(value, 0, 100, 100, 5E3));
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  gd.setupLittlevGL();

  lv_obj_t *slider = lv_slider_create(lv_scr_act(), NULL);
  lv_obj_set_size(slider, 600, 100);
  lv_obj_align(slider, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_obj_set_event_cb(slider, event_handler);
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}
