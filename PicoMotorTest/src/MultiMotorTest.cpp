#include <Arduino.h>
#include <Servo.h>
// put function declarations here:
// This program currently is for servos only- DC motors need to be implemented

const int defaultAngle = 0;  //Default value for angle
const int stepDelayMs = 15;  //Time given to a servo to reach each step

Servo servo1;
Servo servo2;
Servo servo3;

//Angle each servo is currently holding
int currentAngle1 = defaultAngle;
int currentAngle2 = defaultAngle;
int currentAngle3 = defaultAngle;

//Sweep one servo from its current angle to the target, a degree at a time, and report the new angle
int sweepTo(Servo &servo, int currentAngle, int desiredAngle)
{
  int step = (desiredAngle < currentAngle) ? -1 : 1; //Sweep in whichever direction the target lies

  while(currentAngle != desiredAngle){
      currentAngle += step;
      servo.write(currentAngle);
      Serial.print("Current angle: ");
      Serial.println(currentAngle);
      delay(stepDelayMs);
  }
  return currentAngle;
}

void setup()
{
  Serial.begin(9600); // Begin broadcasting over serial on a baud rate of 9600

  // TODO: Change these pins to match hardware

  // Set up pins for digital input and output- for help refer to the "Resources" folder for the schematic
  // Using pins 1-6 for servo output.
  //! Pin 3 is GROUND- Do not assign something to this

  pinMode(1, OUTPUT); // High Torque Servo Miuzei
  pinMode(2, OUTPUT); // Grab — MGT Servo
  pinMode(4, OUTPUT); // Rotation MGT-Servo
  pinMode(5, OUTPUT); // PWMA Driver - Is this an input?
  pinMode(6, OUTPUT); // PWMB Driver- Are these actually inputs- difficult to tell from the diagram

  pinMode(21, INPUT);  // SDA-BMP388- SDA = serial input to processor- confirm
  pinMode(22, OUTPUT); // SCL-BMP388

  pinMode(25, OUTPUT); // SCL-BNO055
  pinMode(26, INPUT);  // SDA-BNO055- SDA = serial input to processor- confirm

  pinMode(40, OUTPUT); // Output to Libre

  servo1.attach(1); //Attach the servo on port 1 to the servo library
  servo2.attach(2); //Attach the servo on port 2 to the servo library
  servo3.attach(4); //Attach the servo on port 4 to the servo library- port 3 is GROUND

  //Set each servo to the default position before executing any commands in the loop
  servo1.write(defaultAngle);
  servo2.write(defaultAngle);
  servo3.write(defaultAngle);
}

void loop()
{
  int desiredAngle1 = random(1,180);
  int desiredAngle2 = random(1,180);
  int desiredAngle3 = random(1,180);

  currentAngle1 = sweepTo(servo1, currentAngle1, desiredAngle1);
  currentAngle2 = sweepTo(servo2, currentAngle2, desiredAngle2);
  currentAngle3 = sweepTo(servo3, currentAngle3, desiredAngle3);
}

