/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* graphScreen;

lv_obj_t* chart1;
lv_obj_t* slider1;

void graph_page() {
  graphScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x707B7C);
  style_screen.body.grad_color = lv_color_hex(0x707B7C);
  lv_obj_set_style(graphScreen, &style_screen);
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0x515A5A);
  btn1_rel_style.body.grad_color = lv_color_hex(0x515A5A);
  btn1_rel_style.body.radius = 0;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x4D5656);
  btn1_pr_style.body.grad_color = lv_color_hex(0x4D5656);
  btn1_pr_style.body.radius = 0;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  lv_obj_t* btn1 = lv_btn_create(graphScreen, NULL);
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
  
  /* ========== chart1 ========== */
  static lv_style_t chart1_style;
  lv_style_copy(&chart1_style, &lv_style_plain);
  chart1_style.body.main_color = lv_color_hex(0xFFFFFF);
  chart1_style.body.grad_color = lv_color_hex(0xC0C0C0);
  chart1_style.body.radius = 6;
  chart1_style.body.border.color = lv_color_hex(0x404040);
  chart1_style.body.border.width = 2;
  chart1_style.line.color = lv_color_hex(0x202020);
  chart1_style.line.width = 2;
  
  chart1 = lv_chart_create(graphScreen, NULL);
  lv_chart_set_style(chart1, LV_CHART_STYLE_MAIN, &chart1_style);
  lv_obj_set_size(chart1, 700, 260);
  lv_obj_align(chart1, NULL, LV_ALIGN_IN_TOP_LEFT, 50, 130);
  lv_chart_set_type(chart1, LV_CHART_TYPE_POINT | LV_CHART_TYPE_LINE);
  lv_chart_set_series_opa(chart1, LV_OPA_70);
  lv_chart_set_series_width(chart1, 6);
  lv_chart_set_div_line_count(chart1, 3, 10);
  lv_chart_set_range(chart1, 0, 100);
  /* ====== END of chart1 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_60;
  
  lv_obj_t* txt2 = lv_label_create(graphScreen, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "กราฟ");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
  /* ====== END of txt2 ====== */
  
  /* ========== slider1 ========== */
  static lv_style_t slider1_bg_style;
  static lv_style_t slider1_indic_style;
  static lv_style_t slider1_knob_style;
  
  lv_style_copy(&slider1_bg_style, &lv_style_pretty);
  slider1_bg_style.body.radius = 6;
  slider1_bg_style.body.main_color = lv_color_hex(0xFFFFFF);
  slider1_bg_style.body.grad_color = lv_color_hex(0xC0C0C0);
  slider1_bg_style.body.padding.left = 6;
  slider1_bg_style.body.padding.right = 6;
  slider1_bg_style.body.padding.top = 6;
  slider1_bg_style.body.padding.bottom = 6;
  slider1_bg_style.body.border.color = lv_color_hex(0x404040);
  slider1_bg_style.body.border.width = 2;
  
  lv_style_copy(&slider1_indic_style, &lv_style_pretty_color);
  slider1_indic_style.body.radius = 6;
  slider1_indic_style.body.main_color = lv_color_hex(0x6b9ac7);
  slider1_indic_style.body.grad_color = lv_color_hex(0x2b598b);
  slider1_indic_style.body.padding.left = 0;
  slider1_indic_style.body.padding.right = 0;
  slider1_indic_style.body.padding.top = 0;
  slider1_indic_style.body.padding.bottom = 0;
  slider1_indic_style.body.border.color = lv_color_hex(0x152c42);
  slider1_indic_style.body.border.width = 2;
  
  lv_style_copy(&slider1_knob_style, &lv_style_pretty);
  slider1_knob_style.body.main_color = lv_color_hex(0x6b9ac7);
  slider1_knob_style.body.grad_color = lv_color_hex(0x2b598b);
  slider1_knob_style.body.radius = LV_RADIUS_CIRCLE;
  slider1_knob_style.body.border.color = lv_color_hex(0x152c42);
  slider1_knob_style.body.border.width = 2;
  
  slider1 = lv_slider_create(graphScreen, NULL);
  lv_slider_set_style(slider1, LV_SLIDER_STYLE_BG, &slider1_bg_style);
  lv_slider_set_style(slider1, LV_SLIDER_STYLE_INDIC, &slider1_indic_style);
  lv_slider_set_style(slider1, LV_SLIDER_STYLE_KNOB, &slider1_knob_style);
  lv_obj_set_size(slider1, 400, 40);
  lv_obj_align(slider1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  // lv_obj_set_event_cb(slider1, event_handler);
  
  lv_slider_set_range(slider1, 0, 100);
  lv_slider_set_value(slider1, 50, LV_ANIM_OFF);
  /* ====== END of slider1 ====== */

  xTaskCreate([](void*) {
    lv_chart_series_t * ser1 = lv_chart_add_series(chart1, LV_COLOR_RED);
    while (1) {
      lv_chart_set_next(chart1, ser1, lv_slider_get_value(slider1));
      delay(100);
    }
  }, "graphTask", 512, NULL, 1, NULL);
}
