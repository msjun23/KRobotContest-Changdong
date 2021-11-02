// K로봇대회 2021 라인트레이서
// 출발 및 도착 계측기
// Author: Moon Seokjun

int psd_start = A0;     // 적외선 센서 데이터 핀

void setup() {
  // put your setup code here, to run once:
  pinMode(psd_start, INPUT);

  Serial.begin(9600);
}

void loop() {
  // put your main code here, to run repeatedly:
  float psd_adc = analogRead(psd_start);
  float dist = 10650.08 * pow(psd_adc, -0.935) - 10;
  delay(10);

  //Serial.println(dist);
  Serial.println("Start");
}
