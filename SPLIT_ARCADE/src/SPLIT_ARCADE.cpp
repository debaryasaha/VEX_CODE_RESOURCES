#include "vex.h"

using namespace vex;
using namespace std;

void split_arcade()
{
  // deadband stops the motors when axis values are close to zero.
  int deadband = 5;

  while (true) {

    // gets the velocity percentage of the left motor; (Axis3 + Axis1)
    int leftMotorSpeed = Controller1.Axis3.position() + Controller1.Axis1.position();
    // gets the velocity percentage of the right motor; (Axis3 - Axis1)
    int rightMotorSpeed = Controller1.Axis3.position() - Controller1.Axis1.position();

    // Sets the speed of the left motor; if the value is less than the deadband, set it to zero
    if (abs(leftMotorSpeed) < deadband) 
    {
      // sets the speed to zero
      LeftMotor.setVelocity(0, percent);
    } 
    else 
    {
      // S]sets the speed to leftMotorSpeed
      LeftMotor.setVelocity(leftMotorSpeed, percent);
    }

    // set the speed of the right motor; if the value is less than the deadband, sets it to zero
    if (abs(rightMotorSpeed) < deadband) 
    {
      // set the speed to zero
      RightMotor.setVelocity(0, percent);
    } 
    else 
    {
      // sets the speed to rightMotorSpeed
      RightMotor.setVelocity(rightMotorSpeed, percent);
    }

    // spins both motors in the forward direction.
    LeftMotor.spin(fwd);
    RightMotor.spin(fwd);

    wait(25, msec);
  }
}