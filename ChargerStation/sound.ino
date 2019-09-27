
lv_task_t* afterBeepTask;

void afterBeepTask_cb(lv_task_t* task) {
  // noTone(BUZZER_PIN);
  // lv_task_del(afterBeepTask);
}

void beep() {
  // tone(BUZZER_PIN, 4E3);
  // afterBeepTask = lv_task_create(afterBeepTask_cb, 50, LV_TASK_PRIO_MID, NULL);

  xTaskCreate([](void*) {
    tone(BUZZER_PIN, 4E3);
    vTaskDelay(50 / portTICK_PERIOD_MS);
    noTone(BUZZER_PIN);
    vTaskDelete(NULL);
  }, "soundTask", 1024, NULL, 5, NULL);
}
