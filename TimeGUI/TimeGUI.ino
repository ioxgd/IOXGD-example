#include <IOXGD.h>

extern lv_obj_t* txt2;
extern lv_obj_t* txt3;
extern lv_obj_t* txt4;

char thMonth[12][40] = { "มกราคม", "กุมภาพันธ์", "มีนาคม", "เมษายน", "พฤษภาคม", "มิถุนายน", "กรกฎาคม", "สิงหาคม", "กันยายน", "ตุลาคม", "พฤศจิกายน", "ธันวาคม" };

void setup() {
  gd.begin(SETUP_LVGL);

  load_page();

  xTaskCreate([](void*) {
    Serial.begin(115200);

    WiFi.begin();
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
        String timeStr;
        if (RTC.hour() < 10) timeStr += '0';
        timeStr += RTC.hour();
        timeStr += ':';
        if (RTC.minute() < 10) timeStr += '0';
        timeStr += RTC.minute();
        timeStr += ':';
        if (RTC.second() < 10) timeStr += '0';
        timeStr += RTC.second();

        lv_label_set_text(txt2, timeStr.c_str());

        String dateStr;
        dateStr += RTC.day();
        dateStr += ' ';
        dateStr += thMonth[RTC.month() - 1];
        dateStr += ' ';
        dateStr += (RTC.year() + 543);
        lv_label_set_text(txt3, dateStr.c_str());
      } else {
        Serial.println("Error, can't read from RTC.");
        lv_label_set_text(txt2, "ERROR");
      }
      delay(1000);
    }
  }, "mainTask", 1024, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() {
  // put your main code here, to run repeatedly:

}
