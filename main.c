#include <Servo.h>

Servo rudderServo; 
Servo myESC;  // ESCs use the Servo library

void setup() {
  // Initialize the SERVO
  rudderServo.attach(9); 
  rudderServo.write(0);
  delay(50);

  // Initialize the ESC
  myESC.attach(10); 
  // --- STEP 1: ARMING ---
  // Most ESCs need to hear 1000ms (Zero Throttle) to unlock.
  myESC.writeMicroseconds(1000); 
  // Wait 5-8 seconds for the ESC to finish its startup music
  delay(8000); 

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
 //delay(5000);
   // --- STEP 2: TEST SPIN ---
  // We stay between 1000 (Off) and 1200 (Very Low Power)
  for (int speed = 1000; speed <= 1100; speed += 5) {
    myESC.writeMicroseconds(speed);
    delay(100);
  }

  delay(2000); // Run at low speed for 2 seconds

  // --- STEP 3: STOP ---
  myESC.writeMicroseconds(1000);
  delay(5000); // Wait 5 seconds before repeating
}