#include <Servo.h>

Servo rudderServo; 

void setup() {
  rudderServo.attach(9); 
  rudderServo.write(0);
  delay(50);
  
}

void loop() {
  // Sweep from 68 to 112 degrees (a 44-degree range centered at 90)
  for (int pos = 90 - 22; pos <= 90 + 22; pos += 1) {
    rudderServo.write(pos);
    delay(15);
  }
  // Sweep back from 112 to 68 degrees
  for (int pos = 90 + 22; pos >= 90 - 22; pos -= 1) {
    rudderServo.write(pos);
    delay(15);
  }
 delay(5000);
}