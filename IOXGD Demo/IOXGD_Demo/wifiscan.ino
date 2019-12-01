/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);
LV_FONT_DECLARE(supermarket_30);

lv_obj_t* wifiscanScreen;
lv_obj_t* txt2;

void wifiscan_page() {
  wifiscanScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x2C3E50);
  style_screen.body.grad_color = lv_color_hex(0x2C3E50);
  lv_obj_set_style(wifiscanScreen, &style_screen);
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0x273746);
  btn1_rel_style.body.grad_color = lv_color_hex(0x273746);
  btn1_rel_style.body.radius = 0;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x17202A);
  btn1_pr_style.body.grad_color = lv_color_hex(0x17202A);
  btn1_pr_style.body.radius = 0;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  lv_obj_t* btn1 = lv_btn_create(wifiscanScreen, NULL);
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
  
  lv_obj_t* txt1 = lv_label_create(wifiscanScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "WiFi Scan");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt1 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_30;
  
  txt2 = lv_label_create(wifiscanScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "Scaning...");
  lv_obj_set_size(txt2, 600, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_CENTER, 0, -120);
  /* ====== END of txt2 ====== */

  xTaskCreate([](void*) {
    String list = "";
    while (1) {
      list += "กำลังค้นหา...";
      lv_label_set_text(txt2, list.c_str());
      int n = WiFi.scanNetworks();
      list = "ค้นพบ " + String(n) + " รายการ\n";
      for (int i=0;i<n;i++) {
        list += (i + 1);
        list += ".";
        list += WiFi.SSID(i);
        if (WiFi.isEncryption(i)) {
          list += "*";
        }
        list += "\n";
      }
      lv_label_set_text(txt2, list.c_str());
      delay(1000);
    }
  }, "wifiScanTask", 1024, NULL, 1, NULL);
}
