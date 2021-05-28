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
}

void arcade_controls()
{

}