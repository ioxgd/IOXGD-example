#include <bsp.h>
#include <sysctl.h>
#include <IOXGD.h>

lv_obj_t* screenSelectTime;
lv_obj_t* screenQRCode;
lv_obj_t* screenCountdown;

extern lv_font_t supermarket_60;
extern lv_font_t supermarket_160;
extern lv_font_t supermarket_40;

int loop1(void *ctx) ;

lv_obj_t* loader1;
lv_obj_t* timeoutLabel;

#define BUZZER_PIN 37

uint8_t qrCodePage_countdown_flag = 0;

bool trigBeep = false;
bool beeping = false;

void select_plan_cb(uint8_t plan) {
  Serial.println("Click " + String(plan));
  // lv_obj_set_hidden(loader1, false);

  // Show QR Code page
  lv_scr_load(screenQRCode);

  qrCodePage_countdown_flag = 1;

  trigBeep = true;
}

static void select_plan1_cb(lv_obj_t * obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    select_plan_cb(1);
  }
}

static void select_plan2_cb(lv_obj_t * obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    select_plan_cb(2);
  }
}

static void select_plan3_cb(lv_obj_t * obj, lv_event_t event) {
  if (event == LV_EVENT_CLICKED) {
    select_plan_cb(3);
  }
}

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);

  Serial.begin(115200);
  Serial.println("Core " + String(current_coreid()) + " runing");

  gd.begin();

  // Create a screen select time
  screenSelectTime = lv_obj_create(NULL, NULL);

  static lv_style_t screenSelectTimeStyle;
  lv_style_copy(&screenSelectTimeStyle, &lv_style_plain);
  screenSelectTimeStyle.body.main_color = lv_color_hex(0xf2f7fc);
  screenSelectTimeStyle.body.grad_color = lv_color_hex(0xf2f7fc);
  lv_obj_set_style(screenSelectTime, &screenSelectTimeStyle);

  // Title
  static lv_style_t titleStyle;
  lv_style_copy(&titleStyle, &lv_style_plain);
  titleStyle.text.font = &supermarket_60;
  titleStyle.text.color = lv_color_hex(0x424949);

  lv_obj_t* titleLabel = lv_label_create(screenSelectTime, NULL);
  lv_label_set_style(titleLabel, LV_LABEL_STYLE_MAIN, &titleStyle);
  lv_label_set_text(titleLabel, "เลือกเวลาชาร์จ");
  lv_label_set_align(titleLabel, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(titleLabel, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);

  // Container
  static lv_style_t ContainerStyle;
  lv_style_copy(&ContainerStyle, &lv_style_plain);
  ContainerStyle.body.main_color = lv_color_hex(0xffffff);
  ContainerStyle.body.grad_color = lv_color_hex(0xffffff);
  ContainerStyle.body.radius = 0;
  ContainerStyle.body.border.width = 1;
  ContainerStyle.body.border.color = lv_color_hex(0xe8e8e8);
  ContainerStyle.body.padding.top = 0;
  ContainerStyle.body.padding.inner = 0;

  // Min style
  static lv_style_t minStyle;
  lv_style_copy(&minStyle, &lv_style_plain);
  minStyle.text.font = &supermarket_40;
  minStyle.text.color = lv_color_hex(0xf07c1f);

  // Baht Number style
  static lv_style_t bahtNumberStyle;
  lv_style_copy(&bahtNumberStyle, &lv_style_plain);
  bahtNumberStyle.text.font = &supermarket_160;
  bahtNumberStyle.text.color = lv_color_hex(0x323232);

  // Baht Text style
  static lv_style_t bahtTextStyle;
  lv_style_copy(&bahtTextStyle, &lv_style_plain);
  bahtTextStyle.text.font = &supermarket_60;
  bahtTextStyle.text.color = lv_color_hex(0x9c9c9c);

  // Container1
  lv_obj_t* Container1 = lv_cont_create(screenSelectTime, NULL);
  lv_cont_set_fit(Container1, LV_FIT_NONE);
  lv_cont_set_layout(Container1, LV_LAYOUT_OFF);
  lv_obj_set_size(Container1, 200, 290);
  lv_obj_align(Container1, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 50, 0);
  lv_obj_set_style(Container1, &ContainerStyle);

  lv_obj_t* min1Label = lv_label_create(Container1, NULL);
  lv_label_set_style(min1Label, LV_LABEL_STYLE_MAIN, &minStyle);
  lv_label_set_text(min1Label, "10 นาที");
  lv_obj_align(min1Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);

  lv_obj_t* bahtNumber1Label = lv_label_create(Container1, NULL);
  lv_label_set_style(bahtNumber1Label, LV_LABEL_STYLE_MAIN, &bahtNumberStyle);
  lv_label_set_text(bahtNumber1Label, "10");
  lv_obj_align(bahtNumber1Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 60);

  lv_obj_t* bahtText1Label = lv_label_create(Container1, NULL);
  lv_label_set_style(bahtText1Label, LV_LABEL_STYLE_MAIN, &bahtTextStyle);
  lv_label_set_text(bahtText1Label, "บาท");
  lv_obj_align(bahtText1Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 200);

  // Container2
  lv_obj_t* Container2 = lv_cont_create(screenSelectTime, NULL);
  lv_cont_set_fit(Container2, LV_FIT_NONE);
  lv_cont_set_layout(Container2, LV_LAYOUT_OFF);
  lv_obj_set_size(Container2, 200, 350);
  lv_obj_align(Container2, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, 0);
  lv_obj_set_style(Container2, &ContainerStyle);

  lv_obj_t* min2Label = lv_label_create(Container2, NULL);
  lv_label_set_style(min2Label, LV_LABEL_STYLE_MAIN, &minStyle);
  lv_label_set_text(min2Label, "30 นาที");
  lv_obj_align(min2Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 50);

  lv_obj_t* bahtNumber2Label = lv_label_create(Container2, NULL);
  lv_label_set_style(bahtNumber2Label, LV_LABEL_STYLE_MAIN, &bahtNumberStyle);
  lv_label_set_text(bahtNumber2Label, "20");
  lv_obj_align(bahtNumber2Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 80);

  lv_obj_t* bahtText2Label = lv_label_create(Container2, NULL);
  lv_label_set_style(bahtText2Label, LV_LABEL_STYLE_MAIN, &bahtTextStyle);
  lv_label_set_text(bahtText2Label, "บาท");
  lv_obj_align(bahtText2Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 220);

  // Container3
  lv_obj_t* Container3 = lv_cont_create(screenSelectTime, NULL);
  lv_cont_set_fit(Container3, LV_FIT_NONE);
  lv_cont_set_layout(Container3, LV_LAYOUT_OFF);
  lv_obj_set_size(Container3, 200, 290);
  lv_obj_align(Container3, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -50, 0);
  lv_obj_set_style(Container3, &ContainerStyle);

  lv_obj_t* min3Label = lv_label_create(Container3, NULL);
  lv_label_set_style(min3Label, LV_LABEL_STYLE_MAIN, &minStyle);
  lv_label_set_text(min3Label, "60 นาที");
  lv_obj_align(min3Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 30);

  lv_obj_t* bahtNumber3Label = lv_label_create(Container3, NULL);
  lv_label_set_style(bahtNumber3Label, LV_LABEL_STYLE_MAIN, &bahtNumberStyle);
  lv_label_set_text(bahtNumber3Label, "30");
  lv_obj_align(bahtNumber3Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 60);

  lv_obj_t* bahtText3Label = lv_label_create(Container3, NULL);
  lv_label_set_style(bahtText3Label, LV_LABEL_STYLE_MAIN, &bahtTextStyle);
  lv_label_set_text(bahtText3Label, "บาท");
  lv_obj_align(bahtText3Label, NULL, LV_ALIGN_IN_TOP_MID, 0, 200);

  lv_obj_set_click(Container1, true);
  lv_obj_set_event_cb(Container1, select_plan1_cb);

  lv_obj_set_click(Container2, true);
  lv_obj_set_event_cb(Container2, select_plan2_cb);

  lv_obj_set_click(Container3, true);
  lv_obj_set_event_cb(Container3, select_plan3_cb);

  // Loader
  static lv_style_t style;
  lv_style_copy(&style, &lv_style_plain);
  style.line.width = 10;                         /*10 px thick arc*/
  style.line.color = lv_color_hex3(0x258);       /*Blueish arc color*/

  style.body.border.color = lv_color_hex3(0xBBB); /*Gray background color*/
  style.body.border.width = 10;
  style.body.padding.left = 0;

  loader1 = lv_preload_create(screenSelectTime, NULL);
  lv_obj_set_size(loader1, 100, 100);
  lv_obj_align(loader1, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_preload_set_style(loader1, LV_PRELOAD_STYLE_MAIN, &style);
  lv_obj_set_hidden(loader1, true);

  // QR Code
  screenQRCode = lv_obj_create(NULL, NULL);

  static lv_style_t screenQRCodeStyle;
  lv_style_copy(&screenQRCodeStyle, &lv_style_plain);
  screenQRCodeStyle.body.main_color = lv_color_hex(0xf2f7fc);
  screenQRCodeStyle.body.grad_color = lv_color_hex(0xf2f7fc);
  lv_obj_set_style(screenQRCode, &screenQRCodeStyle);

  static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(53 * 6, 53 * 6)];

  lv_obj_t* canvasQRCode = lv_canvas_create(screenQRCode, NULL);
  lv_canvas_set_buffer(canvasQRCode, cbuf, 53 * 6, 53 * 6, LV_IMG_CF_TRUE_COLOR);
  lv_canvas_fill_bg(canvasQRCode, LV_COLOR_WHITE);
  lv_obj_align(canvasQRCode, NULL, LV_ALIGN_IN_TOP_LEFT, 50, 50);
  drawQRCode(canvasQRCode, "Good moring");

  static lv_style_t timeoutLabelStyle;
  lv_style_copy(&timeoutLabelStyle, &lv_style_plain);
  timeoutLabelStyle.text.font = &supermarket_40;
  timeoutLabelStyle.text.color = lv_color_hex(0xff0000);

  timeoutLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(timeoutLabel, LV_LABEL_STYLE_MAIN, &timeoutLabelStyle);
  lv_label_set_align(timeoutLabel, LV_LABEL_ALIGN_CENTER);
  lv_obj_align(timeoutLabel, NULL, LV_ALIGN_IN_BOTTOM_LEFT, 50, -50);
  lv_label_set_long_mode(timeoutLabel, LV_LABEL_LONG_CROP);
  lv_obj_set_width(timeoutLabel, 318);
  lv_label_set_text(timeoutLabel, "เหลือเวลาอีก 90 วินาที");

  // Label
  static lv_style_t labelStyle;
  lv_style_copy(&labelStyle, &lv_style_plain);
  labelStyle.text.font = &supermarket_40;
  labelStyle.text.color = lv_color_hex(0x323232);

  static lv_style_t labelBigTextStyle;
  lv_style_copy(&labelBigTextStyle, &lv_style_plain);
  labelBigTextStyle.text.font = &supermarket_60;
  labelBigTextStyle.text.color = lv_color_hex(0x323232);

  // Time
  lv_obj_t * timeLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(timeLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_obj_align(timeLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 400, 30);
  lv_label_set_text(timeLabel, "เวลา");

  lv_obj_t * timeNumberLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(timeNumberLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_label_set_long_mode(timeNumberLabel, LV_LABEL_LONG_BREAK);
  lv_obj_set_width(timeNumberLabel, 100);
  lv_label_set_align(timeNumberLabel, LV_LABEL_ALIGN_RIGHT);
  lv_obj_align(timeNumberLabel, NULL, LV_ALIGN_IN_TOP_RIGHT, -170, 30);
  lv_label_set_text(timeNumberLabel, "10");

  lv_obj_t * timeTextLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(timeTextLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_label_set_align(timeTextLabel, LV_LABEL_ALIGN_RIGHT);
  lv_obj_align(timeTextLabel, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 30);
  lv_label_set_text(timeTextLabel, "นาที");

  // Price
  lv_obj_t * priceLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(priceLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_obj_align(priceLabel, NULL, LV_ALIGN_IN_TOP_LEFT, 400, 100);
  lv_label_set_text(priceLabel, "ราคา");

  lv_obj_t * priceNumberLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(priceNumberLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_label_set_long_mode(priceNumberLabel, LV_LABEL_LONG_BREAK);
  lv_obj_set_width(priceNumberLabel, 100);
  lv_label_set_align(priceNumberLabel, LV_LABEL_ALIGN_RIGHT);
  lv_obj_align(priceNumberLabel, NULL, LV_ALIGN_IN_TOP_RIGHT, -170, 100);
  lv_label_set_text(priceNumberLabel, "10");

  lv_obj_t * priceTextLabel = lv_label_create(screenQRCode, NULL);
  lv_label_set_style(priceTextLabel, LV_LABEL_STYLE_MAIN, &labelBigTextStyle);
  lv_label_set_align(priceTextLabel, LV_LABEL_ALIGN_RIGHT);
  lv_obj_align(priceTextLabel, NULL, LV_ALIGN_IN_TOP_RIGHT, -50, 100);
  lv_label_set_text(priceTextLabel, "บาท");

  // Confirm Button style
  static lv_style_t confirmButtonRelStyle;
  lv_style_copy(&confirmButtonRelStyle, &lv_style_plain);
  confirmButtonRelStyle.body.main_color = lv_color_hex(0x17A589);
  confirmButtonRelStyle.body.grad_color = lv_color_hex(0x17A589);
  confirmButtonRelStyle.body.border.color = lv_color_hex(0x17A589);
  confirmButtonRelStyle.body.border.width = 10;
  confirmButtonRelStyle.body.radius = 10;

  static lv_style_t confirmButtonPrStyle;
  lv_style_copy(&confirmButtonPrStyle, &confirmButtonRelStyle);
  confirmButtonPrStyle.body.main_color = lv_color_hex(0x148F77);
  confirmButtonPrStyle.body.grad_color = lv_color_hex(0x148F77);
  confirmButtonPrStyle.body.border.color = lv_color_hex(0x148F77);

  static lv_style_t buttonLabelStyle;
  lv_style_copy(&buttonLabelStyle, &lv_style_plain);
  buttonLabelStyle.text.font = &supermarket_40;
  buttonLabelStyle.text.color = lv_color_hex(0xffffff);
  
  lv_obj_t * confirmButton = lv_btn_create(screenQRCode, NULL);
  // lv_obj_set_event_cb(confirmButton, event_handler);
  lv_btn_set_style(confirmButton, LV_BTN_STATE_REL, &confirmButtonRelStyle);
  lv_btn_set_style(confirmButton, LV_BTN_STATE_PR, &confirmButtonPrStyle);
  lv_obj_align(confirmButton, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -300, -130);
  lv_obj_set_width(confirmButton, 350);

  lv_obj_t * confirmButtonLabel = lv_label_create(confirmButton, NULL);
  lv_label_set_style(confirmButtonLabel, LV_LABEL_STYLE_MAIN, &buttonLabelStyle);
  lv_label_set_text(confirmButtonLabel, "ยืนยัน");


  // Cancel Button style
  static lv_style_t cancelButtonRelStyle;
  lv_style_copy(&cancelButtonRelStyle, &lv_style_plain);
  cancelButtonRelStyle.body.main_color = lv_color_hex(0xE74C3C);
  cancelButtonRelStyle.body.grad_color = lv_color_hex(0xE74C3C);
  cancelButtonRelStyle.body.border.color = lv_color_hex(0xE74C3C);
  cancelButtonRelStyle.body.border.width = 10;
  cancelButtonRelStyle.body.radius = 10;

  static lv_style_t cancelButtonPrStyle;
  lv_style_copy(&cancelButtonPrStyle, &confirmButtonRelStyle);
  cancelButtonPrStyle.body.main_color = lv_color_hex(0xCB4335);
  cancelButtonPrStyle.body.grad_color = lv_color_hex(0xCB4335);
  cancelButtonPrStyle.body.border.color = lv_color_hex(0xCB4335);
  
  lv_obj_t * cancelButton = lv_btn_create(screenQRCode, NULL);
  // lv_obj_set_event_cb(confirmButton, event_handler);
  lv_btn_set_style(cancelButton, LV_BTN_STATE_REL, &cancelButtonRelStyle);
  lv_btn_set_style(cancelButton, LV_BTN_STATE_PR, &cancelButtonPrStyle);
  lv_obj_align(cancelButton, NULL, LV_ALIGN_IN_BOTTOM_RIGHT, -300, -50);
  lv_obj_set_width(cancelButton, 350);

  lv_obj_t * cancelButtonLabel = lv_label_create(cancelButton, NULL);
  lv_label_set_style(cancelButtonLabel, LV_LABEL_STYLE_MAIN, &buttonLabelStyle);
  lv_label_set_text(cancelButtonLabel, "ยกเลิก");

  screenCountdown = lv_obj_create(NULL, NULL);

  // Load screen
  // lv_scr_load(screenSelectTime);
  lv_scr_load(screenQRCode);

  // Use core 1 to run littlevgl loop
  register_core1(loop1, NULL);
}

void loop() {
  static uint32_t timer = millis();
  if (trigBeep) {
    if (!beeping) {
      tone(BUZZER_PIN, 4E3);
      beeping = true;
      timer = millis();
    } else {
      if ((millis() - timer) > 50) {
        noTone(BUZZER_PIN);
        beeping = false;
        trigBeep = false;
      }
    }
  }

  if (qrCodePage_countdown_flag == 1) {
    static uint64_t strat = millis();
    static uint8_t i = 90;
    if ((millis() - strat) > 1000){
      strat = millis();
      
      lv_label_set_text(timeoutLabel, String(String("เหลือเวลาอีก ") + i + String(" วินาที")).c_str());
      if (i == 0) {
        lv_scr_load(screenSelectTime);
        i = 90;
        qrCodePage_countdown_flag = 0;
      } else {
        i--;
      }
      // delay(1000);
    }
  }
}

int loop1(void *ctx) {
  Serial.println("Core " + String(current_coreid()) + " runing");
  while (1) {
    lv_task_handler(); /* let the GUI do its work */
    delay(5);
  }
}
