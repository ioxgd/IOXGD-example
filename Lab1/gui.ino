/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_60);

lv_obj_t* txt2;

void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xFFFFFF);
  style_screen.body.grad_color = lv_color_hex(0xFFFFFF);
  lv_obj_set_style(lv_scr_act(), &style_screen);
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0x000000);
  txt1_style.text.font = &supermarket_60;
  
  lv_obj_t* txt1 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "ลูกเต๋าอิเล็กทรอนิกส์");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);
  /* ====== END of txt1 ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x000000);
  txt2_style.text.font = &supermarket_60;
  
  txt2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "0");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_CENTER, 0, 0);
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
  lv_obj_set_event_cb(btn1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      int n = random(1, 6); // สุ่มค่า 1 ถึง 6
      char str[4]; // สร้างตัวแปร str เก็บค่าที่สุ่มได้เป็นข้อความ
      itoa(n, str, 10); // แปลงตัวเลขเป็นข้อความ
      lv_label_set_text(txt2, str); // อัพเดทข้อความใน txt2
      gd.beep(); // ให้บัสเซอร์ส่งเสียง
    }
  });
  lv_btn_set_style(btn1, LV_BTN_STATE_REL, &btn1_rel_style);
  lv_btn_set_style(btn1, LV_BTN_STATE_PR, &btn1_pr_style);
  lv_obj_set_size(btn1, 300, 100);
  lv_obj_align(btn1, NULL, LV_ALIGN_CENTER, 0, 140);
  
  static lv_style_t btn1_label_style;
  lv_style_copy(&btn1_label_style, &lv_style_plain);
  btn1_label_style.text.color = lv_color_hex(0xFFFFFF);
  btn1_label_style.text.font = &supermarket_60;
  lv_obj_t* btn1_label = lv_label_create(btn1, NULL);
  lv_label_set_style(btn1_label, LV_LABEL_STYLE_MAIN, &btn1_label_style);
  lv_label_set_text(btn1_label, "ทอยลูกเต๋า");
  /* ====== END of btn1 ====== */
}
