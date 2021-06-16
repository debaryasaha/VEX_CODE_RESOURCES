using namespace vex;

extern brain Brain;
extern motor RightFrontMotor;
extern motor LeftFrontMotor;
extern motor RightRearMotor;
extern motor LeftRearMotor;
extern motor RightIntake;
extern motor LeftIntake;
extern controller Controller1;
extern motor RollerFront;
extern motor RollerBack;

extern motor_group l;
extern motor_group r;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);
