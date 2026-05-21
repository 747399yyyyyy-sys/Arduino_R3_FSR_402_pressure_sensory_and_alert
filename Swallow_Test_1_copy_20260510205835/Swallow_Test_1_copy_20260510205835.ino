// --- 技术部 V2.0 预警代码 ---

int sensorPin = A0;   // 压力传感器
int greenLed = 3;     // 绿灯接 D3
int redLed = 4;       // 红灯接 D4

// 阈值设定（根据你的传感器灵敏度可以微调）
int touchThreshold = 0.5;  // 只要超过这个数，说明有吞咽动作
int dangerThreshold = 600; // 如果超过这个数，说明压力异常过大（预警）

void setup() {
  Serial.begin(9600);
  pinMode(greenLed, OUTPUT);
  pinMode(redLed, OUTPUT);

  // 系统启动自检：双灯闪烁一下
  digitalWrite(greenLed, HIGH);
  digitalWrite(redLed, HIGH);
  delay(500);
  digitalWrite(greenLed, LOW);
  digitalWrite(redLed, LOW);
}

void loop() {
  int val = analogRead(sensorPin);
  Serial.println(val); // 依然发送数据给电脑，方便观察

  // --- 逻辑判断开始 ---
  
  if (val > touchThreshold && val < dangerThreshold) {
    // 正常吞咽范围内：亮绿灯
    digitalWrite(greenLed, HIGH);
    digitalWrite(redLed, LOW);
  } 
  else if (val >= dangerThreshold) {
    // 压力过大/异常：亮红灯，灭绿灯
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, HIGH);
  } 
  else {
    // 没动作：全灭
    digitalWrite(greenLed, LOW);
    digitalWrite(redLed, LOW);
  }

  delay(30); // 采样间隔
}
