#include <IOXGD.h>
#include <lvgl.h>

#include <Wire.h>
#include <SPI.h>
#include <Adafruit_LIS3DH.h>
#include <Adafruit_Sensor.h>

Adafruit_LIS3DH lis = Adafruit_LIS3DH();

char text[64];
lv_obj_t *label1;
lv_obj_t *label2;
lv_obj_t *line1;
lv_point_t line_points[2] = { {100, 240}, {700, 240} };

lv_style_t style_line;

#define BUZZER_PIN 37

void setup() {
  pinMode(BUZZER_PIN, OUTPUT);
  
  Serial.begin(115200);
  gd.setupLittlevGL();

  if (! lis.begin(0x18)) {   // change this to 0x19 for alternative i2c address
    Serial.println("Couldnt start");
    while (1);
  }
  Serial.println("LIS3DH found!");

  lis.setRange(LIS3DH_RANGE_4_G);   // 2, 4, 8 or 16 G!

  label1 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_align(label1, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_width(label1, 800);

  label2 = lv_label_create(lv_scr_act(), NULL);
  lv_label_set_align(label2, LV_LABEL_ALIGN_CENTER);
  lv_obj_set_width(label1, 60);

  /*Create new style (thick dark blue)*/
  lv_style_copy(&style_line, &lv_style_plain);
  style_line.line.color = LV_COLOR_MAKE(0x00, 0x00, 0x00);
  style_line.line.width = 8;
  style_line.line.rounded = 1;

  line1 = lv_line_create(lv_scr_act(), NULL);
  lv_line_set_points(line1, line_points, 2);
  lv_line_set_style(line1, LV_LINE_STYLE_MAIN, &style_line);
  lv_obj_align(line1, NULL, LV_ALIGN_IN_TOP_LEFT, 0, 0);
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);

  static uint32_t timer = millis();
  if ((millis() - timer) > 50) { // do every 50mS
    timer = millis();

    lis.read();
    lis.x_g *= 10.0;
    lis.y_g *= 10.0;
    lis.z_g *= 10.0;
    sprintf(text, "X: %.2f        Y: %.2f        Z: %.2f", lis.x_g, lis.y_g, lis.z_g);
    lv_label_set_text(label1, text);
    lv_obj_align(label1, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -30);

    float m = sqrt((lis.x_g * lis.x_g) + (lis.y_g * lis.y_g) + (lis.z_g * lis.z_g)); // magnitude of the vector
    float angle_x = degrees(acos(lis.x_g / m));
    float angle_y = degrees(acos(lis.y_g / m));
    float angle_z = degrees(acos(lis.z_g / m));

    uint16_t radius = 200;

    line_points[0] = { sin(radians(angle_x)) * radius + 400, cos(radians(angle_x)) * radius + 240 };
    line_points[1] = { sin(radians(angle_x + 180)) * radius + 400, cos(radians(angle_x + 180)) * radius + 240 };
    lv_line_set_points(line1, line_points, 2);
    if (abs(angle_x - 90.0) > 2.0) {
      style_line.line.color = LV_COLOR_MAKE(255, 0, 0);
      noTone(BUZZER_PIN);
    } else {
      style_line.line.color = LV_COLOR_MAKE(20, 133, 0);
      tone(BUZZER_PIN, 2E3);
    }
    lv_line_set_style(line1, LV_LINE_STYLE_MAIN, &style_line);

    sprintf(text, "%.2f", angle_x - 90.0);
    lv_label_set_text(label2, text);
    lv_obj_align(label2, NULL, LV_ALIGN_CENTER, 0, -30);

  }
}
