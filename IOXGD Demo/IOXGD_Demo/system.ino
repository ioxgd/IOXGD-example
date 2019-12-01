/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* systemScreen;
lv_obj_t* txt9;

void system_page() {
  systemScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x28B463);
  style_screen.body.grad_color = lv_color_hex(0x28B463);
  lv_obj_set_style(systemScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xFFFFFF);
  txt1_style.text.font = &supermarket_60;
  
  lv_obj_t* txt1 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "ข้อมูลระบบ");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);
  /* ====== END of txt1 ====== */
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0x1D8348);
  btn1_rel_style.body.grad_color = lv_color_hex(0x1D8348);
  btn1_rel_style.body.radius = 0;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x186A3B);
  btn1_pr_style.body.grad_color = lv_color_hex(0x186A3B);
  btn1_pr_style.body.radius = 0;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  lv_obj_t* btn1 = lv_btn_create(systemScreen, NULL);
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
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_30;
  
  lv_obj_t* txt2 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "ตัวประมวลผล");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 140);
  /* ====== END of txt2 ====== */
  
  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0xFFFFFF);
  txt3_style.text.font = &supermarket_30;
  
  lv_obj_t* txt3 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt3, "WiFi");
  lv_obj_set_size(txt3, 0, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 190);
  /* ====== END of txt3 ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0xFFFFFF);
  txt4_style.text.font = &supermarket_30;
  
  lv_obj_t* txt4 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt4, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txt4, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt4, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt4, "เวลาปัจจุบัน");
  lv_obj_set_size(txt4, 0, 0);
  lv_obj_align(txt4, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 240);
  /* ====== END of txt4 ====== */
  
  /* ========== txt5 ========== */
  static lv_style_t txt5_style;
  lv_style_copy(&txt5_style, &lv_style_plain);
  txt5_style.text.color = lv_color_hex(0xFFFFFF);
  txt5_style.text.font = &supermarket_30;
  
  lv_obj_t* txt5 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt5, LV_LABEL_STYLE_MAIN, &txt5_style);
  lv_label_set_long_mode(txt5, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt5, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt5, "MicroSD Card");
  lv_obj_set_size(txt5, 0, 0);
  lv_obj_align(txt5, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 290);
  /* ====== END of txt5 ====== */
  
  /* ========== txt6 ========== */
  static lv_style_t txt6_style;
  lv_style_copy(&txt6_style, &lv_style_plain);
  txt6_style.text.color = lv_color_hex(0xFFFFFF);
  txt6_style.text.font = &supermarket_30;
  
  lv_obj_t* txt6 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt6, LV_LABEL_STYLE_MAIN, &txt6_style);
  lv_label_set_long_mode(txt6, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt6, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt6, "รุ่น");
  lv_obj_set_size(txt6, 0, 0);
  lv_obj_align(txt6, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 390);
  /* ====== END of txt6 ====== */
  
  /* ========== txt7 ========== */
  static lv_style_t txt7_style;
  lv_style_copy(&txt7_style, &lv_style_plain);
  txt7_style.text.color = lv_color_hex(0xFFFFFF);
  txt7_style.text.font = &supermarket_30;
  
  lv_obj_t* txt7 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt7, LV_LABEL_STYLE_MAIN, &txt7_style);
  lv_label_set_long_mode(txt7, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt7, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt7, "Kendryte K210, RISC-V");
  lv_obj_set_size(txt7, 0, 0);
  lv_obj_align(txt7, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 140);
  /* ====== END of txt7 ====== */
  
  /* ========== txt8 ========== */
  static lv_style_t txt8_style;
  lv_style_copy(&txt8_style, &lv_style_plain);
  txt8_style.text.color = lv_color_hex(0xFFFFFF);
  txt8_style.text.font = &supermarket_30;
  
  lv_obj_t* txt8 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt8, LV_LABEL_STYLE_MAIN, &txt8_style);
  lv_label_set_long_mode(txt8, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt8, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt8, "ESP32, WiFi+Bluetooth");
  lv_obj_set_size(txt8, 0, 0);
  lv_obj_align(txt8, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 190);
  /* ====== END of txt8 ====== */
  
  /* ========== txt9 ========== */
  static lv_style_t txt9_style;
  lv_style_copy(&txt9_style, &lv_style_plain);
  txt9_style.text.color = lv_color_hex(0xFFFFFF);
  txt9_style.text.font = &supermarket_30;
  
  txt9 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt9, LV_LABEL_STYLE_MAIN, &txt9_style);
  lv_label_set_long_mode(txt9, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt9, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt9, "30/11/2562 10:59:00");
  lv_obj_set_size(txt9, 0, 0);
  lv_obj_align(txt9, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 240);
  /* ====== END of txt9 ====== */
  
  /* ========== txt10 ========== */
  static lv_style_t txt10_style;
  lv_style_copy(&txt10_style, &lv_style_plain);
  txt10_style.text.color = lv_color_hex(0xFFFFFF);
  txt10_style.text.font = &supermarket_30;
  
  lv_obj_t* txt10 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt10, LV_LABEL_STYLE_MAIN, &txt10_style);
  lv_label_set_long_mode(txt10, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt10, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt10, "Yes");
  lv_obj_set_size(txt10, 0, 0);
  lv_obj_align(txt10, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 290);
  /* ====== END of txt10 ====== */
  
  /* ========== txt11 ========== */
  static lv_style_t txt11_style;
  lv_style_copy(&txt11_style, &lv_style_plain);
  txt11_style.text.color = lv_color_hex(0xFFFFFF);
  txt11_style.text.font = &supermarket_30;
  
  lv_obj_t* txt11 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt11, LV_LABEL_STYLE_MAIN, &txt11_style);
  lv_label_set_long_mode(txt11, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt11, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt11, "EEPROM");
  lv_obj_set_size(txt11, 0, 0);
  lv_obj_align(txt11, NULL, LV_ALIGN_IN_TOP_LEFT, 70, 340);
  /* ====== END of txt11 ====== */
  
  /* ========== txt12 ========== */
  static lv_style_t txt12_style;
  lv_style_copy(&txt12_style, &lv_style_plain);
  txt12_style.text.color = lv_color_hex(0xFFFFFF);
  txt12_style.text.font = &supermarket_30;
  
  lv_obj_t* txt12 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt12, LV_LABEL_STYLE_MAIN, &txt12_style);
  lv_label_set_long_mode(txt12, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt12, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt12, "มี");
  lv_obj_set_size(txt12, 0, 0);
  lv_obj_align(txt12, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 340);
  /* ====== END of txt12 ====== */
  
  /* ========== txt13 ========== */
  static lv_style_t txt13_style;
  lv_style_copy(&txt13_style, &lv_style_plain);
  txt13_style.text.color = lv_color_hex(0xFFFFFF);
  txt13_style.text.font = &supermarket_30;
  
  lv_obj_t* txt13 = lv_label_create(systemScreen, NULL);
  lv_label_set_style(txt13, LV_LABEL_STYLE_MAIN, &txt13_style);
  lv_label_set_long_mode(txt13, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt13, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt13, "IOXGD4");
  lv_obj_set_size(txt13, 0, 0);
  lv_obj_align(txt13, NULL, LV_ALIGN_IN_TOP_LEFT, 270, 390);
  /* ====== END of txt13 ====== */

  xTaskCreate([](void*) {
    RTC.begin();
    char datetime[64];
    
    while (1) {
      if (RTC.get()) {
        sprintf(datetime, "%02d:%02d:%02d %d/%d/%d", RTC.hour(), RTC.minute(), RTC.second(), RTC.day(), RTC.month(), RTC.year());
        lv_label_set_text(txt9, datetime);
      } else {
        lv_label_set_text(txt9, "RTC Error !");
      }
      delay(1000);
    }
  }, "rtcTask", 512, NULL, 1, NULL);
}
