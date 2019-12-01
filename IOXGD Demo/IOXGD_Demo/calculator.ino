/* ======== Generate by IOXGD Designer ======== */

LV_FONT_DECLARE(supermarket_30);
LV_FONT_DECLARE(supermarket_60);

lv_obj_t* calculatorScreen;
lv_obj_t* result;

String Operand1 = "";
String Operand2 = "";
char Operator = '\0';
String Result = "";

void updateResult(bool equal = false) ;
void addOperand(char digi) ;

void calculator_page() {
  calculatorScreen = lv_obj_create(NULL, NULL);
  
  static lv_style_t style_screen;
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x3D3D3D);
  style_screen.body.grad_color = lv_color_hex(0x242424);
  lv_obj_set_style(calculatorScreen, &style_screen);
  
  /* ========== btn1 ========== */
  static lv_style_t btn1_rel_style;
  lv_style_copy(&btn1_rel_style, &lv_style_plain);
  btn1_rel_style.body.main_color = lv_color_hex(0x535353);
  btn1_rel_style.body.grad_color = lv_color_hex(0x535353);
  btn1_rel_style.body.radius = 0;
  btn1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_rel_style.body.border.width = 0;
  
  static lv_style_t btn1_pr_style;
  lv_style_copy(&btn1_pr_style, &lv_style_plain);
  btn1_pr_style.body.main_color = lv_color_hex(0x0A131D);
  btn1_pr_style.body.grad_color = lv_color_hex(0x0A131D);
  btn1_pr_style.body.radius = 0;
  btn1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  btn1_pr_style.body.border.width = 0;
  
  lv_obj_t* btn1 = lv_btn_create(calculatorScreen, NULL);
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
  
  /* ========== digi0 ========== */
  static lv_style_t digi0_rel_style;
  lv_style_copy(&digi0_rel_style, &lv_style_plain);
  digi0_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi0_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi0_rel_style.body.radius = 6;
  digi0_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi0_rel_style.body.border.width = 2;
  
  static lv_style_t digi0_pr_style;
  lv_style_copy(&digi0_pr_style, &lv_style_plain);
  digi0_pr_style.body.main_color = lv_color_hex(0x336294);
  digi0_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi0_pr_style.body.radius = 6;
  digi0_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi0_pr_style.body.border.width = 2;
  
  lv_obj_t* digi0 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi0, event_handler); // TODO
  lv_btn_set_style(digi0, LV_BTN_STATE_REL, &digi0_rel_style);
  lv_btn_set_style(digi0, LV_BTN_STATE_PR, &digi0_pr_style);
  lv_obj_set_size(digi0, 200, 80);
  lv_obj_align(digi0, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 0, 0);
  lv_obj_set_event_cb(digi0, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('0');
      updateResult();
    }
  });
  
  static lv_style_t digi0_label_style;
  lv_style_copy(&digi0_label_style, &lv_style_plain);
  digi0_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi0_label_style.text.font = &supermarket_30;
  lv_obj_t* digi0_label = lv_label_create(digi0, NULL);
  lv_label_set_style(digi0_label, LV_LABEL_STYLE_MAIN, &digi0_label_style);
  lv_label_set_text(digi0_label, "0");
  /* ====== END of digi0 ====== */
  
  /* ========== dot ========== */
  static lv_style_t dot_rel_style;
  lv_style_copy(&dot_rel_style, &lv_style_plain);
  dot_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  dot_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  dot_rel_style.body.radius = 6;
  dot_rel_style.body.border.color = lv_color_hex(0x0B1928);
  dot_rel_style.body.border.width = 2;
  
  static lv_style_t dot_pr_style;
  lv_style_copy(&dot_pr_style, &lv_style_plain);
  dot_pr_style.body.main_color = lv_color_hex(0x336294);
  dot_pr_style.body.grad_color = lv_color_hex(0x10263C);
  dot_pr_style.body.radius = 6;
  dot_pr_style.body.border.color = lv_color_hex(0x0B1928);
  dot_pr_style.body.border.width = 2;
  
  lv_obj_t* dot = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(dot, event_handler); // TODO
  lv_btn_set_style(dot, LV_BTN_STATE_REL, &dot_rel_style);
  lv_btn_set_style(dot, LV_BTN_STATE_PR, &dot_pr_style);
  lv_obj_set_size(dot, 200, 80);
  lv_obj_align(dot, NULL, LV_ALIGN_IN_BOTTOM_MID, -100, 0);
  lv_obj_set_event_cb(dot, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('.');
      updateResult();
    }
  });
  
  static lv_style_t dot_label_style;
  lv_style_copy(&dot_label_style, &lv_style_plain);
  dot_label_style.text.color = lv_color_hex(0xFFFFFF);
  dot_label_style.text.font = &supermarket_30;
  lv_obj_t* dot_label = lv_label_create(dot, NULL);
  lv_label_set_style(dot_label, LV_LABEL_STYLE_MAIN, &dot_label_style);
  lv_label_set_text(dot_label, ".");
  /* ====== END of dot ====== */
  
  /* ========== equal ========== */
  static lv_style_t equal_rel_style;
  lv_style_copy(&equal_rel_style, &lv_style_plain);
  equal_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  equal_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  equal_rel_style.body.radius = 6;
  equal_rel_style.body.border.color = lv_color_hex(0x0B1928);
  equal_rel_style.body.border.width = 2;
  
  static lv_style_t equal_pr_style;
  lv_style_copy(&equal_pr_style, &lv_style_plain);
  equal_pr_style.body.main_color = lv_color_hex(0x336294);
  equal_pr_style.body.grad_color = lv_color_hex(0x10263C);
  equal_pr_style.body.radius = 6;
  equal_pr_style.body.border.color = lv_color_hex(0x0B1928);
  equal_pr_style.body.border.width = 2;
  
  lv_obj_t* equal = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(equal, event_handler); // TODO
  lv_btn_set_style(equal, LV_BTN_STATE_REL, &equal_rel_style);
  lv_btn_set_style(equal, LV_BTN_STATE_PR, &equal_pr_style);
  lv_obj_set_size(equal, 200, 80);
  lv_obj_align(equal, NULL, LV_ALIGN_IN_BOTTOM_MID, 100, 0);
  lv_obj_set_event_cb(equal, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      updateResult(true);
    }
  });
  
  static lv_style_t equal_label_style;
  lv_style_copy(&equal_label_style, &lv_style_plain);
  equal_label_style.text.color = lv_color_hex(0xFFFFFF);
  equal_label_style.text.font = &supermarket_30;
  lv_obj_t* equal_label = lv_label_create(equal, NULL);
  lv_label_set_style(equal_label, LV_LABEL_STYLE_MAIN, &equal_label_style);
  lv_label_set_text(equal_label, "=");
  /* ====== END of equal ====== */
  
  /* ========== plus ========== */
  static lv_style_t plus_rel_style;
  lv_style_copy(&plus_rel_style, &lv_style_plain);
  plus_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  plus_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  plus_rel_style.body.radius = 6;
  plus_rel_style.body.border.color = lv_color_hex(0x0B1928);
  plus_rel_style.body.border.width = 2;
  
  static lv_style_t plus_pr_style;
  lv_style_copy(&plus_pr_style, &lv_style_plain);
  plus_pr_style.body.main_color = lv_color_hex(0x336294);
  plus_pr_style.body.grad_color = lv_color_hex(0x10263C);
  plus_pr_style.body.radius = 6;
  plus_pr_style.body.border.color = lv_color_hex(0x0B1928);
  plus_pr_style.body.border.width = 2;
  
  lv_obj_t* plus = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(plus, event_handler); // TODO
  lv_btn_set_style(plus, LV_BTN_STATE_REL, &plus_rel_style);
  lv_btn_set_style(plus, LV_BTN_STATE_PR, &plus_pr_style);
  lv_obj_set_size(plus, 200, 80);
  lv_obj_align(plus, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, 0, 0);
  lv_obj_set_event_cb(plus, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      Operator = '+';
      updateResult();
    }
  });
  
  static lv_style_t plus_label_style;
  lv_style_copy(&plus_label_style, &lv_style_plain);
  plus_label_style.text.color = lv_color_hex(0xFFFFFF);
  plus_label_style.text.font = &supermarket_30;
  lv_obj_t* plus_label = lv_label_create(plus, NULL);
  lv_label_set_style(plus_label, LV_LABEL_STYLE_MAIN, &plus_label_style);
  lv_label_set_text(plus_label, "+");
  /* ====== END of plus ====== */
  
  /* ========== digi1 ========== */
  static lv_style_t digi1_rel_style;
  lv_style_copy(&digi1_rel_style, &lv_style_plain);
  digi1_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi1_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi1_rel_style.body.radius = 6;
  digi1_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi1_rel_style.body.border.width = 2;
  
  static lv_style_t digi1_pr_style;
  lv_style_copy(&digi1_pr_style, &lv_style_plain);
  digi1_pr_style.body.main_color = lv_color_hex(0x336294);
  digi1_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi1_pr_style.body.radius = 6;
  digi1_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi1_pr_style.body.border.width = 2;
  
  lv_obj_t* digi1 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi1, event_handler); // TODO
  lv_btn_set_style(digi1, LV_BTN_STATE_REL, &digi1_rel_style);
  lv_btn_set_style(digi1, LV_BTN_STATE_PR, &digi1_pr_style);
  lv_obj_set_size(digi1, 200, 80);
  lv_obj_align(digi1, NULL, LV_ALIGN_IN_LEFT_MID, 0, 120);
  lv_obj_set_event_cb(digi1, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('1');
      updateResult();
    }
  });
  
  static lv_style_t digi1_label_style;
  lv_style_copy(&digi1_label_style, &lv_style_plain);
  digi1_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi1_label_style.text.font = &supermarket_30;
  lv_obj_t* digi1_label = lv_label_create(digi1, NULL);
  lv_label_set_style(digi1_label, LV_LABEL_STYLE_MAIN, &digi1_label_style);
  lv_label_set_text(digi1_label, "1");
  /* ====== END of digi1 ====== */
  
  /* ========== digi2 ========== */
  static lv_style_t digi2_rel_style;
  lv_style_copy(&digi2_rel_style, &lv_style_plain);
  digi2_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi2_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi2_rel_style.body.radius = 6;
  digi2_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi2_rel_style.body.border.width = 2;
  
  static lv_style_t digi2_pr_style;
  lv_style_copy(&digi2_pr_style, &lv_style_plain);
  digi2_pr_style.body.main_color = lv_color_hex(0x336294);
  digi2_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi2_pr_style.body.radius = 6;
  digi2_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi2_pr_style.body.border.width = 2;
  
  lv_obj_t* digi2 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi2, event_handler); // TODO
  lv_btn_set_style(digi2, LV_BTN_STATE_REL, &digi2_rel_style);
  lv_btn_set_style(digi2, LV_BTN_STATE_PR, &digi2_pr_style);
  lv_obj_set_size(digi2, 200, 80);
  lv_obj_align(digi2, NULL, LV_ALIGN_CENTER, -100, 120);
  lv_obj_set_event_cb(digi2, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('2');
      updateResult();
    }
  });
  
  static lv_style_t digi2_label_style;
  lv_style_copy(&digi2_label_style, &lv_style_plain);
  digi2_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi2_label_style.text.font = &supermarket_30;
  lv_obj_t* digi2_label = lv_label_create(digi2, NULL);
  lv_label_set_style(digi2_label, LV_LABEL_STYLE_MAIN, &digi2_label_style);
  lv_label_set_text(digi2_label, "2");
  /* ====== END of digi2 ====== */
  
  /* ========== digi3 ========== */
  static lv_style_t digi3_rel_style;
  lv_style_copy(&digi3_rel_style, &lv_style_plain);
  digi3_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi3_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi3_rel_style.body.radius = 6;
  digi3_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi3_rel_style.body.border.width = 2;
  
  static lv_style_t digi3_pr_style;
  lv_style_copy(&digi3_pr_style, &lv_style_plain);
  digi3_pr_style.body.main_color = lv_color_hex(0x336294);
  digi3_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi3_pr_style.body.radius = 6;
  digi3_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi3_pr_style.body.border.width = 2;
  
  lv_obj_t* digi3 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi3, event_handler); // TODO
  lv_btn_set_style(digi3, LV_BTN_STATE_REL, &digi3_rel_style);
  lv_btn_set_style(digi3, LV_BTN_STATE_PR, &digi3_pr_style);
  lv_obj_set_size(digi3, 200, 80);
  lv_obj_align(digi3, NULL, LV_ALIGN_CENTER, 100, 120);
  lv_obj_set_event_cb(digi3, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('3');
      updateResult();
    }
  });
  
  static lv_style_t digi3_label_style;
  lv_style_copy(&digi3_label_style, &lv_style_plain);
  digi3_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi3_label_style.text.font = &supermarket_30;
  lv_obj_t* digi3_label = lv_label_create(digi3, NULL);
  lv_label_set_style(digi3_label, LV_LABEL_STYLE_MAIN, &digi3_label_style);
  lv_label_set_text(digi3_label, "3");
  /* ====== END of digi3 ====== */
  
  /* ========== minus ========== */
  static lv_style_t minus_rel_style;
  lv_style_copy(&minus_rel_style, &lv_style_plain);
  minus_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  minus_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  minus_rel_style.body.radius = 6;
  minus_rel_style.body.border.color = lv_color_hex(0x0B1928);
  minus_rel_style.body.border.width = 2;
  
  static lv_style_t minus_pr_style;
  lv_style_copy(&minus_pr_style, &lv_style_plain);
  minus_pr_style.body.main_color = lv_color_hex(0x336294);
  minus_pr_style.body.grad_color = lv_color_hex(0x10263C);
  minus_pr_style.body.radius = 6;
  minus_pr_style.body.border.color = lv_color_hex(0x0B1928);
  minus_pr_style.body.border.width = 2;
  
  lv_obj_t* minus = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(minus, event_handler); // TODO
  lv_btn_set_style(minus, LV_BTN_STATE_REL, &minus_rel_style);
  lv_btn_set_style(minus, LV_BTN_STATE_PR, &minus_pr_style);
  lv_obj_set_size(minus, 200, 80);
  lv_obj_align(minus, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 120);
  lv_obj_set_event_cb(minus, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      Operator = '-';
      updateResult();
    }
  });
  
  static lv_style_t minus_label_style;
  lv_style_copy(&minus_label_style, &lv_style_plain);
  minus_label_style.text.color = lv_color_hex(0xFFFFFF);
  minus_label_style.text.font = &supermarket_30;
  lv_obj_t* minus_label = lv_label_create(minus, NULL);
  lv_label_set_style(minus_label, LV_LABEL_STYLE_MAIN, &minus_label_style);
  lv_label_set_text(minus_label, "-");
  /* ====== END of minus ====== */
  
  /* ========== digi4 ========== */
  static lv_style_t digi4_rel_style;
  lv_style_copy(&digi4_rel_style, &lv_style_plain);
  digi4_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi4_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi4_rel_style.body.radius = 6;
  digi4_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi4_rel_style.body.border.width = 2;
  
  static lv_style_t digi4_pr_style;
  lv_style_copy(&digi4_pr_style, &lv_style_plain);
  digi4_pr_style.body.main_color = lv_color_hex(0x336294);
  digi4_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi4_pr_style.body.radius = 6;
  digi4_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi4_pr_style.body.border.width = 2;
  
  lv_obj_t* digi4 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi4, event_handler); // TODO
  lv_btn_set_style(digi4, LV_BTN_STATE_REL, &digi4_rel_style);
  lv_btn_set_style(digi4, LV_BTN_STATE_PR, &digi4_pr_style);
  lv_obj_set_size(digi4, 200, 80);
  lv_obj_align(digi4, NULL, LV_ALIGN_IN_LEFT_MID, 0, 40);
  lv_obj_set_event_cb(digi4, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('4');
      updateResult();
    }
  });
  
  static lv_style_t digi4_label_style;
  lv_style_copy(&digi4_label_style, &lv_style_plain);
  digi4_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi4_label_style.text.font = &supermarket_30;
  lv_obj_t* digi4_label = lv_label_create(digi4, NULL);
  lv_label_set_style(digi4_label, LV_LABEL_STYLE_MAIN, &digi4_label_style);
  lv_label_set_text(digi4_label, "4");
  /* ====== END of digi4 ====== */
  
  /* ========== digi5 ========== */
  static lv_style_t digi5_rel_style;
  lv_style_copy(&digi5_rel_style, &lv_style_plain);
  digi5_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi5_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi5_rel_style.body.radius = 6;
  digi5_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi5_rel_style.body.border.width = 2;
  
  static lv_style_t digi5_pr_style;
  lv_style_copy(&digi5_pr_style, &lv_style_plain);
  digi5_pr_style.body.main_color = lv_color_hex(0x336294);
  digi5_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi5_pr_style.body.radius = 6;
  digi5_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi5_pr_style.body.border.width = 2;
  
  lv_obj_t* digi5 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi5, event_handler); // TODO
  lv_btn_set_style(digi5, LV_BTN_STATE_REL, &digi5_rel_style);
  lv_btn_set_style(digi5, LV_BTN_STATE_PR, &digi5_pr_style);
  lv_obj_set_size(digi5, 200, 80);
  lv_obj_align(digi5, NULL, LV_ALIGN_CENTER, -100, 40);
  lv_obj_set_event_cb(digi5, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('5');
      updateResult();
    }
  });
  
  static lv_style_t digi5_label_style;
  lv_style_copy(&digi5_label_style, &lv_style_plain);
  digi5_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi5_label_style.text.font = &supermarket_30;
  lv_obj_t* digi5_label = lv_label_create(digi5, NULL);
  lv_label_set_style(digi5_label, LV_LABEL_STYLE_MAIN, &digi5_label_style);
  lv_label_set_text(digi5_label, "5");
  /* ====== END of digi5 ====== */
  
  /* ========== digi6 ========== */
  static lv_style_t digi6_rel_style;
  lv_style_copy(&digi6_rel_style, &lv_style_plain);
  digi6_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi6_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi6_rel_style.body.radius = 6;
  digi6_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi6_rel_style.body.border.width = 2;
  
  static lv_style_t digi6_pr_style;
  lv_style_copy(&digi6_pr_style, &lv_style_plain);
  digi6_pr_style.body.main_color = lv_color_hex(0x336294);
  digi6_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi6_pr_style.body.radius = 6;
  digi6_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi6_pr_style.body.border.width = 2;
  
  lv_obj_t* digi6 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi6, event_handler); // TODO
  lv_btn_set_style(digi6, LV_BTN_STATE_REL, &digi6_rel_style);
  lv_btn_set_style(digi6, LV_BTN_STATE_PR, &digi6_pr_style);
  lv_obj_set_size(digi6, 200, 80);
  lv_obj_align(digi6, NULL, LV_ALIGN_CENTER, 100, 40);
  lv_obj_set_event_cb(digi6, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('6');
      updateResult();
    }
  });
  
  static lv_style_t digi6_label_style;
  lv_style_copy(&digi6_label_style, &lv_style_plain);
  digi6_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi6_label_style.text.font = &supermarket_30;
  lv_obj_t* digi6_label = lv_label_create(digi6, NULL);
  lv_label_set_style(digi6_label, LV_LABEL_STYLE_MAIN, &digi6_label_style);
  lv_label_set_text(digi6_label, "6");
  /* ====== END of digi6 ====== */
  
  /* ========== multiplication ========== */
  static lv_style_t multiplication_rel_style;
  lv_style_copy(&multiplication_rel_style, &lv_style_plain);
  multiplication_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  multiplication_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  multiplication_rel_style.body.radius = 6;
  multiplication_rel_style.body.border.color = lv_color_hex(0x0B1928);
  multiplication_rel_style.body.border.width = 2;
  
  static lv_style_t multiplication_pr_style;
  lv_style_copy(&multiplication_pr_style, &lv_style_plain);
  multiplication_pr_style.body.main_color = lv_color_hex(0x336294);
  multiplication_pr_style.body.grad_color = lv_color_hex(0x10263C);
  multiplication_pr_style.body.radius = 6;
  multiplication_pr_style.body.border.color = lv_color_hex(0x0B1928);
  multiplication_pr_style.body.border.width = 2;
  
  lv_obj_t* multiplication = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(multiplication, event_handler); // TODO
  lv_btn_set_style(multiplication, LV_BTN_STATE_REL, &multiplication_rel_style);
  lv_btn_set_style(multiplication, LV_BTN_STATE_PR, &multiplication_pr_style);
  lv_obj_set_size(multiplication, 200, 80);
  lv_obj_align(multiplication, NULL, LV_ALIGN_IN_RIGHT_MID, 0, 40);
  lv_obj_set_event_cb(multiplication, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      Operator = '*';
      updateResult();
    }
  });
  
  static lv_style_t multiplication_label_style;
  lv_style_copy(&multiplication_label_style, &lv_style_plain);
  multiplication_label_style.text.color = lv_color_hex(0xFFFFFF);
  multiplication_label_style.text.font = &supermarket_60;
  lv_obj_t* multiplication_label = lv_label_create(multiplication, NULL);
  lv_label_set_style(multiplication_label, LV_LABEL_STYLE_MAIN, &multiplication_label_style);
  lv_label_set_text(multiplication_label, "*");
  /* ====== END of multiplication ====== */
  
  /* ========== digi7 ========== */
  static lv_style_t digi7_rel_style;
  lv_style_copy(&digi7_rel_style, &lv_style_plain);
  digi7_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi7_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi7_rel_style.body.radius = 6;
  digi7_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi7_rel_style.body.border.width = 2;
  
  static lv_style_t digi7_pr_style;
  lv_style_copy(&digi7_pr_style, &lv_style_plain);
  digi7_pr_style.body.main_color = lv_color_hex(0x336294);
  digi7_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi7_pr_style.body.radius = 6;
  digi7_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi7_pr_style.body.border.width = 2;
  
  lv_obj_t* digi7 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi7, event_handler); // TODO
  lv_btn_set_style(digi7, LV_BTN_STATE_REL, &digi7_rel_style);
  lv_btn_set_style(digi7, LV_BTN_STATE_PR, &digi7_pr_style);
  lv_obj_set_size(digi7, 200, 80);
  lv_obj_align(digi7, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 160);
  lv_obj_set_event_cb(digi7, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('7');
      updateResult();
    }
  });
  
  static lv_style_t digi7_label_style;
  lv_style_copy(&digi7_label_style, &lv_style_plain);
  digi7_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi7_label_style.text.font = &supermarket_30;
  lv_obj_t* digi7_label = lv_label_create(digi7, NULL);
  lv_label_set_style(digi7_label, LV_LABEL_STYLE_MAIN, &digi7_label_style);
  lv_label_set_text(digi7_label, "7");
  /* ====== END of digi7 ====== */
  
  /* ========== digi8 ========== */
  static lv_style_t digi8_rel_style;
  lv_style_copy(&digi8_rel_style, &lv_style_plain);
  digi8_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi8_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi8_rel_style.body.radius = 6;
  digi8_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi8_rel_style.body.border.width = 2;
  
  static lv_style_t digi8_pr_style;
  lv_style_copy(&digi8_pr_style, &lv_style_plain);
  digi8_pr_style.body.main_color = lv_color_hex(0x336294);
  digi8_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi8_pr_style.body.radius = 6;
  digi8_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi8_pr_style.body.border.width = 2;
  
  lv_obj_t* digi8 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi8, event_handler); // TODO
  lv_btn_set_style(digi8, LV_BTN_STATE_REL, &digi8_rel_style);
  lv_btn_set_style(digi8, LV_BTN_STATE_PR, &digi8_pr_style);
  lv_obj_set_size(digi8, 200, 80);
  lv_obj_align(digi8, NULL, LV_ALIGN_IN_TOP_MID, -100, 160);
  lv_obj_set_event_cb(digi8, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('8');
      updateResult();
    }
  });
  
  static lv_style_t digi8_label_style;
  lv_style_copy(&digi8_label_style, &lv_style_plain);
  digi8_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi8_label_style.text.font = &supermarket_30;
  lv_obj_t* digi8_label = lv_label_create(digi8, NULL);
  lv_label_set_style(digi8_label, LV_LABEL_STYLE_MAIN, &digi8_label_style);
  lv_label_set_text(digi8_label, "8");
  /* ====== END of digi8 ====== */
  
  /* ========== digi9 ========== */
  static lv_style_t digi9_rel_style;
  lv_style_copy(&digi9_rel_style, &lv_style_plain);
  digi9_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  digi9_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  digi9_rel_style.body.radius = 6;
  digi9_rel_style.body.border.color = lv_color_hex(0x0B1928);
  digi9_rel_style.body.border.width = 2;
  
  static lv_style_t digi9_pr_style;
  lv_style_copy(&digi9_pr_style, &lv_style_plain);
  digi9_pr_style.body.main_color = lv_color_hex(0x336294);
  digi9_pr_style.body.grad_color = lv_color_hex(0x10263C);
  digi9_pr_style.body.radius = 6;
  digi9_pr_style.body.border.color = lv_color_hex(0x0B1928);
  digi9_pr_style.body.border.width = 2;
  
  lv_obj_t* digi9 = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(digi9, event_handler); // TODO
  lv_btn_set_style(digi9, LV_BTN_STATE_REL, &digi9_rel_style);
  lv_btn_set_style(digi9, LV_BTN_STATE_PR, &digi9_pr_style);
  lv_obj_set_size(digi9, 200, 80);
  lv_obj_align(digi9, NULL, LV_ALIGN_IN_TOP_MID, 100, 160);
  
  static lv_style_t digi9_label_style;
  lv_style_copy(&digi9_label_style, &lv_style_plain);
  digi9_label_style.text.color = lv_color_hex(0xFFFFFF);
  digi9_label_style.text.font = &supermarket_30;
  lv_obj_t* digi9_label = lv_label_create(digi9, NULL);
  lv_label_set_style(digi9_label, LV_LABEL_STYLE_MAIN, &digi9_label_style);
  lv_label_set_text(digi9_label, "9");
  lv_obj_set_event_cb(digi9, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      addOperand('9');
      updateResult();
    }
  });
  /* ====== END of digi9 ====== */
  
  /* ========== divide ========== */
  static lv_style_t divide_rel_style;
  lv_style_copy(&divide_rel_style, &lv_style_plain);
  divide_rel_style.body.main_color = lv_color_hex(0x76A2D0);
  divide_rel_style.body.grad_color = lv_color_hex(0x193A5D);
  divide_rel_style.body.radius = 6;
  divide_rel_style.body.border.color = lv_color_hex(0x0B1928);
  divide_rel_style.body.border.width = 2;
  
  static lv_style_t divide_pr_style;
  lv_style_copy(&divide_pr_style, &lv_style_plain);
  divide_pr_style.body.main_color = lv_color_hex(0x336294);
  divide_pr_style.body.grad_color = lv_color_hex(0x10263C);
  divide_pr_style.body.radius = 6;
  divide_pr_style.body.border.color = lv_color_hex(0x0B1928);
  divide_pr_style.body.border.width = 2;
  
  lv_obj_t* divide = lv_btn_create(calculatorScreen, NULL);
  // lv_obj_set_event_cb(divide, event_handler); // TODO
  lv_btn_set_style(divide, LV_BTN_STATE_REL, &divide_rel_style);
  lv_btn_set_style(divide, LV_BTN_STATE_PR, &divide_pr_style);
  lv_obj_set_size(divide, 200, 80);
  lv_obj_align(divide, NULL, LV_ALIGN_IN_TOP_RIGHT, 0, 160);
  lv_obj_set_event_cb(divide, [](lv_obj_t* obj, lv_event_t event) {
    if(event == LV_EVENT_CLICKED) {
      Operator = '/';
      updateResult();
    }
  });
  
  static lv_style_t divide_label_style;
  lv_style_copy(&divide_label_style, &lv_style_plain);
  divide_label_style.text.color = lv_color_hex(0xFFFFFF);
  divide_label_style.text.font = &supermarket_30;
  lv_obj_t* divide_label = lv_label_create(divide, NULL);
  lv_label_set_style(divide_label, LV_LABEL_STYLE_MAIN, &divide_label_style);
  lv_label_set_text(divide_label, "/");
  /* ====== END of divide ====== */
  
  /* ========== result ========== */
  static lv_style_t result_style;
  lv_style_copy(&result_style, &lv_style_plain);
  result_style.text.color = lv_color_hex(0xFFFFFF);
  result_style.text.font = &supermarket_60;
  
  result = lv_label_create(calculatorScreen, NULL);
  lv_label_set_style(result, LV_LABEL_STYLE_MAIN, &result_style);
  lv_label_set_long_mode(result, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(result, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(result, "0");
  lv_obj_set_size(result, 0, 0);
  lv_obj_align(result, NULL, LV_ALIGN_IN_TOP_RIGHT, -40, 30);
  /* ====== END of result ====== */

  lv_obj_set_auto_realign(result, true);
}

void updateResult(bool equal) {
  if (equal) {
    if (Operator == '+') {
      Result = Operand1.toFloat() + Operand2.toFloat();
    } else if (Operator == '-') {
      Result = Operand1.toFloat() - Operand2.toFloat();
    } else if (Operator == '*') {
      Result = Operand1.toFloat() * Operand2.toFloat();
    } else if (Operator == '/') {
      Result = Operand1.toFloat() / Operand2.toFloat();
    }
    lv_label_set_text(result, Result.c_str());
    Operand1 = "";
    Operator = '\0';
    Operand2 = "";
  } else {
    String txt = Operand1 + Operator + Operand2;
    lv_label_set_text(result, txt.c_str());
  }
}

void addOperand(char digi) {
  if (Operator != '\0') {
    Operand2 += digi;
  } else {
    Operand1 += digi;
  }
}
