#include <stdio.h>
#include <syslog.h>
#include <timer.h>
#include <pwm.h>
#include <plic.h>
#include <sysctl.h>
#include <fpioa.h>
#include <SD.h>

#define TIMER_NOR   TIMER_DEVICE_0
#define TIMER_CHN   TIMER_CHANNEL_0
#define TIMER_PWM   PWM_DEVICE_1
#define TIMER_PWM_CHN PWM_CHANNEL_0

#define BUFFER_SIZE 500
int16_t buffer1[BUFFER_SIZE];
int16_t buffer2[BUFFER_SIZE];
uint16_t buffer1size = 0;
uint16_t buffer2size = 0;

File myFile;

int timer_callback(void *ctx)
{
  static uint32_t nextInx = 0;
  static uint32_t dataFromBuff = 1;
  int16_t wav = 0;
  if (dataFromBuff == 1 && buffer1size > 0) {
    wav = buffer1[nextInx++];
    buffer1size--;
    if (buffer1size == 0) {
      nextInx = 0;
      dataFromBuff = 2;
    }
  } else if (dataFromBuff == 2 && buffer2size > 0) {
    wav = buffer2[nextInx++];
    buffer2size--;
    if (buffer2size == 0) {
      nextInx = 0;
      dataFromBuff = 1;
    }
  }
  uint16_t v_wav = wav + 32768;
  double duty = v_wav / 65536.0;
  /* 16K * 60 HZ */
  pwm_set_frequency(TIMER_PWM, TIMER_PWM_CHN, 960000, duty);

  return 0;
}

void setup() {
  Serial.begin(115200);
  
  Serial.println("PWM wav test");
  /* Init FPIOA pin mapping for PWM*/
  fpioa_set_function(8, FUNC_TIMER1_TOGGLE1);
  /* Init Platform-Level Interrupt Controller(PLIC) */
  plic_init();
  /* Enable global interrupt for machine mode of RISC-V */
  sysctl_enable_irq();
  /* Init timer */
  timer_init(TIMER_NOR);
  /* 16k sample rate */
  // timer_set_interval(TIMER_NOR, TIMER_CHN, 125000);
  // timer_set_interval(TIMER_NOR, TIMER_CHN, 62500);
  timer_set_interval(TIMER_NOR, TIMER_CHN, 22675);
  /* Set timer callback function with repeat method */
  timer_irq_register(TIMER_NOR, TIMER_CHN, 0, 1, timer_callback, NULL);
  /* Enable timer */
  // timer_set_enable(TIMER_NOR, TIMER_CHN, 1);
  /* Init PWM */
  pwm_init(TIMER_PWM);
  /* Enable PWM */
  pwm_set_enable(TIMER_PWM, TIMER_PWM_CHN, 1);

  Serial.print("Initializing SD card...");

  if (!SD.begin(20E6, 29)) {
    Serial.println("initialization failed!");
    while (1);
  }
  Serial.println("initialization done.");

  Serial.println("Start read file");
  myFile = SD.open("3.wav");
  if (myFile) {
    if (myFile.find("data")) {
      myFile.read();
      myFile.read();
      myFile.read();
      myFile.read();

      Serial.println("Start play");

      timer_set_enable(TIMER_NOR, TIMER_CHN, 1);
      while(myFile.available()) {
        if (buffer1size == 0) {
          int count = myFile.readBytes((uint8_t*)&buffer1, BUFFER_SIZE * 2);
          buffer1size += count / 2;
          // Serial.println(buffer1size);
        } else if (buffer2size == 0) {
          int count = myFile.readBytes((uint8_t*)&buffer2, BUFFER_SIZE * 2);
          buffer2size += count / 2;
        }
      }
    } else {
      Serial.println("Error, not found data");
    }
  }
}

void loop() {

}
