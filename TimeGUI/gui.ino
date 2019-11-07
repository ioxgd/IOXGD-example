/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_80);
LV_FONT_DECLARE(supermarket_200);
LV_FONT_DECLARE(supermarket_40);

lv_obj_t* txt2;
lv_obj_t* txt3;
lv_obj_t* txt4;

void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x2E86C1);
  style_screen.body.grad_color = lv_color_hex(0x2E86C1);
  lv_obj_set_style(lv_scr_act(), &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xFFFFFF);
  txt1_style.text.font = &supermarket_80;
  
  lv_obj_t* txt1 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "นาฬิกาดิจิตอล");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt1 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0xFFFFFF);
  txt2_style.text.font = &supermarket_200;
  
  txt2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "00:00:00");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_CENTER, 0, 0);
  /* ====== END of txt2 ====== */
  
  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0xFFFFFF);
  txt3_style.text.font = &supermarket_40;
  
  txt3 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt3, "....");
  lv_obj_set_size(txt3, 0, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_CENTER, 0, 130);
  /* ====== END of txt3 ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0xFFFFFF);
  txt4_style.text.font = &lv_font_roboto_16;
  
  txt4 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt4, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txt4, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt4, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt4, "Waiting...");
  lv_obj_set_size(txt4, 0, 0);
  lv_obj_align(txt4, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  /* ====== END of txt4 ====== */

  lv_obj_set_auto_realign(txt2, true);
  lv_obj_set_auto_realign(txt3, true);
  lv_obj_set_auto_realign(txt4, true);
}
