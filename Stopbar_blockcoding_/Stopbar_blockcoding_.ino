#include <Servo.h> 
#include <SimpleTimer.h>

#define SIGNAL_1 5
#define servoPin 9

#define STOPANGLE 105
#define GOANGLE   20

Servo servo; 
int angle = 0; // servo position in degrees 

void setup() 
{ 
  pinMode(SIGNAL_1, INPUT);
  servo.attach(servoPin); 
} 

void loop() 
{
  if (digitalRead(SIGNAL_1) == LOW){
    delay(10 * 1000);
    
    servo.write(GOANGLE);
    delay(15);
    
    delay(30 * 1000);
  }

  servo.write(STOPANGLE);
  delay(15);
}
