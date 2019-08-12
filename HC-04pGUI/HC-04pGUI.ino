#include <IOXGD.h>
#include <lvgl.h>

lv_obj_t * chart;
lv_chart_series_t *ser1;
void setup() {
  Serial.begin(115200);
  gd.setupLittlevGL();

  fpioa_set_function(15, FUNC_GPIO7); // Trig
  fpioa_set_function(14, FUNC_GPIO6); // Echo
  gpio_set_drive_mode(7, GPIO_DM_OUTPUT);
  gpio_set_drive_mode(6, GPIO_DM_INPUT);

  /*Create a chart*/
  chart = lv_chart_create(lv_scr_act(), NULL);
  lv_obj_set_size(chart, 800, 480);
  lv_obj_align(chart, NULL, LV_ALIGN_CENTER, 0, 0);
  lv_chart_set_type(chart, LV_CHART_TYPE_POINT | LV_CHART_TYPE_LINE);
  lv_chart_set_series_opa(chart, LV_OPA_70);
  lv_chart_set_series_width(chart, 8);

  lv_chart_set_range(chart, 5, 25);

  /*Add two data series*/
  ser1 = lv_chart_add_series(chart, LV_COLOR_RED);
  for (int i = 0; i < 10; i++) {
    ser1->points[i] = 5;
  }
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);

  static int i = 0;
  if (i >= (20 / 5)) {
    gpio_set_pin(7, GPIO_PV_LOW);
    delayMicroseconds(5);
    gpio_set_pin(7, GPIO_PV_HIGH);
    delayMicroseconds(10);
    gpio_set_pin(7, GPIO_PV_LOW);

    unsigned int distance = __pulseIn() * 0.0173681;

    for (int i = 0; i < 9; i++) {
      ser1->points[i] = ser1->points[i + 1];
    }
    ser1->points[9] = constrain(distance, 5, 25);
    Serial.println(distance);

    lv_chart_refresh(chart);
    i = 0;
  } else {
    i++;
  }
}

uint32_t __pulseIn() {
  uint32_t cpu_freq = sysctl_clock_get_freq(SYSCTL_CLOCK_CPU);
  uint32_t numloops = 0;
  uint32_t maxloops = 100000 * (cpu_freq / 1000000L) / 16; // microsecondsToClockCycles(timeout) / 16; ???
  uint32_t start, end;
  
  // wait for any previous pulse to end
  while (gpio_get_pin(6) == HIGH)
    if (numloops++ == maxloops)
      return 0;
  
  // wait for the pulse to start
  while (gpio_get_pin(6) != HIGH)
    if (numloops++ == maxloops)
      return 0;
  
  // wait for the pulse to stop
  start = micros();
  while (gpio_get_pin(6) == HIGH)
    if (numloops++ == maxloops)
      return 0;
  end  = micros();

  return (end - start);
}
