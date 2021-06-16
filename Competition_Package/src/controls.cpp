#include "vex.h"

using namespace vex;
using namespace std;

void tank_controls()
{ 
  LeftFrontMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
  LeftRearMotor.spin(vex::directionType::fwd, Controller1.Axis3.value(), vex::velocityUnits::pct);
  RightFrontMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
  RightRearMotor.spin(vex::directionType::fwd, Controller1.Axis2.value(), vex::velocityUnits::pct);
        
  vex::task::sleep(20); 

  int motorSpeed = 200;

  if (Controller1.ButtonR2.pressing()) // for intaking and scoring
  {
    RollerFront.spin(directionType::fwd, motorSpeed, pct);
    RollerBack.spin(directionType::fwd, motorSpeed, pct);
    RightIntake.spin(directionType::rev, motorSpeed, pct);
    LeftIntake.spin(directionType::rev, motorSpeed, pct);
  }
  else if (Controller1.ButtonR1.pressing()) // for empyting out balls out of cycle
  {
    RollerFront.spin(directionType::rev, motorSpeed, pct);
    RollerBack.spin(directionType::rev, motorSpeed, pct);
    RightIntake.spin(directionType::fwd, motorSpeed, pct);
    LeftIntake.spin(directionType::fwd, motorSpeed, pct);
  }
  else
  {
    RightIntake.stop(brakeType::coast);
    LeftIntake.stop(brakeType::coast);
    RollerFront.stop(brakeType::coast);
    RollerBack.stop(brakeType::coast);
  }
}