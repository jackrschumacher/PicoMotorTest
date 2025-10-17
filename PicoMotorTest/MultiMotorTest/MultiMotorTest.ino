#include <Arduino.h>
#include <Servo.h>
// put function declarations here:
// This program currently is for servos only- DC motors need to be implemented

double defaultAngle = 0.0; //Default value for angle

Servo servo1;
Servo servo2;
Servo servo3;

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

  servo.attach(1); //Attach the servo on port 1 to the servo library
  servo.attach(2); //Attach the servo on port 1 to the servo library
  servo.attach(3); //Attach the servo on port 1 to the servo library
  servo.write(defaultAngle); //Set servo to the default position before executing any commands in the loop
}

void loop()
{
  desiredAngle1 = random(1,180);
  desiredAngle2 = random(1,180);
  desiredAngle3 = random(1,180);
  for(defaultAngle; defaultAngle < desiredAngle1; defaultAngle++){
      servo1.write(desiredAngle1);
      Serial.write("Current angle: ", defaultAngle);
  }
  for(defaultAngle; defaultAngle < desiredAngle2; defaultAngle++){
      servo1.write(desiredAngle2);
      Serial.write("Current angle: ", defaultAngle);
  }
  for(defaultAngle; defaultAngle < desiredAngle3; defaultAngle++){
      servo1.write(desiredAngle3);
      Serial.write("Current angle: ", defaultAngle);
  }

}

