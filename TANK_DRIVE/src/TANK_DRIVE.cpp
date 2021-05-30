#include "vex.h"

using namespace vex;
using namespace std;

void tank_drive()
{
  // deadband stops the motors when axis values are close to zero.
  int deadband = 5;

  while (true) {
    // gets the velocity percentage of the left motor (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // gets the velocity percentage of the right motor (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();

    // set the speed of the left motor; if the value is less than the deadband, set it to zero
    if (abs(leftMotorSpeed) < deadband) {
      // sets the speed to zero
      LeftMotor.setVelocity(0, percent);
    } else {
      // set the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // sets the speed of the right motor; if the value is less than the deadband, sets it to zero
    if (abs(rightMotorSpeed) < deadband) {
      // sets the speed to zero
      RightMotor.setVelocity(0, percent);
    } else {
      // sets the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    // spins both motors in the forward direction
    LeftMotor.spin(fwd);
    RightMotor.spin(fwd);

    wait(25, msec);
  }
}