#include "qrcode.h"
#include "lvgl.h"

void drawQRCode(lv_obj_t* canvas, String text) {
  QRCode qrcode;
  uint8_t qrcodeData[qrcode_getBufferSize(9)];
  qrcode_initText(&qrcode, qrcodeData, 9, ECC_MEDIUM, text.c_str());

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
