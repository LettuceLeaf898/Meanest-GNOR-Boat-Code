#include <Servo.h>
Servo rudder;
Servo motor;

// Important Variables

// Adjust this to adjust start-up delay
#define Startup_Delay 10000 // Adjust time it takes for boat to start moving
#define Calibration_Delay 2000 // Adjust time it takes for calibration

// Adjust these to adjust rudder movement
#define Rudder_Straight 60   
#define Rudder_45_Degree_Left_Turn 0  // Needs to be adjusted based on actual turning movement

// Adjust these to adjust timing
#define Motor_On 1200 // Can be increased for faster boat, but also will eat up battery more
#define Motor_Off 1000 // Can be used to stop ESC
#define First_Boat_Lap_Segment_Time_Straight 45000 // Can adjust these values along with motor_on to mess with timing of lap segments
#define Second_Boat_Lap_Segment_Time_Turn 15000
#define Third_Boat_Lap_Segment_Time_Straight 15000
#define Fourth_Boat_Lap_Segment_Time_Turn 5000
#define Last_Boat_Lap_Segment_Time_Straight 45000

// Defining Boat_Lap_Segment states (for switch case)
enum Boat_Lap_Segment_States {
  START,
  First_Boat_Lap_Segment,
  Second_Boat_Lap_Segment,
  Third_Boat_Lap_Segment,
  Fourth_Boat_Lap_Segment,
  Last_Boat_Lap_Segment,
  STOP
};

// Initializing Boat Lap Segment
Boat_Lap_Segment_States Boat_Lap_Segment = START;

void setup() {
  rudder.attach(9); // Tells program that Servo (Rudder) is attached to pin 9 on arduino (Data pin)
  motor.attach(10); // Tells program that ESC (motor) is attached to pin 10 on arduino (Data pin)

  rudder.write(Rudder_Straight); // Initialized rudder to 0 degrees

  // Calibrating ESC (motor)
  motor.writeMicroseconds(2000); // Maximum for ESC
  delay(2000);
  motor.writeMicroseconds(1000); // Minimum for ESC

}

void loop() {
  switch(Boat_Lap_Segment) {
    case START:
      // Start-Up Delay for Getting Boat Ready
      delay(Startup_Delay - Calibration_Delay); 
      Boat_Lap_Segment = First_Boat_Lap_Segment;
      break;
    case First_Boat_Lap_Segment:
      motor.writeMicroseconds(Motor_On);
      delay(First_Boat_Lap_Segment_Time_Straight);
      Boat_Lap_Segment = Second_Boat_Lap_Segment;
      break;
    case Second_Boat_Lap_Segment:
      motor.writeMicroseconds(Motor_On);
      rudder.write(Rudder_45_Degree_Left_Turn);
      delay(Second_Boat_Lap_Segment_Time_Turn);
      Boat_Lap_Segment = Third_Boat_Lap_Segment;
      break;
    case Third_Boat_Lap_Segment:
      motor.writeMicroseconds(Motor_On);
      rudder.write(Rudder_Straight);
      delay(Third_Boat_Lap_Segment_Time_Straight);
      Boat_Lap_Segment = Fourth_Boat_Lap_Segment;
      break;
    case Fourth_Boat_Lap_Segment:
      motor.writeMicroseconds(Motor_On);
      rudder.write(Rudder_45_Degree_Left_Turn);
      delay(Fourth_Boat_Lap_Segment_Time_Turn);
      Boat_Lap_Segment = Last_Boat_Lap_Segment;
      break;
    case Last_Boat_Lap_Segment:
      motor.writeMicroseconds(Motor_On);
      rudder.write(Rudder_Straight);
      delay(Last_Boat_Lap_Segment_Time_Straight);
      Boat_Lap_Segment = STOP;
      break;
    case STOP:
      motor.writeMicroseconds(Motor_Off);
      rudder.write(Rudder_Straight);
      break;

  }

}