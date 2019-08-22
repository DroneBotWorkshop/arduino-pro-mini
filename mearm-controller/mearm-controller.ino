/*
  Robot Arm Control Demo
  mearm-controller.ino
  Demonstrate use of 3.3 volt Arduino Pro Mini
  Controls 4-DOF Robot Arm with 4 potentiometers
  Powered by 6-volt power source
  DroneBot Workshop 2019
  https://dronebotworkshop.com
*/

// Include Servo Library
#include <Servo.h>

// Create 4 servo objexts
Servo base, left, right, claw ;

// Integers for analog inputs from potentiometers
int basePin = A0;  // Middle Pot Analog Input Pin
int leftPin = A1;  // Left Pot Analog Input Pin
int rightPin = A2;  // Right Pot Analog Input Pin
int clawPin = A3;  // Claw Pot Analog Input Pin

int baseValue = 0;  // Middle Pot Value
int leftValue = 0;  // Left Pot Value
int rightValue = 0;  // Right Pot Value
int clawValue = 0;  // Claw Pot Value


void setup()
{
  // Attach servo objects to output pins
  base.attach(9);
  left.attach(6);
  right.attach(5);
  claw.attach(3);
}

void loop()
{

  // Read the Pot Values
  // Convert to values between 0 and 180 for the servos
  baseValue = map(analogRead(basePin), 0, 1023, 0, 180);
  leftValue = map(analogRead(leftPin), 0, 1023, 0, 180);
  rightValue = map(analogRead(rightPin), 0, 1023, 0, 180);
  clawValue = map(analogRead(clawPin), 0, 1023, 0, 180);

  // Write values to servos
  base.write(baseValue); // Base servo position
  left.write(leftValue); // Left servo position
  right.write(rightValue); // Right servo position
  claw.write(clawValue); // Claw servo position

  delay(400); // Short Delay
}
