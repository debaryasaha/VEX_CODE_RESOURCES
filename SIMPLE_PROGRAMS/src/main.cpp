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
