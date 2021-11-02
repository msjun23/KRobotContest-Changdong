// K로봇대회 2021 라인트레이서
// 출발 및 도착 계측기
// Author: Moon Seokjun

int psd_start = A0;     // 적외선 센서 데이터 핀
int psd_goal = A1;      // 적외선 센서 데이터 핀
int led_r = 7;          // 확인용 LED 핀 빨간색
int led_g = 6;          // 확인용 LED 핀 초록색

float passing_robot_threshold = 30.0;

void setup() {
  // put your setup code here, to run once:
  pinMode(psd_start, INPUT);
  pinMode(psd_goal, INPUT);
  pinMode(led_r, OUTPUT);
  pinMode(led_g, OUTPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  //float psd_adc = analogRead(psd_start) * 5.0 / 1023.0;
  //float dist = 60.495 * pow(psd_adc, -1.1904);
  float psd_adc = analogRead(psd_start);
  float dist = 10650.08 * pow(psd_adc, -0.935) - 10;
  delay(100);

  Serial.print("Distance(cm): ");
  Serial.println(dist);
  
  //float dist = 11;

  if (dist > passing_robot_threshold) {
    // 라인트레이서가 지나가기 전
    digitalWrite(led_r, HIGH);
    digitalWrite(led_g, LOW);
  }
  else if (dist < passing_robot_threshold) {
    // 라인트레이서가 주행을 시작하는 순간
    digitalWrite(led_r, LOW);
    digitalWrite(led_g, HIGH);
  }
}
