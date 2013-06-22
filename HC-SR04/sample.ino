/* HC-SR04 Sample */

#define trigPin 8
#define echoPin 9
#define LED 13

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED, OUTPUT);
}

void loop() {
  int duration, distance;

  // 超音波を投げる
  digitalWrite(trigPin, HIGH);
  delayMicroseconds(1000);
  digitalWrite(trigPin, LOW);

  // 反射して返ってきたのを受け取る
  duration = pulseIn(echoPin, HIGH);

  // 往復してるので半分に割って、音の速度で割ると距離が出る
  distance = (duration/2) / 29.1;

  if (distance >= 300 || distance <= 0){
    Serial.println("Out of range");
  }
  else {
    Serial.print(distance);
    Serial.println(" cm");
  }
  delay(500);
}