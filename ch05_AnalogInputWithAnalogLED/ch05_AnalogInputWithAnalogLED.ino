const int LED = 9;
int val = 0;
int brightness = 0;

void setup() {
  pinMode(LED, OUTPUT);
}

void loop() {
  val = analogRead(0);
  brightness = (val < 10 ? 1 : val / 2.5);
  analogWrite(LED, brightness);
  delay(10);
}
