/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_80);

/* ========== temp header ========== */
static lv_style_t temp_style;
lv_obj_t* temp;
/* ====== END of temp header ====== */

/* ========== humi header ========== */
static lv_style_t humi_style;
lv_obj_t* humi;
/* ====== END of humi header ====== */

/* ========== chart1 header ========== */
static lv_style_t chart1_style;
lv_obj_t* chart1;
/* ====== END of chart1 header ====== */

/* ========== lamp header ========== */
static lv_style_t lamp_bg_style;
static lv_style_t lamp_indic_style;
static lv_style_t lamp_knob_on_style;
static lv_style_t lamp_knob_off_style;

lv_obj_t* lamp;
extern void event_helper_handle(lv_obj_t*, lv_event_t);
/* ====== END of lamp header ====== */

/* ========== loadingBox header ========== */
static lv_style_t loadingBox_style;
lv_obj_t* loadingBox;
/* ====== END of loadingBox header ====== */


void load_page() {
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0xEAEDED);
  style_screen.body.grad_color = lv_color_hex(0xEAEDED);
  lv_obj_set_style(lv_scr_act(), &style_screen);
  
  /* ========== box1 ========== */
  static lv_style_t box1_style;
  lv_obj_t* box1;
  
  lv_style_copy(&box1_style, &lv_style_plain);
  box1_style.body.main_color = lv_color_hex(0xFFFFFF);
  box1_style.body.grad_color = lv_color_hex(0xFFFFFF);
  box1_style.body.radius = 0;
  box1_style.body.opa = 255;
  box1_style.body.border.color = lv_color_hex(0x000000);
  box1_style.body.border.width = 0;
  box1_style.body.border.opa = 255;
  box1_style.body.shadow.color = lv_color_hex(0xAFAFAF);
  box1_style.body.shadow.width = 4;
  box1_style.body.shadow.type = LV_SHADOW_BOTTOM;
  
  box1 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(box1, &box1_style);
  lv_obj_set_size(box1, 280, 210);
  lv_obj_align(box1, NULL, LV_ALIGN_IN_TOP_MID, -240, 20);
  
  lv_obj_set_hidden(box1, false);
  /* ====== END of box1 ====== */
  
  /* ========== box1in ========== */
  static lv_style_t box1in_style;
  lv_obj_t* box1in;
  
  lv_style_copy(&box1in_style, &lv_style_plain);
  box1in_style.body.main_color = lv_color_hex(0x1ABC9C);
  box1in_style.body.grad_color = lv_color_hex(0x1ABC9C);
  box1in_style.body.radius = 0;
  box1in_style.body.opa = 255;
  box1in_style.body.border.color = lv_color_hex(0x000000);
  box1in_style.body.border.width = 0;
  box1in_style.body.border.opa = 255;
  box1in_style.body.shadow.color = lv_color_hex(0x000000);
  box1in_style.body.shadow.width = 0;
  box1in_style.body.shadow.type = LV_SHADOW_FULL;
  
  box1in = lv_obj_create(box1, NULL);
  lv_obj_set_style(box1in, &box1in_style);
  lv_obj_set_size(box1in, 280, 160);
  lv_obj_align(box1in, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
  
  lv_obj_set_hidden(box1in, false);
  /* ====== END of box1in ====== */
  
  /* ========== txt1 ========== */
  static lv_style_t txt1_style;
  lv_obj_t* txt1;
  
  lv_style_copy(&txt1_style, &lv_style_plain);
  txt1_style.text.color = lv_color_hex(0x515A5A);
  txt1_style.text.font = &supermarket_30;
  
  txt1 = lv_label_create(box1, NULL);
  lv_label_set_style(txt1, LV_LABEL_STYLE_MAIN, &txt1_style);
  lv_label_set_long_mode(txt1, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt1, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt1, "อุณหภูมิ (*C)");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
  
  lv_obj_set_hidden(txt1, false);
  /* ====== END of txt1 ====== */
  
  /* ========== box2 ========== */
  static lv_style_t box2_style;
  lv_obj_t* box2;
  
  lv_style_copy(&box2_style, &lv_style_plain);
  box2_style.body.main_color = lv_color_hex(0xFFFFFF);
  box2_style.body.grad_color = lv_color_hex(0xFFFFFF);
  box2_style.body.radius = 0;
  box2_style.body.opa = 255;
  box2_style.body.border.color = lv_color_hex(0x000000);
  box2_style.body.border.width = 0;
  box2_style.body.border.opa = 255;
  box2_style.body.shadow.color = lv_color_hex(0xAFAFAF);
  box2_style.body.shadow.width = 4;
  box2_style.body.shadow.type = LV_SHADOW_BOTTOM;
  
  box2 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(box2, &box2_style);
  lv_obj_set_size(box2, 280, 210);
  lv_obj_align(box2, NULL, LV_ALIGN_IN_TOP_MID, 60, 20);
  
  lv_obj_set_hidden(box2, false);
  /* ====== END of box2 ====== */
  
  /* ========== box2in ========== */
  static lv_style_t box2in_style;
  lv_obj_t* box2in;
  
  lv_style_copy(&box2in_style, &lv_style_plain);
  box2in_style.body.main_color = lv_color_hex(0xF1C40F);
  box2in_style.body.grad_color = lv_color_hex(0xF1C40F);
  box2in_style.body.radius = 0;
  box2in_style.body.opa = 255;
  box2in_style.body.border.color = lv_color_hex(0x000000);
  box2in_style.body.border.width = 0;
  box2in_style.body.border.opa = 255;
  box2in_style.body.shadow.color = lv_color_hex(0x000000);
  box2in_style.body.shadow.width = 0;
  box2in_style.body.shadow.type = LV_SHADOW_FULL;
  
  box2in = lv_obj_create(box2, NULL);
  lv_obj_set_style(box2in, &box2in_style);
  lv_obj_set_size(box2in, 280, 160);
  lv_obj_align(box2in, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
  
  lv_obj_set_hidden(box2in, false);
  /* ====== END of box2in ====== */
  
  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_obj_t* txt2;
  
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x515A5A);
  txt2_style.text.font = &supermarket_30;
  
  txt2 = lv_label_create(box2, NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "ความชื้น (%RH)");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
  
  lv_obj_set_hidden(txt2, false);
  /* ====== END of txt2 ====== */
  
  /* ========== box3 ========== */
  static lv_style_t box3_style;
  lv_obj_t* box3;
  
  lv_style_copy(&box3_style, &lv_style_plain);
  box3_style.body.main_color = lv_color_hex(0xFFFFFF);
  box3_style.body.grad_color = lv_color_hex(0xFFFFFF);
  box3_style.body.radius = 0;
  box3_style.body.opa = 255;
  box3_style.body.border.color = lv_color_hex(0x000000);
  box3_style.body.border.width = 0;
  box3_style.body.border.opa = 255;
  box3_style.body.shadow.color = lv_color_hex(0xAFAFAF);
  box3_style.body.shadow.width = 4;
  box3_style.body.shadow.type = LV_SHADOW_BOTTOM;
  
  box3 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(box3, &box3_style);
  lv_obj_set_size(box3, 160, 210);
  lv_obj_align(box3, NULL, LV_ALIGN_IN_TOP_MID, 300, 20);
  
  lv_obj_set_hidden(box3, false);
  /* ====== END of box3 ====== */
  
  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_obj_t* txt3;
  
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0x515A5A);
  txt3_style.text.font = &supermarket_30;
  
  txt3 = lv_label_create(box3, NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt3, "ไฟหน้าบ้าน");
  lv_obj_set_size(txt3, 0, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_IN_TOP_MID, 0, 10);
  
  lv_obj_set_hidden(txt3, false);
  /* ====== END of txt3 ====== */
  
  /* ========== temp ========== */
  lv_style_copy(&temp_style, &lv_style_plain);
  temp_style.text.color = lv_color_hex(0xFFFFFF);
  temp_style.text.font = &supermarket_80;
  
  temp = lv_label_create(box1in, NULL);
  lv_label_set_style(temp, LV_LABEL_STYLE_MAIN, &temp_style);
  lv_label_set_long_mode(temp, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(temp, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(temp, "200");
  lv_obj_set_size(temp, 0, 0);
  lv_obj_align(temp, NULL, LV_ALIGN_CENTER, 0, 0);
  
  lv_obj_set_hidden(temp, false);
  /* ====== END of temp ====== */
  
  /* ========== humi ========== */
  lv_style_copy(&humi_style, &lv_style_plain);
  humi_style.text.color = lv_color_hex(0xFFFFFF);
  humi_style.text.font = &supermarket_80;
  
  humi = lv_label_create(box2in, NULL);
  lv_label_set_style(humi, LV_LABEL_STYLE_MAIN, &humi_style);
  lv_label_set_long_mode(humi, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(humi, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(humi, "10");
  lv_obj_set_size(humi, 0, 0);
  lv_obj_align(humi, NULL, LV_ALIGN_CENTER, 0, 0);
  
  lv_obj_set_hidden(humi, false);
  /* ====== END of humi ====== */
  
  /* ========== box4 ========== */
  static lv_style_t box4_style;
  lv_obj_t* box4;
  
  lv_style_copy(&box4_style, &lv_style_plain);
  box4_style.body.main_color = lv_color_hex(0xFFFFFF);
  box4_style.body.grad_color = lv_color_hex(0xFFFFFF);
  box4_style.body.radius = 0;
  box4_style.body.opa = 255;
  box4_style.body.border.color = lv_color_hex(0x000000);
  box4_style.body.border.width = 0;
  box4_style.body.border.opa = 255;
  box4_style.body.shadow.color = lv_color_hex(0xAFAFAF);
  box4_style.body.shadow.width = 4;
  box4_style.body.shadow.type = LV_SHADOW_BOTTOM;
  
  box4 = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(box4, &box4_style);
  lv_obj_set_size(box4, 760, 210);
  lv_obj_align(box4, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -20);
  
  lv_obj_set_hidden(box4, false);
  /* ====== END of box4 ====== */
  
  /* ========== chart1 ========== */
  lv_style_copy(&chart1_style, &lv_style_plain);
  chart1_style.body.main_color = lv_color_hex(0xFFFFFF);
  chart1_style.body.grad_color = lv_color_hex(0xFFFFFF);
  chart1_style.body.radius = 6;
  chart1_style.body.border.color = lv_color_hex(0x404040);
  chart1_style.body.border.width = 0;
  chart1_style.line.color = lv_color_hex(0xE5E7E9);
  chart1_style.line.width = 2;
  
  chart1 = lv_chart_create(box4, NULL);
  lv_chart_set_style(chart1, LV_CHART_STYLE_MAIN, &chart1_style);
  lv_obj_set_size(chart1, 740, 190);
  lv_obj_align(chart1, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_chart_set_type(chart1, LV_CHART_TYPE_POINT | LV_CHART_TYPE_LINE);
  lv_chart_set_series_opa(chart1, LV_OPA_70);
  lv_chart_set_series_width(chart1, 2);
  lv_chart_set_div_line_count(chart1, 5, 10);
  lv_chart_set_range(chart1, 0, 100);
  
  lv_obj_set_hidden(chart1, false);
  /* ====== END of chart1 ====== */
  
  /* ========== lamp ========== */
  lv_style_copy(&lamp_bg_style, &lv_style_pretty);
  lamp_bg_style.body.radius = LV_RADIUS_CIRCLE;
  lamp_bg_style.body.main_color = lv_color_hex(0xFFFFFF);
  lamp_bg_style.body.grad_color = lv_color_hex(0xFFFFFF);
  lamp_bg_style.body.padding.left = 0;
  lamp_bg_style.body.padding.right = 0;
  lamp_bg_style.body.padding.top = 0;
  lamp_bg_style.body.padding.bottom = 0;
  lamp_bg_style.body.border.color = lv_color_hex(0xE5E7E9);
  lamp_bg_style.body.border.width = 2;
  
  lv_style_copy(&lamp_indic_style, &lv_style_pretty_color);
  lamp_indic_style.body.radius = LV_RADIUS_CIRCLE;
  lamp_indic_style.body.main_color = lv_color_hex(0xA569BD);
  lamp_indic_style.body.grad_color = lv_color_hex(0xA569BD);
  lamp_indic_style.body.padding.left = 0;
  lamp_indic_style.body.padding.right = 0;
  lamp_indic_style.body.padding.top = 0;
  lamp_indic_style.body.padding.bottom = 0;
  lamp_indic_style.body.border.color = lv_color_hex(0x5B2C6F);
  lamp_indic_style.body.border.width = 2;
  
  lv_style_copy(&lamp_knob_off_style, &lv_style_pretty);
  lamp_knob_off_style.body.main_color = lv_color_hex(0xFFFFFF);
  lamp_knob_off_style.body.grad_color = lv_color_hex(0xFFFFFF);
  lamp_knob_off_style.body.radius = LV_RADIUS_CIRCLE;
  lamp_knob_off_style.body.shadow.color = lv_color_hex(0x808080);
  lamp_knob_off_style.body.shadow.width = 0;
  lamp_knob_off_style.body.shadow.type = LV_SHADOW_BOTTOM;
  lamp_knob_off_style.body.border.color = lv_color_hex(0xD7DBDD);
  lamp_knob_off_style.body.border.width = 2;
  
  lv_style_copy(&lamp_knob_on_style, &lv_style_pretty_color);
  lamp_knob_on_style.body.main_color = lv_color_hex(0x8E44AD);
  lamp_knob_on_style.body.grad_color = lv_color_hex(0x8E44AD);
  lamp_knob_on_style.body.radius = LV_RADIUS_CIRCLE;
  lamp_knob_on_style.body.shadow.color = lv_color_hex(0x808080);
  lamp_knob_on_style.body.shadow.width = 0;
  lamp_knob_on_style.body.shadow.type = LV_SHADOW_BOTTOM;
  lamp_knob_on_style.body.border.color = lv_color_hex(0x5B2C6F);
  lamp_knob_on_style.body.border.width = 2;
  
  lamp = lv_sw_create(box3, NULL);
  lv_sw_set_style(lamp, LV_SW_STYLE_BG, &lamp_bg_style);
  lv_sw_set_style(lamp, LV_SW_STYLE_INDIC, &lamp_indic_style);
  lv_sw_set_style(lamp, LV_SW_STYLE_KNOB_ON, &lamp_knob_on_style);
  lv_sw_set_style(lamp, LV_SW_STYLE_KNOB_OFF, &lamp_knob_off_style);
  lv_obj_set_size(lamp, 100, 60);
  lv_obj_align(lamp, NULL, LV_ALIGN_CENTER, 0, 20);
  lv_obj_set_event_cb(lamp, event_helper_handle);
  
  lv_sw_off(lamp, LV_ANIM_OFF);
  
  lv_obj_set_hidden(lamp, false);
  /* ====== END of lamp ====== */
  
  /* ========== loadingBox ========== */
  lv_style_copy(&loadingBox_style, &lv_style_plain);
  loadingBox_style.body.main_color = lv_color_hex(0x000000);
  loadingBox_style.body.grad_color = lv_color_hex(0x000000);
  loadingBox_style.body.radius = 0;
  loadingBox_style.body.opa = 160;
  loadingBox_style.body.border.color = lv_color_hex(0x000000);
  loadingBox_style.body.border.width = 0;
  loadingBox_style.body.border.opa = 255;
  loadingBox_style.body.shadow.color = lv_color_hex(0x000000);
  loadingBox_style.body.shadow.width = 0;
  loadingBox_style.body.shadow.type = LV_SHADOW_FULL;
  
  loadingBox = lv_obj_create(lv_scr_act(), NULL);
  lv_obj_set_style(loadingBox, &loadingBox_style);
  lv_obj_set_size(loadingBox, 800, 480);
  lv_obj_align(loadingBox, NULL, LV_ALIGN_CENTER, 0, 0);
  
  lv_obj_set_hidden(loadingBox, true);
  /* ====== END of loadingBox ====== */
  
  /* ========== txt4 ========== */
  static lv_style_t txt4_style;
  lv_obj_t* txt4;
  
  lv_style_copy(&txt4_style, &lv_style_plain);
  txt4_style.text.color = lv_color_hex(0xFFFFFF);
  txt4_style.text.font = &supermarket_80;
  
  txt4 = lv_label_create(loadingBox, NULL);
  lv_label_set_style(txt4, LV_LABEL_STYLE_MAIN, &txt4_style);
  lv_label_set_long_mode(txt4, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt4, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt4, "LOADING");
  lv_obj_set_size(txt4, 0, 0);
  lv_obj_align(txt4, NULL, LV_ALIGN_CENTER, 0, 0);
  
  lv_obj_set_hidden(txt4, false);
  /* ====== END of txt4 ====== */
}
