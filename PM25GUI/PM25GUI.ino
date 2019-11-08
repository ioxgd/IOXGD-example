/* ======== Generate by IOXGD Designer ======== */

#include <IOXGD.h>

LV_FONT_DECLARE(supermarket_60);
LV_FONT_DECLARE(supermarket_20);
LV_FONT_DECLARE(supermarket_200);

lv_obj_t* txt2;
lv_obj_t* txt5;

static lv_style_t style_screen;

void load_page() {
  lv_style_copy(&style_screen, &lv_style_plain);
  style_screen.body.main_color = lv_color_hex(0x00CC00);
  style_screen.body.grad_color = lv_color_hex(0x00CC00);
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
  lv_label_set_text(txt1, "มิเตอร์วัดค่าฝุ่น PM2.5");
  lv_obj_set_size(txt1, 0, 0);
  lv_obj_align(txt1, NULL, LV_ALIGN_IN_TOP_MID, 0, 20);
  /* ====== END of txt1 ====== */

  /* ========== txt2 ========== */
  static lv_style_t txt2_style;
  lv_style_copy(&txt2_style, &lv_style_plain);
  txt2_style.text.color = lv_color_hex(0x000000);
  txt2_style.text.font = &supermarket_200;

  txt2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt2, LV_LABEL_STYLE_MAIN, &txt2_style);
  lv_label_set_long_mode(txt2, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt2, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt2, "0");
  lv_obj_set_size(txt2, 0, 0);
  lv_obj_align(txt2, NULL, LV_ALIGN_CENTER, 0, 20);
  /* ====== END of txt2 ====== */

  /* ========== txt3 ========== */
  static lv_style_t txt3_style;
  lv_style_copy(&txt3_style, &lv_style_plain);
  txt3_style.text.color = lv_color_hex(0x000000);
  txt3_style.text.font = &supermarket_20;

  lv_obj_t* txt3 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt3, LV_LABEL_STYLE_MAIN, &txt3_style);
  lv_label_set_long_mode(txt3, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt3, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt3, "ฝุ่นละออง (PM) ที่มีขนาดเส้นผ่าศูนย์กลางน้อยกว่า 2.5 ไมโครเมตร");
  lv_obj_set_size(txt3, 0, 0);
  lv_obj_align(txt3, NULL, LV_ALIGN_IN_TOP_MID, 0, 110);
  /* ====== END of txt3 ====== */

  /* ========== txt5 ========== */
  static lv_style_t txt5_style;
  lv_style_copy(&txt5_style, &lv_style_plain);
  txt5_style.text.color = lv_color_hex(0x000000);
  txt5_style.text.font = &supermarket_20;

  txt5 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_style(txt5, LV_LABEL_STYLE_MAIN, &txt5_style);
  lv_label_set_long_mode(txt5, LV_LABEL_LONG_EXPAND);
  lv_label_set_align(txt5, LV_LABEL_ALIGN_LEFT);
  lv_label_set_text(txt5, "น้อยถึงไม่มีความเสี่ยง");
  lv_obj_set_size(txt5, 0, 0);
  lv_obj_align(txt5, NULL, LV_ALIGN_CENTER, 0, 150);
  /* ====== END of txt5 ====== */

  lv_obj_set_auto_realign(txt2, true);
  lv_obj_set_auto_realign(txt5, true);
}

int PM_SP_UG_1_0, PM_SP_UG_2_5, PM_SP_UG_10_0;
int PM_AE_UG_1_0, PM_AE_UG_2_5, PM_AE_UG_10_0;

bool pms_process() {
  if (!Serial1.available()) {
    return false;
  }
  uint8_t ch = Serial1.read();

  static uint8_t dataIndex = 0;
  static uint16_t checksum = 0;
  static uint16_t calculatedChecksum = 0;
  static uint16_t frameLen = 0;
  static uint8_t payload[30];

  switch (dataIndex) {
    case 0:
      if (ch != 0x42) {
        return false;
      }
      calculatedChecksum = ch;
      break;

    case 1:
      if (ch != 0x4D) {
        dataIndex = 0;
        return false;
      }
      calculatedChecksum += ch;
      break;

    case 2:
      frameLen = ch << 8;
      calculatedChecksum += ch;
      break;

    case 3:
      frameLen |= ch;
      calculatedChecksum += ch;
      break;

    default:
      if (dataIndex == frameLen + 2) {
        checksum = ch << 8;
      } else if (dataIndex == frameLen + 2 + 1) {
        checksum |= ch;

        if (calculatedChecksum == checksum) {
          PM_SP_UG_1_0 = (((uint16_t)payload[0]) << 8) | payload[1];
          PM_SP_UG_2_5 = (((uint16_t)payload[2]) << 8) | payload[3];
          PM_SP_UG_10_0 = (((uint16_t)payload[4]) << 8) | payload[5];

          PM_AE_UG_1_0 = (((uint16_t)payload[6]) << 8) | payload[7];
          PM_AE_UG_2_5 = (((uint16_t)payload[8]) << 8) | payload[9];
          PM_AE_UG_10_0 = (((uint16_t)payload[10]) << 8) | payload[11];
        } else {
          Serial.println("Error checksum");
        }

        dataIndex = 0;
        return true;
      } else {
        calculatedChecksum += ch;
        uint8_t payloadIndex = dataIndex - 4;

        if (payloadIndex < sizeof(payload)) {
          payload[payloadIndex] = ch;
        }
      }
  }

  dataIndex++;
  return false;
}

void setup() {
  Serial.begin(9600);
  Serial1.begin(9600, 8, -1);

  gd.begin(SETUP_LVGL);

  load_page();

  xTaskCreate([](void*) {
    while (1) {
      if (pms_process()) {
        Serial.print("PM2.5: ");
        Serial.println(PM_AE_UG_2_5);
        
        lv_label_set_text(txt2, String(PM_AE_UG_2_5).c_str());

        if (PM_AE_UG_2_5 <= 12) {
          lv_label_set_text(txt5, "อากาศดีมาก");

          style_screen.body.main_color = lv_color_hex(0x00CC00);
          style_screen.body.grad_color = lv_color_hex(0x00CC00);
          lv_obj_set_style(lv_scr_act(), &style_screen);
        } else if (PM_AE_UG_2_5 <= 35) {
          lv_label_set_text(txt5, "อากาศดี");

          style_screen.body.main_color = lv_color_hex(0xFFFF00);
          style_screen.body.grad_color = lv_color_hex(0xFFFF00);
          lv_obj_set_style(lv_scr_act(), &style_screen);
        } else if (PM_AE_UG_2_5 <= 55) {
          lv_label_set_text(txt5, "ปานกลาง");

          style_screen.body.main_color = lv_color_hex(0xEB8A14);
          style_screen.body.grad_color = lv_color_hex(0xEB8A14);
          lv_obj_set_style(lv_scr_act(), &style_screen);
        } else if (PM_AE_UG_2_5 <= 150) {
          lv_label_set_text(txt5, "มีผลต่อสุขภาพ");

          style_screen.body.main_color = lv_color_hex(0xFF0000);
          style_screen.body.grad_color = lv_color_hex(0xFF0000);
          lv_obj_set_style(lv_scr_act(), &style_screen);
        } else if (PM_AE_UG_2_5 <= 250) {
          lv_label_set_text(txt5, "อันตราย");

          style_screen.body.main_color = lv_color_hex(0xA10649);
          style_screen.body.grad_color = lv_color_hex(0xA10649);
          lv_obj_set_style(lv_scr_act(), &style_screen);
        }
      }

      delay(10);
    }
  }, "mainTask", 1024, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() {

}
