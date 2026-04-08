#include <Servo.h>

Servo myESC;

void setup() {
  myESC.attach(10); 

  // --- STEP 1: ARMING ---
  // Most ESCs need to hear 1000ms (Zero Throttle) to unlock.
  myESC.writeMicroseconds(1000); 
  
  // Wait 5-8 seconds for the ESC to finish its startup music
  delay(8000); 
}
//peak voltage is 12.6 //11.1 voltage //2200 KV

//Duty Cycle = what percentage it's on for
// what percentage is the signal set to five volts

//2200*11.1 = about 24200 RPM as the MAX
//PLZ PLZ PLZ DO NOT PUT IT AT THAT
//24200*1%=242pm


void loop() {
  // --- STEP 2: TEST SPIN ---
  // We stay between 1000 (Off) and 1200 (Very Low Power)
  for (int speed = 1000; speed <= 1150; speed += 5) {
    myESC.writeMicroseconds(speed);
    delay(100);
  }

  delay(2000); // Run at low speed for 2 seconds

  // --- STEP 3: STOP ---
  myESC.writeMicroseconds(1000);
  delay(5000); // Wait 5 seconds before repeating
}