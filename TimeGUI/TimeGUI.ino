#include <IOXGD.h>

extern lv_obj_t* txt2;
extern lv_obj_t* txt3;
extern lv_obj_t* txt4;

char thMonth[12][40] = { "มกราคม", "กุมภาพันธ์", "มีนาคม", "เมษายน", "พฤษภาคม", "มิถุนายน", "กรกฎาคม", "สิงหาคม", "กันยายน", "ตุลาคม", "พฤศจิกายน", "ธันวาคม" };

void setup() {
  Serial.begin(115200);
  
  gd.begin(SETUP_LVGL);

  load_page();

  xTaskCreate([](void*) {
    
    ESP32.begin();
    WiFi.connect("MaxHome3BB", "987654321");

    Serial.print("Connect");
    lv_label_set_text(txt4, "WiFi Connecting");
    while (!WiFi.isConnected()) {
      Serial.print(".");
      vTaskDelay(500 / portTICK_PERIOD_MS);
    }
    Serial.println("Connected");

    NTP.begin(7);
    RTC.begin();

    lv_label_set_text(txt4, "Syncing");
    if (RTC.syncFromNTP()) {
      Serial.println("Sync from NTP !");
      lv_label_set_text(txt4, "Sync from NTP !");
    } else {
      Serial.println("Sync error");
      lv_label_set_text(txt4, "Sync error");
    }

    while (1) {
      if (RTC.get()) {
        char timeStr[20];
        sprintf(timeStr, "%02d:%02d:%02d", RTC.hour(), RTC.minute(), RTC.second());
        lv_label_set_text(txt2, timeStr);

        char dateStr[100];
        sprintf(dateStr, "%d %s %d", RTC.day(), thMonth[RTC.month() - 1], RTC.year() + 543);
        lv_label_set_text(txt3, dateStr);
      } else {
        Serial.println("Error, can't read from RTC.");
        lv_label_set_text(txt2, "ERROR");
      }
      delay(1000);
    }
  }, "mainTask", 2048, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() {
  // put your main code here, to run repeatedly:

}
