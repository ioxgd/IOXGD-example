#define LODEPNG_NO_COMPILE_CPP

#include <IOXGD.h>
#include "pngdecode/lodepng.h"

uint8_t *rawImageData = NULL;

void loadImg() {
  HTTP.get("http://192.168.1.7/img.png");

  Serial.print("File size: ");
  Serial.println(HTTP.payloadSize);

  uint32_t png_width;
  uint32_t png_height;
  uint8_t *img_data = NULL;
    
  uint32_t error = lodepng_decode24(&img_data, &png_width, &png_height, HTTP.payload, HTTP.payloadSize);
  free(HTTP.payload);
  if (error) {
    Serial.print("error ");
    Serial.print(error);
    Serial.print(':');
    Serial.print(lodepng_error_text(error));
    Serial.println();
    return;
  }
  Serial.print("PNG Image size: ");
  Serial.print(png_width);
  Serial.print('x');
  Serial.print(png_height);
  Serial.println();
  
  uint16_t *img16;
  img16 = (uint16_t*)malloc(png_width * png_height * 2);
  for (uint32_t i=0;i<(png_width * png_height);i++) {
    uint8_t r = img_data[(i * 3) + 0];
    uint8_t g = img_data[(i * 3) + 1];
    uint8_t b = img_data[(i * 3) + 2];
    uint16_t RGB565 = ((r & 0b11111000) << 8) | ((g & 0b11111100) << 3) | (b >> 3);
    img16[i] = ((RGB565&0xFF) << 8) | ((RGB565>>8)&0xFF);
  }

  free(img_data);
  
  lcd.startPushColor(0, 0, png_width - 1, png_height - 1);
  lcd.pushColorBlock(img16, png_width * png_height);
  lcd.stopPushColor();

  free(img16);
}

void setup() {
  Serial.begin(115200);
  lcd.init();

  WiFi.begin();
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
