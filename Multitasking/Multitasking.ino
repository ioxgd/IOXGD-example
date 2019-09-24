#include <FreeRTOS.h>
#include <task.h>

void vTaskCode( void * pvParameters ) {
  for ( ;; ) {
    Serial.println("Run in task !");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}

void vTaskCode2( void * pvParameters ) {
  for ( ;; ) {
    Serial.println("Run in task 2 !");
    vTaskDelay(500 / portTICK_PERIOD_MS);
  }
}


TaskHandle_t xHandle = NULL, xHandle2 = NULL;

void setup() {
  Serial.begin(115200);

  Serial.println("Task create");
  xTaskCreate(
    vTaskCode,       /* Function that implements the task. */
    "vTaskCode",     /* Text name for the task. */
    1024,            /* Stack size in words, not bytes. */
    NULL,            /* Parameter passed into the task. */
    4,               /* Priority at which the task is created. */
    &xHandle );      /* Used to pass out the created task's handle. */

  xTaskCreate(
    vTaskCode2,      /* Function that implements the task. */
    "vTaskCode2",    /* Text name for the task. */
    1024,            /* Stack size in words, not bytes. */
    NULL,            /* Parameter passed into the task. */
    4,               /* Priority at which the task is created. */
    &xHandle2 );     /* Used to pass out the created task's handle. */

  vTaskStartScheduler();
}

void loop() {

}
