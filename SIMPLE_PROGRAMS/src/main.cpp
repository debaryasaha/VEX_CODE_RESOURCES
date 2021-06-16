#include "vex.h"


using namespace vex;
using namespace std;

competition Competition;

void pre_auton()
{
  vexcodeInit();
}

void autonomous()
{
  driveForward (1.2 * 12); // // drives 1.2 ft forwards
  Turn(90); //robot turns 90 degrees to the right
  driveForward (2 * 12); // // drives 2 ft forwards
  Turn(-90); //robot turns 90 degrees to the left
}

void usercontrol()
{
  while (1)
  {
    // deadband stops the motors when axis values are close to zero.
  int deadband = 5;
    // gets the velocity percentage of the left motor (Axis3)
    int leftMotorSpeed = Controller1.Axis3.position();
    // gets the velocity percentage of the right motor (Axis2)
    int rightMotorSpeed = Controller1.Axis2.position();

    // set the speed of the left motor; if the value is less than the deadband, set it to zero
    if (abs(leftMotorSpeed) < deadband) {
      // sets the speed to zero
      l.setVelocity(0, percent);
    } else {
      // set the speed to leftMotorSpeed
      l.setVelocity(leftMotorSpeed, percent);
    }

    // sets the speed of the right motor; if the value is less than the deadband, sets it to zero
    if (abs(rightMotorSpeed) < deadband) {
      // sets the speed to zero
      r.setVelocity(0, percent);
    } else {
      // sets the speed to rightMotorSpeed
      r.setVelocity(rightMotorSpeed, percent);
    }

    // spins both motors in the forward direction
    l.spin(fwd);
    r.spin(fwd);

    wait(25, msec);
  }
}



int main() {
  // Initializing Robot Configuration. DO NOT REMOVE!
  pre_auton();
  
  // Set up callbacks for autonomous and driver control periods.
  Competition.autonomous(autonomous);
  Competition.drivercontrol(usercontrol);

  // Prevent main from exiting with an infinite loop.
  while (1)
  {
    vex::task::sleep(100);
    // Sleep the task for a short amount of time to
    // prevent wasted resources.
  }
}
