#include <Servo.h>

Servo rudderServo; 
Servo myESC;  // ESCs use the Servo library

void setup() {
  rudderServo.attach(9); 
  rudderServo.write(0);
  delay(50);
  myESC.attach(10); // Connected to Pin 10

  // --- ARMING SEQUENCE ---
  // Most ESCs need to "hear" 0 speed before they turn on
  myESC.write(0); 
  delay(2000);
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

  for (int speed = 0; speed <= 30; speed += 1) { // 30 is low power for safety
    myESC.write(speed);
    delay(100); 
  }

  delay(2000); // Run at this speed for 2 seconds

  // Stop
  myESC.write(0);
  delay(5000);
}