#include <IOXGD.h>
#include "qrcode.h"

static lv_color_t cbuf[LV_CANVAS_BUF_SIZE_TRUE_COLOR(53 * 6, 53 * 6)];

void setup() {
  Serial.begin(115200);

  gd.begin();

  lv_obj_t * canvas = lv_canvas_create(lv_scr_act(), NULL);
  lv_canvas_set_buffer(canvas, cbuf, 53 * 6, 53 * 6, LV_IMG_CF_TRUE_COLOR);
  lv_canvas_fill_bg(canvas, LV_COLOR_WHITE);
  lv_obj_align(canvas, NULL, LV_ALIGN_CENTER, 0, 0);

  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(9)];
  qrcode_initText(&qrcode, qrcodeData, 9, ECC_MEDIUM, "HELLO WORLD");

  static lv_style_t style;
  lv_style_copy(&style, &lv_style_plain);
  style.body.main_color = LV_COLOR_BLACK;
  style.body.grad_color = LV_COLOR_BLACK;

  for (uint8_t y = 0; y < qrcode.size; y++) {
    for (uint8_t x = 0; x < qrcode.size; x++) {
      if (qrcode_getModule(&qrcode, x, y)) {
        lv_canvas_draw_rect(canvas, x * 6, y * 6, 6, 6, &style);
      }
    }
  }
}

void loop() {
  lv_task_handler();
  delay(5);
}
