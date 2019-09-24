
lv_task_t* afterBeepTask;

void afterBeepTask_cb(lv_task_t* task) {
  noTone(BUZZER_PIN);
  lv_task_del(afterBeepTask);
}

void beep() {
  tone(BUZZER_PIN, 4E3);
  afterBeepTask = lv_task_create(afterBeepTask_cb, 50, LV_TASK_PRIO_MID, NULL);
}
