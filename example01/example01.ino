// Example 01

const int LED = 13;    // LED を13番ピンに接続する

void setup() {
  pinMode(LED, OUTPUT);  // use digital pin as an output
}

void loop() {
  digitalWrite(LED, HIGH);  // turn signal ON (HIGH)
  delay(100);              // wait 1 second
  digitalWrite(LED, LOW);   // turn signal OFF (LOW)
  delay(100);
}
