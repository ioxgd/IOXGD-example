#include <IOXGD.h>
#include "png_decoder.h"

#include <SPI.h>
#include <SD.h>

File f;

static lv_fs_res_t lv_sd_open(lv_fs_drv_t * drv, void * file_p, const char * fn, lv_fs_mode_t mode) {
  Serial.print("Open file ");
  Serial.println(fn);

  if (!SD.exists(fn)) {
    return LV_FS_RES_UNKNOWN;
  }

  f = SD.open(fn, mode == LV_FS_MODE_WR ? FILE_WRITE : FILE_READ);
  if (!f) {
    Serial.println("Open " + String(fn) + " fail");
    return LV_FS_RES_UNKNOWN;
  }
  f.seek(0);

  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_close(lv_fs_drv_t * drv, void * file_p) {
  Serial.println("Close file");

  f.close();
  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br) {
  Serial.print("Read file ");
  Serial.print(btr);
  Serial.println(" bytes");

  *br = f.read((uint8_t*)buf, btr);
  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos) {
  Serial.println("seek file");

  f.seek(pos);
  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_write(lv_fs_drv_t *drv, void *file_p, const void *buf, uint32_t btw, uint32_t *bw) {
  Serial.print("Write file ");
  Serial.print(btw);
  Serial.println(" bytes");

  uint32_t write_size;
  write_size = f.write((uint8_t*)buf, btw);
  if (bw) {
    *bw = write_size;
  }

  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_size(lv_fs_drv_t *drv, void *file_p, uint32_t *size_p) {
  Serial.println("Get file size");

  *size_p = f.size();

  return LV_FS_RES_OK;
}

static uint64_t time_before = 0;
static lv_obj_t* img_bin;

void setup() {
  Serial.begin(115200);
  
  gd.begin(); // Keep it first

  Serial.print("\nInitializing SD card...");
  if (!SD.begin(29)) {
    Serial.println("initialization failed.");
    while (1) ;
  }
  Serial.println("Wiring is correct and a card is present.");

  lv_fs_drv_t drv;
  lv_fs_drv_init(&drv);

  drv.letter = 'S';
  drv.file_size = 0;
  drv.open_cb = lv_sd_open;
  drv.close_cb = lv_sd_close;
  drv.read_cb = lv_sd_read;
  drv.write_cb = lv_sd_write;
  drv.seek_cb = lv_sd_seek;
  drv.size_cb = lv_sd_size;

  lv_fs_drv_register(&drv);

  png_decoder_init();

  static lv_style_t new_style;
  lv_style_copy(&new_style, &lv_style_scr);
  new_style.body.main_color = LV_COLOR_RED;
  new_style.body.grad_color = LV_COLOR_BLUE;
  lv_obj_set_style(lv_scr_act(), &new_style);

  img_bin = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img_bin, "S:/test.png");
  lv_obj_align(img_bin, NULL, LV_ALIGN_CENTER, 0, 0);

  time_before = millis();
}

void loop() {
  lv_task_handler();
  delay(5);

  if ((millis() - time_before) > 3000) {
    time_before = millis();
    
    static bool s = true;
    lv_img_cache_invalidate_src(NULL);
    if (s) {
      lv_img_set_src(img_bin, "S:/logo.png");
    } else {
      lv_img_set_src(img_bin, "S:/test.png");
    }
    lv_obj_realign(img_bin);
    s = !s;
  }
}
