#include <avr/wdt.h>

const byte ledPin = 13;
const byte intPin1 = 2;
const byte intPin2 = 3;
volatile byte state = LOW;

int noiseCancel1 = 0;
bool noiseCanBool1 = false;
int noiseCancel2 = 0;
bool noiseCanBool2 = false;

#define _START 3
#define _END 6
#define _IDLE 9

char cMode = _IDLE;
unsigned char ucData = 0;


/*
※ 인터럽트의 발생 조건에는 4가지가 있습니다.
- FALLING : 핀의 상태가 HIGH에서 LOW로 바뀔 경우
- RISING : 핀의 상태가 LOW에서 HIGH로 바뀔 경우
- CHANGE : 핀의 상태가 바뀔 경우(LOW->HIGH, HIGH->LOW 둘 다 포함)
- LOW : 핀의 상태가 LOW일 경우
*/


void setup() {
  // led핀 설정
  pinMode(ledPin, OUTPUT);

  // interrupt핀 설정
  pinMode(intPin1, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(intPin1), interrupt1, FALLING);
  pinMode(intPin2, INPUT_PULLUP);
  attachInterrupt(digitalPinToInterrupt(intPin2), interrupt2, FALLING);
  
  Serial.begin(115200);   // setup serial
}

void loop() {
  digitalWrite(ledPin, state);

  ucData = Serial.read();   // read the character  

  if (ucData == 'R') {
    // 여기에서는 센서 하나를 끄던지 하자
    cMode = _IDLE;
    Serial.print('R');
    wdt_enable(WDTO_15MS);  // 리셋
  }

  if (ucData == 'E') {
      Serial.print('E');
      cMode = _IDLE;
  }

  switch (cMode) {
    case _START:
      // PC 측에서 Start 버튼을 누르면 cMode가 바뀐다.
      // 스위치가 눌리는 지 계속 확인하는 상태가 지속된다.
      if(noiseCanBool1){
          if(noiseCancel1> 40){
              noiseCanBool1 = false;
              noiseCancel1 = 0;
          }
          noiseCancel1++;
      }
      if(noiseCanBool2){
          if(noiseCancel2> 40){
              noiseCanBool2 = false;
              noiseCancel2 = 0;
          }
          noiseCancel2++;
      }
      delay(10);
      break;

  
    case _IDLE:
      if (ucData == 'S') {
          Serial.print("S");
          cMode = _START;
      }
      break;
   }
}

void interrupt1() {
  if(!noiseCanBool1){
    state = !state;
    Serial.write('A');
    noiseCanBool1 = true;
  }

}

void interrupt2() {
  if(!noiseCanBool2){    
    state = !state;
    Serial.write('B');
    noiseCanBool2 = true;
  }
}
