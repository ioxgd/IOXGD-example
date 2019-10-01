void setup() {
  Serial1.begin(5E6, 40, 41);
}

void loop() {
  Serial1.println("Hello");
  delay(1);
}
