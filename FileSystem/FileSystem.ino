#include <IOXGD.h>

#include <SPI.h>
#include <SD.h>

File f;

static lv_fs_res_t lv_sd_open(lv_fs_drv_t * drv, void * file_p, const char * fn, lv_fs_mode_t mode) {
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
  f.close();
  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_read(lv_fs_drv_t * drv, void * file_p, void * buf, uint32_t btr, uint32_t * br) {
  *br = f.read((uint8_t*)buf, btr);
  return LV_FS_RES_OK;
}

static lv_fs_res_t lv_sd_seek(lv_fs_drv_t * drv, void * file_p, uint32_t pos) {
  f.seek(pos);
  return LV_FS_RES_OK;
}

void setup() {
  Serial.begin(115200);

  gd.begin();

  Serial.print("\nInitializing SD card...");
  if (!SD.begin(29)) {
    Serial.println("initialization failed.");
    while(1) ;
  }
  Serial.println("Wiring is correct and a card is present.");

  lv_fs_drv_t drv;
  lv_fs_drv_init(&drv);

  drv.letter = 'S';
  drv.file_size = 0;
  drv.open_cb = lv_sd_open;
  drv.close_cb = lv_sd_close;
  drv.read_cb = lv_sd_read;
  drv.seek_cb = lv_sd_seek;

  lv_fs_drv_register(&drv);

  lv_obj_t* img_bin = lv_img_create(lv_scr_act(), NULL);
  lv_img_set_src(img_bin, "S:/EN.3-4/img/2.bin");
  lv_obj_align(img_bin, NULL, LV_ALIGN_CENTER, 0, 0);
}

void loop() {
  lv_task_handler();
  delay(5);
}
