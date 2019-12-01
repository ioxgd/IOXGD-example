/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* gpioScreen;

void gpio_page() {
  gpioScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xE67E22);
  style_screen.body.grad_color = lv_color_hex(0xE67E22);
  lv_obj_set_style(gpioScreen, &style_screen);
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0xCA6F1E);
  btn1_rel_style.body.grad_color = lv_color_hex(0xCA6F1E);
  btn1_rel_style.body.radius = 0;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x935116);
  btn1_pr_style.body.grad_color = lv_color_hex(0x935116);
  btn1_pr_style.body.radius = 0;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  lv_obj_t* btn1 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn1, event_handler); // TODO
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 120, 80);
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
  lv_obj_set_event_cb(btn1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(homeScreen);
      gd.beep();
    }
  });
  
  static lv_style_t btn1_label_style;
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_30;
  lv_obj_t* btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "< Back");
  /* ====== END of btn1 ====== */
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xFFFFFF);
  txt1_style.text.font = &supermarket_60;
  
  lv_obj_t* txt1 = lv_label_create(gpioScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "GPIO Control");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt1 ====== */
  
  /* ========== btn2 ========== */
  static lv_style_t btn2_rel_style;
  lv_style_copy(&btn2_rel_style, &lv_style_plain);
  btn2_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn2_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn2_rel_style.body.radius = 20;
  btn2_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn2_rel_style.body.border.width = 6;
  
  static lv_style_t btn2_pr_style;
  lv_style_copy(&btn2_pr_style, &lv_style_plain);
  btn2_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn2_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn2_pr_style.body.radius = 20;
  btn2_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn2_pr_style.body.border.width = 6;
  
  lv_obj_t* btn2 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn2, event_handler); // TODO
  lv_btn_set_style(btn2, LV_BTN_STATE_REL, &btn2_rel_style);
  lv_btn_set_style(btn2, LV_BTN_STATE_PR, &btn2_pr_style);
  lv_obj_set_size(btn2, 120, 120);
  lv_obj_align(btn2, NULL, LV_ALIGN_CENTER, -210, -20);
  lv_btn_set_toggle(btn2, true);
  lv_obj_set_event_cb(btn2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(9, HIGH);
      } else {
        digitalWrite(9, LOW);
      }
    }
  });
  
  static lv_style_t btn2_label_style;
  lv_style_copy(&btn2_label_style, &lv_style_plain);
  btn2_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn2_label_style.text.font = &supermarket_60;
  lv_obj_t* btn2_label = lv_label_create(btn2, NULL);
  lv_label_set_style(btn2_label, LV_LABEL_STYLE_MAIN, &btn2_label_style);
  lv_label_set_text(btn2_label, "9");
  /* ====== END of btn2 ====== */
  
  /* ========== btn3 ========== */
  static lv_style_t btn3_rel_style;
  lv_style_copy(&btn3_rel_style, &lv_style_plain);
  btn3_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn3_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn3_rel_style.body.radius = 20;
  btn3_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn3_rel_style.body.border.width = 6;
  
  static lv_style_t btn3_pr_style;
  lv_style_copy(&btn3_pr_style, &lv_style_plain);
  btn3_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn3_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn3_pr_style.body.radius = 20;
  btn3_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn3_pr_style.body.border.width = 6;
  
  lv_obj_t* btn3 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn3, event_handler); // TODO
  lv_btn_set_style(btn3, LV_BTN_STATE_REL, &btn3_rel_style);
  lv_btn_set_style(btn3, LV_BTN_STATE_PR, &btn3_pr_style);
  lv_obj_set_size(btn3, 120, 120);
  lv_obj_align(btn3, NULL, LV_ALIGN_CENTER, -70, -20);
  lv_btn_set_toggle(btn3, true);
  lv_obj_set_event_cb(btn3, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(11, HIGH);
      } else {
        digitalWrite(11, LOW);
      }
    }
  });
  
  static lv_style_t btn3_label_style;
  lv_style_copy(&btn3_label_style, &lv_style_plain);
  btn3_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn3_label_style.text.font = &supermarket_60;
  lv_obj_t* btn3_label = lv_label_create(btn3, NULL);
  lv_label_set_style(btn3_label, LV_LABEL_STYLE_MAIN, &btn3_label_style);
  lv_label_set_text(btn3_label, "11");
  /* ====== END of btn3 ====== */
  
  /* ========== btn4 ========== */
  static lv_style_t btn4_rel_style;
  lv_style_copy(&btn4_rel_style, &lv_style_plain);
  btn4_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn4_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn4_rel_style.body.radius = 20;
  btn4_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn4_rel_style.body.border.width = 6;
  
  static lv_style_t btn4_pr_style;
  lv_style_copy(&btn4_pr_style, &lv_style_plain);
  btn4_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn4_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn4_pr_style.body.radius = 20;
  btn4_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn4_pr_style.body.border.width = 6;
  
  lv_obj_t* btn4 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn4, event_handler); // TODO
  lv_btn_set_style(btn4, LV_BTN_STATE_REL, &btn4_rel_style);
  lv_btn_set_style(btn4, LV_BTN_STATE_PR, &btn4_pr_style);
  lv_obj_set_size(btn4, 120, 120);
  lv_obj_align(btn4, NULL, LV_ALIGN_CENTER, 70, -20);
  lv_btn_set_toggle(btn4, true);
  lv_obj_set_event_cb(btn4, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(13, HIGH);
      } else {
        digitalWrite(13, LOW);
      }
    }
  });
  
  static lv_style_t btn4_label_style;
  lv_style_copy(&btn4_label_style, &lv_style_plain);
  btn4_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn4_label_style.text.font = &supermarket_60;
  lv_obj_t* btn4_label = lv_label_create(btn4, NULL);
  lv_label_set_style(btn4_label, LV_LABEL_STYLE_MAIN, &btn4_label_style);
  lv_label_set_text(btn4_label, "13");
  /* ====== END of btn4 ====== */
  
  /* ========== btn5 ========== */
  static lv_style_t btn5_rel_style;
  lv_style_copy(&btn5_rel_style, &lv_style_plain);
  btn5_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn5_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn5_rel_style.body.radius = 20;
  btn5_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn5_rel_style.body.border.width = 6;
  
  static lv_style_t btn5_pr_style;
  lv_style_copy(&btn5_pr_style, &lv_style_plain);
  btn5_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn5_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn5_pr_style.body.radius = 20;
  btn5_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn5_pr_style.body.border.width = 6;
  
  lv_obj_t* btn5 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn5, event_handler); // TODO
  lv_btn_set_style(btn5, LV_BTN_STATE_REL, &btn5_rel_style);
  lv_btn_set_style(btn5, LV_BTN_STATE_PR, &btn5_pr_style);
  lv_obj_set_size(btn5, 120, 120);
  lv_obj_align(btn5, NULL, LV_ALIGN_CENTER, 210, -20);
  lv_btn_set_toggle(btn5, true);
  lv_obj_set_event_cb(btn5, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(15, HIGH);
      } else {
        digitalWrite(15, LOW);
      }
    }
  });
  
  static lv_style_t btn5_label_style;
  lv_style_copy(&btn5_label_style, &lv_style_plain);
  btn5_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn5_label_style.text.font = &supermarket_60;
  lv_obj_t* btn5_label = lv_label_create(btn5, NULL);
  lv_label_set_style(btn5_label, LV_LABEL_STYLE_MAIN, &btn5_label_style);
  lv_label_set_text(btn5_label, "15");
  /* ====== END of btn5 ====== */
  
  /* ========== btn6 ========== */
  static lv_style_t btn6_rel_style;
  lv_style_copy(&btn6_rel_style, &lv_style_plain);
  btn6_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn6_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn6_rel_style.body.radius = 20;
  btn6_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn6_rel_style.body.border.width = 6;
  
  static lv_style_t btn6_pr_style;
  lv_style_copy(&btn6_pr_style, &lv_style_plain);
  btn6_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn6_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn6_pr_style.body.radius = 20;
  btn6_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn6_pr_style.body.border.width = 6;
  
  lv_obj_t* btn6 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn6, event_handler); // TODO
  lv_btn_set_style(btn6, LV_BTN_STATE_REL, &btn6_rel_style);
  lv_btn_set_style(btn6, LV_BTN_STATE_PR, &btn6_pr_style);
  lv_obj_set_size(btn6, 120, 120);
  lv_obj_align(btn6, NULL, LV_ALIGN_CENTER, -210, 120);
  lv_btn_set_toggle(btn6, true);
  lv_obj_set_event_cb(btn6, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(8, HIGH);
      } else {
        digitalWrite(8, LOW);
      }
    }
  });
  
  static lv_style_t btn6_label_style;
  lv_style_copy(&btn6_label_style, &lv_style_plain);
  btn6_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn6_label_style.text.font = &supermarket_60;
  lv_obj_t* btn6_label = lv_label_create(btn6, NULL);
  lv_label_set_style(btn6_label, LV_LABEL_STYLE_MAIN, &btn6_label_style);
  lv_label_set_text(btn6_label, "8");
  /* ====== END of btn6 ====== */
  
  /* ========== btn7 ========== */
  static lv_style_t btn7_rel_style;
  lv_style_copy(&btn7_rel_style, &lv_style_plain);
  btn7_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn7_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn7_rel_style.body.radius = 20;
  btn7_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn7_rel_style.body.border.width = 6;
  
  static lv_style_t btn7_pr_style;
  lv_style_copy(&btn7_pr_style, &lv_style_plain);
  btn7_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn7_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn7_pr_style.body.radius = 20;
  btn7_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn7_pr_style.body.border.width = 6;
  
  lv_obj_t* btn7 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn7, event_handler); // TODO
  lv_btn_set_style(btn7, LV_BTN_STATE_REL, &btn7_rel_style);
  lv_btn_set_style(btn7, LV_BTN_STATE_PR, &btn7_pr_style);
  lv_obj_set_size(btn7, 120, 120);
  lv_obj_align(btn7, NULL, LV_ALIGN_CENTER, -70, 120);
  lv_btn_set_toggle(btn7, true);
  lv_obj_set_event_cb(btn7, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(10, HIGH);
      } else {
        digitalWrite(10, LOW);
      }
    }
  });
  
  static lv_style_t btn7_label_style;
  lv_style_copy(&btn7_label_style, &lv_style_plain);
  btn7_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn7_label_style.text.font = &supermarket_60;
  lv_obj_t* btn7_label = lv_label_create(btn7, NULL);
  lv_label_set_style(btn7_label, LV_LABEL_STYLE_MAIN, &btn7_label_style);
  lv_label_set_text(btn7_label, "10");
  /* ====== END of btn7 ====== */
  
  /* ========== btn8 ========== */
  static lv_style_t btn8_rel_style;
  lv_style_copy(&btn8_rel_style, &lv_style_plain);
  btn8_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn8_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn8_rel_style.body.radius = 20;
  btn8_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn8_rel_style.body.border.width = 6;
  
  static lv_style_t btn8_pr_style;
  lv_style_copy(&btn8_pr_style, &lv_style_plain);
  btn8_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn8_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn8_pr_style.body.radius = 20;
  btn8_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn8_pr_style.body.border.width = 6;
  
  lv_obj_t* btn8 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn8, event_handler); // TODO
  lv_btn_set_style(btn8, LV_BTN_STATE_REL, &btn8_rel_style);
  lv_btn_set_style(btn8, LV_BTN_STATE_PR, &btn8_pr_style);
  lv_obj_set_size(btn8, 120, 120);
  lv_obj_align(btn8, NULL, LV_ALIGN_CENTER, 70, 120);
  lv_btn_set_toggle(btn8, true);
  lv_obj_set_event_cb(btn8, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(12, HIGH);
      } else {
        digitalWrite(12, LOW);
      }
    }
  });
  
  static lv_style_t btn8_label_style;
  lv_style_copy(&btn8_label_style, &lv_style_plain);
  btn8_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn8_label_style.text.font = &supermarket_60;
  lv_obj_t* btn8_label = lv_label_create(btn8, NULL);
  lv_label_set_style(btn8_label, LV_LABEL_STYLE_MAIN, &btn8_label_style);
  lv_label_set_text(btn8_label, "12");
  /* ====== END of btn8 ====== */
  
  /* ========== btn9 ========== */
  static lv_style_t btn9_rel_style;
  lv_style_copy(&btn9_rel_style, &lv_style_plain);
  btn9_rel_style.body.main_color = lv_color_hex(0x2ECC71);
  btn9_rel_style.body.grad_color = lv_color_hex(0x2ECC71);
  btn9_rel_style.body.radius = 20;
  btn9_rel_style.body.border.color = lv_color_hex(0x1D8348);
  btn9_rel_style.body.border.width = 6;
  
  static lv_style_t btn9_pr_style;
  lv_style_copy(&btn9_pr_style, &lv_style_plain);
  btn9_pr_style.body.main_color = lv_color_hex(0x1D8348);
  btn9_pr_style.body.grad_color = lv_color_hex(0x1D8348);
  btn9_pr_style.body.radius = 20;
  btn9_pr_style.body.border.color = lv_color_hex(0x1D8348);
  btn9_pr_style.body.border.width = 6;
  
  lv_obj_t* btn9 = lv_btn_create(gpioScreen, NULL);
  // lv_obj_set_event_cb(btn9, event_handler); // TODO
  lv_btn_set_style(btn9, LV_BTN_STATE_REL, &btn9_rel_style);
  lv_btn_set_style(btn9, LV_BTN_STATE_PR, &btn9_pr_style);
  lv_obj_set_size(btn9, 120, 120);
  lv_obj_align(btn9, NULL, LV_ALIGN_CENTER, 210, 120);
  lv_btn_set_toggle(btn9, true);
  lv_obj_set_event_cb(btn9, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      if (lv_btn_get_state(obj) == LV_BTN_STATE_TGL_REL) {
        digitalWrite(14, HIGH);
      } else {
        digitalWrite(14, LOW);
      }
    }
  });
  
  static lv_style_t btn9_label_style;
  lv_style_copy(&btn9_label_style, &lv_style_plain);
  btn9_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn9_label_style.text.font = &supermarket_60;
  lv_obj_t* btn9_label = lv_label_create(btn9, NULL);
  lv_label_set_style(btn9_label, LV_LABEL_STYLE_MAIN, &btn9_label_style);
  lv_label_set_text(btn9_label, "14");
  /* ====== END of btn9 ====== */

  pinMode(8, OUTPUT);
  pinMode(9, OUTPUT);
  pinMode(10, OUTPUT);
  pinMode(11, OUTPUT);
  pinMode(12, OUTPUT);
  pinMode(13, OUTPUT);
  pinMode(14, OUTPUT);
  pinMode(15, OUTPUT);
}
