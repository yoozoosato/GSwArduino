const int LED = 9;
int val = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(0);
  analogWrite(LED, val/12);
  delay(10);
}
