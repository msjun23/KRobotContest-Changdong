/*
 Name:    Timer.ino
 Created: 9/8/2020 12:20:43 PM
 Author:  USER
*/

// 5번(시작용)과 6번(종료용)에 신호선을 물리면 됨


#include <SoftwareSerial.h>
#include <avr/wdt.h>


#define SIGNAL_1 5 
#define SIGNAL_2 6
#define START 3
#define END 6
#define IDLE 9


char cRecv = 0;
char cMode = IDLE;
unsigned char ucData = 0;


// the setup function runs once when you press reset or power the board
void setup() {
  Serial.begin(115200);

  pinMode(SIGNAL_1, INPUT);
  pinMode(SIGNAL_2, INPUT);
  
  cMode = IDLE;
  wdt_disable();
}

// the loop function runs over and over again until power down or reset
void loop() {
  
  ucData = Serial.read();   // read the character  

  if (ucData == 'R') {
    // 여기에서는 센서 하나를 끄던지 하자
    cMode = IDLE;

    Serial.print('R');
    wdt_enable(WDTO_15MS);  // 리셋
  }

  switch (cMode) {
    case START:
      // 기존 디폴트 거리 미만이면 장애물이 있다는 증거 
      // 그때는 시리얼로 현재 거리를 전송한다.
      //Serial.print("Q");
      if (digitalRead(SIGNAL_1) == LOW) {
        Serial.print(START);
        cMode = END;
      }
      break;
  
    case END:
      // 도착지점에서 장애물을 감지했을 때
      if (digitalRead(SIGNAL_2) == LOW) {
        Serial.print(END);
        cMode = IDLE;
      }
      break;
  
    case IDLE:
      if (ucData == 'S') {
        Serial.print("S");
        cMode = START;
      }
      break;
   }
}
