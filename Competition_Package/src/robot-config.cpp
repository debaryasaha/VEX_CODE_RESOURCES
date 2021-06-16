#include "vex.h"

using namespace vex;

// A global instance of brain used for printing to the V5 brain screen
brain Brain;
controller Controller1;
motor LeftDriveSmart = motor(PORT4, ratio18_1, false);
motor RightDriveSmart = motor(PORT6, ratio18_1, true);
drivetrain Drivetrain = drivetrain(LeftDriveSmart, RightDriveSmart, 319.19, 295, 165, mm, 1);
motor LeftRearMotor = motor(PORT1, ratio18_1, false);
motor LeftFrontMotor = motor(PORT2, ratio18_1, false);
motor RightRearMotor = motor(PORT3, ratio18_1, false);
motor RightFrontMotor = motor(PORT4, ratio18_1, true);
motor RightIntake = motor(PORT10, ratio18_1, true);
motor LeftIntake = motor(PORT1, ratio18_1, false);
motor RollerFront = motor(PORT5, ratio18_1, false);
motor RollerBack = motor(PORT6, ratio18_1, true);

motor_group l(LeftFrontMotor, LeftRearMotor); // l stands for Left Side motor group
motor_group r(RightFrontMotor, RightRearMotor); // r stands for Right Side motor group


/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void) {
  // Nothing to initialize
}