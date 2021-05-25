#include "vex.h"

using namespace vex;


using signature = vision::signature;
using code = vision::code;

// A global instance of brain used for printing to the V5 Brain screen
brain  Brain;

// VEXcode device constructors
motor LeftDriveSmart = motor(PORT4, ratio18_1, false);
motor RightDriveSmart = motor(PORT6, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 165, mm, 1);
motor RearLeftMotor = motor(PORT10, ratio18_1, true);
motor FrontLeftMotor = motor(PORT10, ratio18_1, true);
motor RearRightMotor = motor(PORT10, ratio18_1, true);
motor FrontRightMotor = motor(PORT10, ratio18_1, true);
motor RightIntake = motor(PORT10, ratio18_1, true);
motor LeftIntake = motor(PORT1, ratio18_1, false);
motor RightLift = motor(PORT8, ratio18_1, true);
motor LeftLift = motor(PORT3, ratio18_1, false);
motor RightStack = motor(PORT7, ratio18_1, true);
controller Controller1 = controller(primary);

motor_group l(FrontLeftMotor, RearLeftMotor); // l stands for Left Side motor group
motor_group r(FrontRightMotor, RearRightMotor); // r stands for Right Side motor group

// VEXcode generated functions
// define variable for remote controller enable/disable
bool RemoteControlCodeEnabled = true;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void vexcodeInit( void ) {
  // nothing to initialize
}