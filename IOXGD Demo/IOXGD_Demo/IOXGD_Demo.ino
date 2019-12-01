#include <IOXGD.h>

extern lv_obj_t* homeScreen;
extern lv_obj_t* gpioScreen;
extern lv_obj_t* graphScreen;
extern lv_obj_t* calculatorScreen;
extern lv_obj_t* wifiscanScreen;
extern lv_obj_t* systemScreen;

extern lv_obj_t* chart1;
extern lv_obj_t* slider1;

void setup() {
  Serial.begin(115200);
  
  gd.begin();
  ESP32.begin();

  home_page();
  graph_page();
  gpio_page();
  calculator_page();
  system_page();
  wifiscan_page();

  lv_scr_load(homeScreen);

  gd.startFreeRTOS();
}

void loop() { }
