/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_50);
LV_FONT_DECLARE(supermarket_30);

LV_IMG_DECLARE(angry);
LV_IMG_DECLARE(confused);
LV_IMG_DECLARE(happy2);
LV_IMG_DECLARE(happy);
LV_IMG_DECLARE(sad);

extern int send_rate;

/* ========== rate1 header ========== */
lv_obj_t* rate1;
/* ====== END of rate1 header ====== */

/* ========== rate3 header ========== */
lv_obj_t* rate3;
/* ====== END of rate3 header ====== */

/* ========== rate4 header ========== */
lv_obj_t* rate4;
/* ====== END of rate4 header ====== */

/* ========== rate5 header ========== */
lv_obj_t* rate5;
/* ====== END of rate5 header ====== */

/* ========== rate2 header ========== */
lv_obj_t* rate2;
/* ====== END of rate2 header ====== */

/* ========== txt7 header ========== */
static lv_style_t txt7_style;
lv_obj_t* txt7;
/* ====== END of txt7 header ====== */


void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x6048FF);
  style_screen.body.grad_color = lv_color_hex(0xEB35FF);
  lv_obj_set_style(lv_scr_act(), &style_screen);
  
  /* ========== obj1 ========== */
  static lv_style_t obj1_style;
  lv_obj_t* obj1;
  
  lv_style_copy(&obj1_style, &lv_style_plain);
  obj1_style.body.main_color = lv_color_hex(0xFFFFFF);
  obj1_style.body.grad_color = lv_color_hex(0xFFFFFF);
  obj1_style.body.radius = 0;
  obj1_style.body.opa = 200;
  obj1_style.body.border.color = lv_color_hex(0x000000);
  obj1_style.body.border.width = 0;
  obj1_style.body.border.opa = 255;
  obj1_style.body.shadow.color = lv_color_hex(0x000000);
  obj1_style.body.shadow.width = 0;
  obj1_style.body.shadow.type = LV_SHADOW_FULL;
  
  obj1 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(obj1, &obj1_style);
  lv_obj_set_size(obj1, 800, 260);
  lv_obj_align(obj1, NULL, LV_ALIGN_IN_TOP_MID, 0, 140);
  
  lv_obj_set_hidden(obj1, false);
  /* ====== END of obj1 ====== */
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_obj_t* txt1;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0xFFFFFF);
  txt1_style.text.font = &supermarket_50;
  
  txt1 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "ให้คะแนนความพึงพอใจในการให้บริการ");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);
  
  lv_obj_set_hidden(txt1, false);
  /* ====== END of txt1 ====== */
  
  /* ========== rate1 ========== */
  rate1 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(rate1, &angry);
  lv_obj_align(rate1, NULL, LV_ALIGN_IN_TOP_LEFT, 50, 210);
  
  lv_obj_set_hidden(rate1, false);
  /* ====== END of rate1 ====== */
  
  /* ========== rate3 ========== */
  rate3 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(rate3, &confused);
  lv_obj_align(rate3, NULL, LV_ALIGN_IN_TOP_LEFT, 350, 210);
  
  lv_obj_set_hidden(rate3, false);
  /* ====== END of rate3 ====== */
  
  /* ========== rate4 ========== */
  rate4 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(rate4, &happy);
  lv_obj_align(rate4, NULL, LV_ALIGN_IN_TOP_LEFT, 500, 210);
  
  lv_obj_set_hidden(rate4, false);
  /* ====== END of rate4 ====== */
  
  /* ========== rate5 ========== */
  rate5 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(rate5, &happy2);
  lv_obj_align(rate5, NULL, LV_ALIGN_IN_TOP_LEFT, 650, 210);
  
  lv_obj_set_hidden(rate5, false);
  /* ====== END of rate5 ====== */
  
  /* ========== rate2 ========== */
  rate2 = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(rate2, &sad);
  lv_obj_align(rate2, NULL, LV_ALIGN_IN_TOP_LEFT, 200, 210);
  
  lv_obj_set_hidden(rate2, false);
  /* ====== END of rate2 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_obj_t* txt2;
  
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x000000);
  txt2_style.text.font = &supermarket_30;
  
  txt2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt2, "น้อยที่สุด");
  lv_obj_set_size(txt2, 100, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_LEFT, 50, 310);
  
  lv_obj_set_hidden(txt2, false);
  /* ====== END of txt2 ====== */
  
  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_obj_t* txt3;
  
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0x000000);
  txt3_style.text.font = &supermarket_30;
  
  txt3 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt3, "น้อย");
  lv_obj_set_size(txt3, 100, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_IN_TOP_LEFT, 200, 310);
  
  lv_obj_set_hidden(txt3, false);
  /* ====== END of txt3 ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  lv_obj_t* txt4;
  
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0x000000);
  txt4_style.text.font = &supermarket_30;
  
  txt4 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt4, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txt4, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt4, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt4, "พอใช้");
  lv_obj_set_size(txt4, 100, 0);
  lv_obj_align(txt4, NULL, LV_ALIGN_IN_TOP_LEFT, 350, 310);
  
  lv_obj_set_hidden(txt4, false);
  /* ====== END of txt4 ====== */
  
  /* ========== txt5 ========== */
  static lv_style_t txt5_style;
  lv_obj_t* txt5;
  
  lv_style_copy(&txt5_style, &lv_style_plain);
  txt5_style.text.color = lv_color_hex(0x000000);
  txt5_style.text.font = &supermarket_30;
  
  txt5 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt5, LV_LABEL_STYLE_MAIN, &txt5_style);
  lv_label_set_long_mode(txt5, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt5, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt5, "มาก");
  lv_obj_set_size(txt5, 100, 0);
  lv_obj_align(txt5, NULL, LV_ALIGN_IN_TOP_LEFT, 500, 310);
  
  lv_obj_set_hidden(txt5, false);
  /* ====== END of txt5 ====== */
  
  /* ========== txt6 ========== */
  static lv_style_t txt6_style;
  lv_obj_t* txt6;
  
  lv_style_copy(&txt6_style, &lv_style_plain);
  txt6_style.text.color = lv_color_hex(0x000000);
  txt6_style.text.font = &supermarket_30;
  
  txt6 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt6, LV_LABEL_STYLE_MAIN, &txt6_style);
  lv_label_set_long_mode(txt6, LV_LABEL_LONG_BREAK);
  lv_label_set_align(txt6, LV_LABEL_ALIGN_CENTER);
  lv_label_set_text(txt6, "มากที่สุด");
  lv_obj_set_size(txt6, 100, 0);
  lv_obj_align(txt6, NULL, LV_ALIGN_IN_TOP_LEFT, 650, 310);
  
  lv_obj_set_hidden(txt6, false);
  /* ====== END of txt6 ====== */
  
  /* ========== txt7 ========== */
  lv_style_copy(&txt7_style, &lv_style_plain);
  txt7_style.text.color = lv_color_hex(0xFFFFFF);
  txt7_style.text.font = &supermarket_30;
  
  txt7 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt7, LV_LABEL_STYLE_MAIN, &txt7_style);
  lv_label_set_long_mode(txt7, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt7, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt7, "กำลังบันทึกคะแนน");
  lv_obj_set_size(txt7, 0, 0);
  lv_obj_align(txt7, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -10);
  
  lv_obj_set_hidden(txt7, true);
  /* ====== END of txt7 ====== */

  lv_obj_set_auto_realign(txt7, true);
}
