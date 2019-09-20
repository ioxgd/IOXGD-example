#include <IOXGD.h>
#include <lvgl.h>
#include <Wire.h>
#include <Ticker.h>

Ticker vcnl;

lv_obj_t * chart;
lv_chart_series_t *ser1;
void setup() {
  Serial.begin(115200);
  gd.setupLittlevGL();
  
  VCNLSetup();
  
  /*Create a chart*/
  chart = lv_chart_create(lv_scr_act(), NULL);
  lv_obj_set_size(chart, 800, 480);
  lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_chart_set_type(chart, LV_CHART_TYPE_POINT | LV_CHART_TYPE_LINE);   /*Show lines and points too*/
  lv_chart_set_series_opa(chart, LV_OPA_70);                            /*Opacity of the data series*/
  lv_chart_set_series_width(chart, 8);                                  /*Line width and point radious*/

  lv_chart_set_range(chart, 0, 20000);

  /*Add two data series*/
  ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);

  static int i = 0;
  if (i >= (100 / 5)) {
    for (int i=0;i<9;i++) {
      ser1->points[i] = ser1->points[i+1];
    }
    ser1->points[9] = VCNLRead();
    Serial.println(ser1->points[9]);
  
    lv_chart_refresh(chart);
    i=0;
  } else {
    i++;
  }
}
