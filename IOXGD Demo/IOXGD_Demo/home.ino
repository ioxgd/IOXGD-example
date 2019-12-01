/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_60);

LV_IMG_DECLARE(ioxgd_logo);
LV_IMG_DECLARE(cpu_logo);
LV_IMG_DECLARE(graph_logo);
LV_IMG_DECLARE(lamp_logo);
LV_IMG_DECLARE(calculator_logo);
LV_IMG_DECLARE(wifi_logo);

extern lv_obj_t* gpioScreen;
extern lv_obj_t* graphScreen;
extern lv_obj_t* calculatorScreen;
extern lv_obj_t* wifiscanScreen;
extern lv_obj_t* systemScreen;

lv_obj_t* homeScreen;

void home_page() {
  homeScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x4F4F4F);
  style_screen.body.grad_color = lv_color_hex(0x272727);
  lv_obj_set_style(homeScreen, &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xFFFFFF);
  txt1_style.text.font = &supermarket_60;
  
  lv_obj_t* txt1 = lv_label_create(homeScreen, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "โปรแกรมตัวอย่าง IOXGD");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt1 ====== */
  
  /* ========== img1 ========== */
  lv_obj_t* img1 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img1, &ioxgd_logo); // TODO
  lv_obj_align(img1, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 20, -20);
  /* ====== END of img1 ====== */
  
  /* ========== img2 ========== */
  lv_obj_t* img2 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img2, &wifi_logo); // TODO
  lv_obj_align(img2, NULL, LV_ALIGN_CENTER, -100, 150);
  lv_obj_set_click(img2, true);
  lv_obj_set_event_cb(img2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(wifiscanScreen);
      gd.beep();
    }
  });
  /* ====== END of img2 ====== */
  
  /* ========== img3 ========== */
  lv_obj_t* img3 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img3, &cpu_logo); // TODO
  lv_obj_align(img3, NULL, LV_ALIGN_CENTER, 100, 160);
  lv_obj_set_click(img3, true);
  lv_obj_set_event_cb(img3, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(systemScreen);
      gd.beep();
    }
  });
  /* ====== END of img3 ====== */
  
  /* ========== img4 ========== */
  lv_obj_t* img4 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img4, &lamp_logo); // TODO
  lv_obj_align(img4, NULL, LV_ALIGN_CENTER, -190, -10);
  lv_obj_set_click(img4, true);
  lv_obj_set_event_cb(img4, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(gpioScreen);
      gd.beep();
    }
  });
  /* ====== END of img4 ====== */
  
  /* ========== img5 ========== */
  lv_obj_t* img5 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img5, &calculator_logo); // TODO
  lv_obj_align(img5, NULL, LV_ALIGN_CENTER, 0, -10);
  lv_obj_set_click(img5, true);
  lv_obj_set_event_cb(img5, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(calculatorScreen);
      gd.beep();
    }
  });
  /* ====== END of img5 ====== */
  
  /* ========== img6 ========== */
  lv_obj_t* img6 = lv_img_create(homeScreen, NULL);
  lv_img_set_src(img6, &graph_logo); // TODO
  lv_obj_align(img6, NULL, LV_ALIGN_CENTER, 190, -10);
  lv_obj_set_click(img6, true);
  lv_obj_set_event_cb(img6, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      lv_scr_load(graphScreen);
      gd.beep();
    }
  });
  /* ====== END of img6 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_30;
  
  lv_obj_t* txt2 = lv_label_create(homeScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "คลิกที่รูปเพื่อเข้าเมนูต่าง ๆ");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_MID, 0, 100);
  /* ====== END of txt2 ====== */
}
