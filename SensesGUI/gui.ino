/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);

lv_obj_t* txtStatus;
lv_obj_t* slider;
lv_obj_t* txtValue;

extern void send_handler(lv_obj_t * obj, lv_event_t event) ;
extern void slider_handler(lv_obj_t * obj, lv_event_t event) ;

void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x474747);
  style_screen.body.grad_color = lv_color_hex(0x2E2E2E);
  lv_obj_set_style(lv_scr_act(), &style_screen);
  
  /* ========== slider ========== */
  static lv_style_t slider_bg_style;
  static lv_style_t slider_indic_style;
  static lv_style_t slider_knob_style;
  
  lv_style_copy(&slider_bg_style, &lv_style_pretty);
  slider_bg_style.body.radius = 6;
  slider_bg_style.body.main_color = lv_color_hex(0xFFFFFF);
  slider_bg_style.body.grad_color = lv_color_hex(0xC0C0C0);
  slider_bg_style.body.padding.left = 6;
  slider_bg_style.body.padding.right = 6;
  slider_bg_style.body.padding.top = 6;
  slider_bg_style.body.padding.bottom = 6;
  slider_bg_style.body.border.color = lv_color_hex(0x404040);
  slider_bg_style.body.border.width = 2;
  
  lv_style_copy(&slider_indic_style, &lv_style_pretty_color);
  slider_indic_style.body.radius = 6;
  slider_indic_style.body.main_color = lv_color_hex(0x6b9ac7);
  slider_indic_style.body.grad_color = lv_color_hex(0x2b598b);
  slider_indic_style.body.padding.left = 6;
  slider_indic_style.body.padding.right = 6;
  slider_indic_style.body.padding.top = 6;
  slider_indic_style.body.padding.bottom = 6;
  slider_indic_style.body.border.color = lv_color_hex(0x152c42);
  slider_indic_style.body.border.width = 2;
  
  lv_style_copy(&slider_knob_style, &lv_style_pretty);
  slider_knob_style.body.main_color = lv_color_hex(0x6b9ac7);
  slider_knob_style.body.grad_color = lv_color_hex(0x2b598b);
  slider_knob_style.body.radius = LV_RADIUS_CIRCLE;
  slider_knob_style.body.border.color = lv_color_hex(0x152c42);
  slider_knob_style.body.border.width = 2;
  
  slider = lv_slider_create(lv_scr_act(), NULL);
  lv_slider_set_style(slider, LV_SLIDER_STYLE_BG, &slider_bg_style);
  lv_slider_set_style(slider, LV_SLIDER_STYLE_INDIC, &slider_indic_style);
  lv_slider_set_style(slider, LV_SLIDER_STYLE_KNOB, &slider_knob_style);
  lv_obj_set_size(slider, 400, 50);
  lv_obj_align(slider, NULL, LV_ALIGN_CENTER, 0, 40);
  lv_obj_set_event_cb(slider, slider_handler);
  
  lv_slider_set_range(slider, 0, 100);
  lv_slider_set_value(slider, 0, LV_ANIM_OFF);
  /* ====== END of slider ====== */
  
  /* ========== txtValue ========== */
  static lv_style_t txtValue_style;
  lv_style_copy(&txtValue_style, &lv_style_plain);
  txtValue_style.text.color = lv_color_hex(0xFFFFFF);
  txtValue_style.text.font = &supermarket_60;
  
  txtValue = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txtValue, LV_LABEL_STYLE_MAIN, &txtValue_style);
  lv_label_set_long_mode(txtValue, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txtValue, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txtValue, "0");
  lv_obj_set_size(txtValue, 0, 0);
  lv_obj_align(txtValue, NULL, LV_ALIGN_CENTER, 0, -30);
  /* ====== END of txtValue ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_60;
  
  lv_obj_t* txt2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "ส่งข้อมูลขึ้น SENSES IoT");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt2 ====== */
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  btn1_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  btn1_rel_style.body.radius = 6;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 2;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x336294);
  btn1_pr_style.body.grad_color = lv_color_hex(0x10263C);
  btn1_pr_style.body.radius = 6;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 2;
  
  lv_obj_t* btn1 = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btn1, send_handler);
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 160, 60);
  lv_obj_align(btn1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -60);
  
  static lv_style_t btn1_label_style;
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &lv_font_roboto_16;
  lv_obj_t* btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "Send");
  /* ====== END of btn1 ====== */
  
  /* ========== txtStatus ========== */
  static lv_style_t txtStatus_style;
  lv_style_copy(&txtStatus_style, &lv_style_plain);
  txtStatus_style.text.color = lv_color_hex(0xFFFFFF);
  txtStatus_style.text.font = &lv_font_roboto_16;
  
  txtStatus = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txtStatus, LV_LABEL_STYLE_MAIN, &txtStatus_style);
  lv_label_set_long_mode(txtStatus, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txtStatus, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txtStatus, "wait boot finish");
  lv_obj_set_size(txtStatus, 0, 0);
  lv_obj_align(txtStatus, NULL, LV_ALIGN_IN_BOTTOM_MID, 10, -20);
  /* ====== END of txtStatus ====== */

  lv_obj_set_auto_realign(txtValue, true);
  lv_obj_set_auto_realign(txtStatus, true);
}
