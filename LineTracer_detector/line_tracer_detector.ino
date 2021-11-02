// K로봇대회 2021 라인트레이서
// 출발 및 도착 계측기
// Author: Moon Seokjun

int psd_start = A0;     // 적외선 센서 데이터 핀
int psd_goal = A1;      // 적외선 센서 데이터 핀
int led_r = 7;          // 확인용 LED 핀 빨간색
int led_g = 6;          // 확인용 LED 핀 초록색
unsigned long start_time = 0;
unsigned long end_time = 0;
unsigned long run_time = 0;

float passing_robot_threshold = 30.0;
int start_flag = 0;

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
  float psd_adc = analogRead(psd_start);
  float dist = 10650.08 * pow(psd_adc, -0.935) - 10;
  delay(10);
    
  if (!start_flag) {
    // 주행 시작 전
    if (dist > passing_robot_threshold) {
      // 라인트레이서가 지나가기 전
      digitalWrite(led_r, HIGH);
      digitalWrite(led_g, LOW);
    }
    else if (dist < passing_robot_threshold) {
      // 라인트레이서가 주행을 시작하는 순간
      digitalWrite(led_r, LOW);
      digitalWrite(led_g, HIGH);
    
      // 주행 기록 타이머 시작
      start_flag = 1;
      start_time = millis();
      Serial.println("Race Start!!");
      delay(5000);
    }
  }
  else {
    // 주행 시작 후
    if (dist > passing_robot_threshold) {
      // 라인트레이서가 골에 들어오기 전
      digitalWrite(led_r, LOW);
      digitalWrite(led_g, HIGH);
    }
    else if (dist < passing_robot_threshold) {
      // 라인트레이서가 골에 들어온 순간
      end_time = millis();

      run_time = end_time - start_time;
      Serial.println("Race Over");
      Serial.print("Lap time: ");
      Serial.print(run_time / 1000);
      Serial.print(".");
      Serial.print(run_time % 1000);
      Serial.println("s");

      digitalWrite(led_r, HIGH);
      digitalWrite(led_g, LOW);
      delay(1000000000);
    }
  }
}
