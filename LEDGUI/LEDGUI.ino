#include <IOXGD.h>
#include <lvgl.h>

void setup() {
  fpioa_set_function(8, FUNC_GPIO0);
  fpioa_set_function(9, FUNC_GPIO1);
  fpioa_set_function(10, FUNC_GPIO2);
  fpioa_set_function(11, FUNC_GPIO3);
  gpio_set_drive_mode(0, GPIO_DM_OUTPUT);
  gpio_set_drive_mode(1, GPIO_DM_OUTPUT);
  gpio_set_drive_mode(2, GPIO_DM_OUTPUT);
  gpio_set_drive_mode(3, GPIO_DM_OUTPUT);

  Serial.begin(115200);
  gd.setupLittlevGL();

  lv_obj_t * label;
  
  lv_obj_t *btn1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btn1, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      Serial.println(lv_btn_get_state(obj) == 2);
      gpio_set_pin(0, lv_btn_get_state(obj) == 2 ? GPIO_PV_HIGH : GPIO_PV_LOW);
    }
  });
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_TOP_LEFT, 60, 60);
  lv_btn_set_toggle(btn1, true);
  label = lv_label_create(btn1, NULL);
  lv_label_set_text(label, "LED1");
  lv_obj_set_size(btn1, (800 / 2) - 60 - (60 / 2), (480 / 2) - 60 - (60 / 2));

  // LED2
  lv_obj_t * btn2 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btn2, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      Serial.println(lv_btn_get_state(obj) == 2);
      gpio_set_pin(1, lv_btn_get_state(obj) == 2 ? GPIO_PV_HIGH : GPIO_PV_LOW);
    }
  });
  lv_obj_align(btn2, NULL, LV_ALIGN_IN_TOP_LEFT, 400 + 30, 60);
  lv_btn_set_toggle(btn2, true);
  label = lv_label_create(btn2, NULL);
  lv_label_set_text(label, "LED2");
  lv_obj_set_size(btn2, (800 / 2) - 60 - (60 / 2), (480 / 2) - 60 - (60 / 2));

  // LED3
  lv_obj_t * btn3 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btn3, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      Serial.println(lv_btn_get_state(obj) == 2);
      gpio_set_pin(2, lv_btn_get_state(obj) == 2 ? GPIO_PV_HIGH : GPIO_PV_LOW);
    }
  });
  lv_obj_align(btn3, NULL, LV_ALIGN_IN_TOP_LEFT, 60, 240 + 30);
  lv_btn_set_toggle(btn3, true);
  label = lv_label_create(btn3, NULL);
  lv_label_set_text(label, "LED3");
  lv_obj_set_size(btn3, (800 / 2) - 60 - (60 / 2), (480 / 2) - 60 - (60 / 2));

  // LED4
  lv_obj_t * btn4 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btn4, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      Serial.println(lv_btn_get_state(obj) == 2);
      gpio_set_pin(3, lv_btn_get_state(obj) == 2 ? GPIO_PV_HIGH : GPIO_PV_LOW);
    }
  });
  lv_obj_align(btn4, NULL, LV_ALIGN_IN_TOP_LEFT, 400 + 30, 240 + 30);
  lv_btn_set_toggle(btn4, true);
  label = lv_label_create(btn4, NULL);
  lv_label_set_text(label, "LED4");
  lv_obj_set_size(btn4, (800 / 2) - 60 - (60 / 2), (480 / 2) - 60 - (60 / 2));
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}
