/* HC-SR04 Sample */

#define trigPin 8
#define echoPin 9
#define LED_YELLOW 13
#define LED_RED 12

void setup() {
  Serial.begin (9600);
  pinMode(trigPin, OUTPUT);
  pinMode(echoPin, INPUT);
  pinMode(LED_YELLOW, OUTPUT);
  pinMode(LED_RED, OUTPUT);
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

  if (distance <= 10){
    Serial.println("Out of range: Too Close");
	digitalWrite(LED_RED, HIGH);
	digitalWrite(LED_YELLOW, LOW);
  }
  else if (distance <= 25) {
	digitalWrite(LED_YELLOW, HIGH);
	digitalWrite(LED_RED, LOW);
  }	
  /* else if (distance >= 40) { */
  /*   Serial.println("Out of range: Too Far"); */
  /* 	digitalWrite(LED, HIGH); */
  /* } */
  else {
    Serial.print(distance);
    Serial.println(" cm");
	digitalWrite(LED_YELLOW, LOW);
	digitalWrite(LED_RED, LOW);
  }
  delay(500);
}