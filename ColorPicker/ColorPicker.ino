#include <IOXGD.h>
#include <lvgl.h>
#include <Wire.h>

#define BUZZER_PIN 37

bool trigBeep = false;
bool beeping = false;

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  Wire.begin();
  Wire.setClock(100E3);
  
  gd.setupLittlevGL();

  static lv_style_t style_bg1;
  lv_style_copy(&style_bg1, &lv_style_plain_color);
  style_bg1.body.main_color = LV_COLOR_MAKE(22, 160, 133);
  style_bg1.body.grad_color = LV_COLOR_MAKE(22, 160, 133);

  static lv_style_t style_bg2;
  lv_style_copy(&style_bg2, &lv_style_plain_color);
  style_bg2.body.main_color = LV_COLOR_MAKE(39, 174, 96);
  style_bg2.body.grad_color = LV_COLOR_MAKE(39, 174, 96);

  static lv_style_t style_bg3;
  lv_style_copy(&style_bg3, &lv_style_plain_color);
  style_bg3.body.main_color = LV_COLOR_MAKE(41, 128, 185);
  style_bg3.body.grad_color = LV_COLOR_MAKE(41, 128, 185);

  static lv_style_t style_bg4;
  lv_style_copy(&style_bg4, &lv_style_plain_color);
  style_bg4.body.main_color = LV_COLOR_MAKE(142, 68, 173);
  style_bg4.body.grad_color = LV_COLOR_MAKE(142, 68, 173);

  static lv_style_t style_bg5;
  lv_style_copy(&style_bg5, &lv_style_plain_color);
  style_bg5.body.main_color = LV_COLOR_MAKE(44, 62, 80);
  style_bg5.body.grad_color = LV_COLOR_MAKE(44, 62, 80);

  static lv_style_t style_bg6;
  lv_style_copy(&style_bg6, &lv_style_plain_color);
  style_bg6.body.main_color = LV_COLOR_MAKE(241, 196, 15);
  style_bg6.body.grad_color = LV_COLOR_MAKE(241, 196, 15);

  static lv_style_t style_bg7;
  lv_style_copy(&style_bg7, &lv_style_plain_color);
  style_bg7.body.main_color = LV_COLOR_MAKE(230, 126, 34);
  style_bg7.body.grad_color = LV_COLOR_MAKE(230, 126, 34);

  static lv_style_t style_bg8;
  lv_style_copy(&style_bg8, &lv_style_plain_color);
  style_bg8.body.main_color = LV_COLOR_MAKE(231, 76, 60);
  style_bg8.body.grad_color = LV_COLOR_MAKE(231, 76, 60);

  static lv_style_t style_bg9;
  lv_style_copy(&style_bg9, &lv_style_plain_color);
  style_bg9.body.main_color = LV_COLOR_MAKE(236, 240, 241);
  style_bg9.body.grad_color = LV_COLOR_MAKE(236, 240, 241);

  static lv_style_t style_bg10;
  lv_style_copy(&style_bg10, &lv_style_plain_color);
  style_bg10.body.main_color = LV_COLOR_MAKE(149, 165, 166);
  style_bg10.body.grad_color = LV_COLOR_MAKE(149, 165, 166);

  lv_obj_t *obj1;
  obj1 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj1, 200, 240);
  lv_obj_set_style(obj1, &style_bg1);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  lv_obj_set_event_cb(obj1, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0x16a085);
    }
  });

  lv_obj_t *obj2;
  obj2 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj2, 200, 240);
  lv_obj_set_style(obj2, &style_bg2);
  lv_obj_align(obj2, NULL, LV_ALIGN_IN_TOP_LEFT, 200, 0);
  lv_obj_set_event_cb(obj2, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0x27ae60);
    }
  });

  lv_obj_t *obj3;
  obj3 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj3, 200, 240);
  lv_obj_set_style(obj3, &style_bg3);
  lv_obj_align(obj3, NULL, LV_ALIGN_IN_TOP_LEFT, 400, 0);
  lv_obj_set_event_cb(obj3, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0x2980b9);
    }
  });

  lv_obj_t *obj4;
  obj4 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj4, 200, 240);
  lv_obj_set_style(obj4, &style_bg4);
  lv_obj_align(obj4, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 0);
  lv_obj_set_event_cb(obj4, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0x8e44ad);
    }
  });

  lv_obj_t *obj6;
  obj6 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj6, 200, 240);
  lv_obj_set_style(obj6, &style_bg6);
  lv_obj_align(obj6, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 240);
  lv_obj_set_event_cb(obj6, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0xf1c40f);
    }
  });

  lv_obj_t *obj7;
  obj7 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj7, 200, 240);
  lv_obj_set_style(obj7, &style_bg7);
  lv_obj_align(obj7, NULL, LV_ALIGN_IN_TOP_LEFT, 200, 240);
  lv_obj_set_event_cb(obj7, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0xe67e22);
    }
  });

  lv_obj_t *obj8;
  obj8 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj8, 200, 240);
  lv_obj_set_style(obj8, &style_bg8);
  lv_obj_align(obj8, NULL, LV_ALIGN_IN_TOP_LEFT, 400, 240);
  lv_obj_set_event_cb(obj8, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0xe74c3c);
    }
  });

  lv_obj_t *obj9;
  obj9 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_size(obj9, 200, 240);
  lv_obj_set_style(obj9, &style_bg9);
  lv_obj_align(obj9, NULL, LV_ALIGN_IN_TOP_LEFT, 600, 240);
  lv_obj_set_event_cb(obj9, [](lv_obj_t * obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      trigBeep = true;
      setColor(0xecf0f1);
    }
  });
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);

  static uint32_t timer = millis();
  if (trigBeep) {
    if (!beeping) {
      tone(BUZZER_PIN, 4E3);
      beeping = true;
      timer = millis();
    } else {
      if ((millis() - timer) > 50) {
        noTone(BUZZER_PIN);
        beeping = false;
        trigBeep = false;
      }
    }
  }
}
