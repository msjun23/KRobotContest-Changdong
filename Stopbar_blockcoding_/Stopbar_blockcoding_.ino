#include <Servo.h> 

#define SIGNAL_1 5
#define servoPin 9
#define LED_PIN 13

#define STOPANGLE 105
#define GOANGLE   20

Servo servo; 
int angle = 0; // servo position in degrees 

void setup() 
{
  pinMode(LED_PIN, OUTPUT);
  pinMode(SIGNAL_1, INPUT);
  servo.attach(servoPin); 
}

void loop() 
{
  if (digitalRead(SIGNAL_1) == LOW){
    digitalWrite(LED_PIN, HIGH);
    delay(10 * 1000);
    
    servo.write(GOANGLE);
    delay(15);
    
    delay(30 * 1000);
  }

  servo.write(STOPANGLE);
  digitalWrite(LED_PIN, LOW);
  delay(15);
}
