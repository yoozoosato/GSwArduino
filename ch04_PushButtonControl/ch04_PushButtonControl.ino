// Trun on LED while button is pushed

const int LED = 13;        // LEDは13番のピンに刺す
const int BUTTON = 7;      // ボタンを接続するピン

int val = 0;
int old_val = 0;
int state = 0;            // 入力ボタンの状態を保持する変数　　　　　

void setup() {
  pinMode(LED, OUTPUT);
  pinMode(BUTTON, INPUT);  // ボタンは入力用
}

void loop() {
  val = digitalRead(BUTTON);  // 入力を val に格納

  if ((val == HIGH) && (old_val == LOW)) {
    state = 1 - state;     // ボタンからの入力でステータスを変える
  }
  old_val = val;
  
  if (state == 1) {
    digitalWrite(LED, HIGH);
  } else {
    digitalWrite(LED, LOW);
  }
}
