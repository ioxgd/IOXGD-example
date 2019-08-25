#include <IOXGD.h>
#include <lvgl.h>
#include <RedMP3.h>

#define MP3_RX 14 // RX
#define MP3_TX 15 // TX
MP3 mp3(MP3_RX, MP3_TX);

int8_t volume = 20; //0~0x1e (30 adjustable level)

void setup() {
  Serial.begin(115200);
  gd.setupLittlevGL();

  delay(500);//Requires 500ms to wait for the MP3 module to initialize
  mp3.begin();
  mp3.setVolume(volume);
  delay(50);//you should wait for >=50ms between two commands
  mp3.stopPlay();

  // UI
  lv_obj_t *label;

  lv_obj_t *btnPlay = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btnPlay, [](lv_obj_t * obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      mp3.play();
    }
  });
  lv_obj_align(btnPlay, NULL, LV_ALIGN_CENTER, 0, -40);
  label = lv_label_create(btnPlay, NULL);
  lv_label_set_text(label, LV_SYMBOL_PLAY "  Play");

  lv_obj_t *btnStop = lv_btn_create(lv_scr_act(), NULL);
  lv_obj_set_event_cb(btnStop, [](lv_obj_t * obj, lv_event_t event) {
    if (event == LV_EVENT_CLICKED) {
      mp3.stopPlay();
    }
  });
  lv_obj_align(btnStop, NULL, LV_ALIGN_CENTER, 0, 40);
  label = lv_label_create(btnStop, NULL);
  lv_label_set_text(label, LV_SYMBOL_STOP "  Stop");

  /* Create a slider in the center of the display */
  lv_obj_t * slider = lv_slider_create(lv_scr_act(), NULL);
  lv_obj_set_size(slider, 600, 40);
  lv_obj_align(slider, NULL, LV_ALIGN_IN_BOTTOM_MID, 0, -60);
  lv_obj_set_event_cb(slider, [](lv_obj_t * slider, lv_event_t event) {
    if(event == LV_EVENT_VALUE_CHANGED) {
      uint8_t value = lv_slider_get_value(slider);
      mp3.setVolume(value);
    }
  });
  lv_slider_set_range(slider, 0, 30);
  lv_slider_set_value(slider, volume, LV_ANIM_OFF);
}

void loop() {
  lv_task_handler(); /* let the GUI do its work */
  delay(5);
}

/*********************************************************************************************************
  The end of file
*********************************************************************************************************/
