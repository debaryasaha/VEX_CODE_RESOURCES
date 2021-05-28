using namespace vex;

extern brain Brain;

// VEXcode devices
extern line LineTrackerA;
extern motor RightDrive;
extern motor LeftDrive;
extern motor LeftIntake;
extern motor RightIntake;

extern motor_group intakes;
extern motor_group Drivetrain;
/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);