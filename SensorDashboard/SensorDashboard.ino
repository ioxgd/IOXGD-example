#include <IOXGD.h>
#include "DHT.h"

#define RELAY_PIN 8
#define DHTPIN 9

// Uncomment whatever type you're using!
//#define DHTTYPE DHT11   // DHT 11
#define DHTTYPE DHT22   // DHT 22  (AM2302), AM2321
//#define DHTTYPE DHT21   // DHT 21 (AM2301)

extern lv_obj_t* temp;
extern lv_obj_t* humi;
extern lv_obj_t* chart1;
extern lv_obj_t* lamp;

DHT dht(DHTPIN, DHTTYPE);

void setup() {
  Serial.begin(115200);

  gd.begin(SETUP_LVGL);

  xTaskCreate([](void*) {
    // put your setup code here, to run once:
    load_page();

    lv_chart_set_series_width(chart1, 8); 
    lv_chart_set_point_count(chart1, 30);

    lv_chart_series_t *ser1 = lv_chart_add_series(chart1, lv_color_hex(0x1ABC9C));
    lv_chart_series_t *ser2 = lv_chart_add_series(chart1, lv_color_hex(0xF1C40F));

    label_set_text(temp, "LOAD");
    label_set_text(humi, "LOAD");

    pinMode(RELAY_PIN, OUTPUT);
    digitalWrite(RELAY_PIN, HIGH);

    dht.begin();

    switch_set_on_value(lamp, []() {
      digitalWrite(RELAY_PIN, !switch_get_value(lamp));
    });

    while (1) {
      delay(1000);

      float h = dht.readHumidity();
      float t = dht.readTemperature();

      if (isnan(h) || isnan(t)) {
        label_set_text(temp, "ERR");
        label_set_text(humi, "ERR");
        
        lv_chart_clear_serie(chart1, ser1);
        lv_chart_clear_serie(chart1, ser2);
        continue;
      }
      
      label_set_text(temp, String(t, 1));
      label_set_text(humi, String(h, 1));

      static uint64_t startTime = millis();

      if ((millis() - startTime) >= 1000 * 1) { // Update every 1 min
        startTime = millis();
        
        lv_chart_set_next(chart1, ser1, t); // Add data from t to serie 1
        lv_chart_set_next(chart1, ser2, h); // Add data from h to serie 2

        lv_chart_refresh(chart1);
      }
    }
  }, "mainTask", 1024, NULL, 1, NULL);

  gd.startFreeRTOS();
}

void loop() { }
