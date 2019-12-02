#include <IOXGD.h>

void setup() {
  gd.begin(SETUP_LVGL);
  
  load_page();
  
  gd.startFreeRTOS();
}

void loop() { }
