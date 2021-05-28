#include "vex.h"

using namespace vex;
using namespace std;

float threshold = 30;

void spinIntakes()
{
  while (true) {
  // If the reflectivity is less than the threshold it will move the intakes forward
  if (LineTrackerA.reflectivity() < threshold) 
  {
    intakes.spin(fwd);
  } 
  else 
  {
    // If the reflectivity is more than the threshold it will move the RightMotor forward
    intakes.stop(coast);
  }
  wait(5, msec);
}
}

void followLine() // robot will follow a straight line (will not autocorrect for turns and curves in line)
{
  while (true) {
  // If the reflectivity is less than the threshold it will move the intakes forward
  if (LineTrackerA.reflectivity() < threshold) 
  {
    Drivetrain.spin(fwd);
  } 
  else 
  {
    // If the reflectivity is more than the threshold it will move the RightMotor forward
    Drivetrain.stop(coast);
  }
  wait(5, msec);
}
}