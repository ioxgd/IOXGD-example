#define LODEPNG_NO_COMPILE_CPP

#include <IOXGD.h>
#include <TJpg_Decoder.h>
#include <tjpgd.h>

uint8_t *rawImageData = NULL;

void loadImg() {
  HTTP.get("http://192.168.1.7/img.jpg");

  Serial.print("File size: ");
  Serial.println(HTTP.payloadSize);

  uint16_t img_width;
  uint16_t img_height;

  JRESULT res;
  res = TJpgDec.getJpgSize(&img_width, &img_height, HTTP.payload, (uint32_t)HTTP.payloadSize);
  if (res == JDR_OK) {
    Serial.print("Image size: ");
    Serial.print(img_width);
    Serial.print('x');
    Serial.print(img_height);
    Serial.println();
  } else {
    Serial.print("Image get size error: ");
    Serial.print((int)res);
    Serial.println();
  }
  

  res = TJpgDec.drawJpg(0, 0, HTTP.payload, HTTP.payloadSize);
  if (res != JDR_OK) {
    Serial.print("Image decode error: ");
    Serial.print((int)res);
    Serial.println();
  }

  free(HTTP.payload);
}

bool tft_output(int16_t x, int16_t y, uint16_t w, uint16_t h, uint16_t* bitmap) {
  if (y >= 480) return 0;

  lcd.startPushColor(x, y, x + w - 1, y + h - 1);
  lcd.pushColorBlock(bitmap, w * h);
  lcd.stopPushColor();
  
  return 1;
}

void setup() {
  Serial.begin(115200);
  lcd.init();

  TJpgDec.setJpgScale(1);
  TJpgDec.setSwapBytes(true);
  TJpgDec.setCallback(tft_output);

  ESP32.begin();
  WiFi.connect("MaxHome3BB", "987654321");
  
  Serial.print("Connect");
  while(!WiFi.isConnected()) {
    Serial.print(".");
    delay(500);
  }
  Serial.println("Connected");
}

void loop() {
  loadImg();
  delay(50);
}
