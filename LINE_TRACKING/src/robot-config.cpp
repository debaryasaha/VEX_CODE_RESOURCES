#include "vex.h"

using namespace vex;
using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain Brain;

// VEXcode device constructors
line LineTrackerA = line(Brain.ThreeWirePort.A);
motor RightDrive = motor(PORT2, ratio18_1, false);
motor LeftDrive = motor(PORT3, ratio18_1, true);
motor LeftIntake = motor(PORT1, ratio18_1, false);
motor RightIntake = motor(PORT10, ratio18_1, true);

motor_group intakes(LeftIntake, RightIntake);
motor_group Drivetrain(RightDrive, LeftDrive);

// VEXcode generated functions

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // nothing to initialize
}