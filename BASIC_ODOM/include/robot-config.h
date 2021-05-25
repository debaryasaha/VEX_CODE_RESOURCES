using namespace vex;

extern brain Brain;

// VEXcode devices
extern encoder l; // left encoder
extern encoder r; // right encoder
extern encoder b; // back encoder

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Pro.
 *
 * This should be called at the start of your int main function.
 */
void vexcodeInit(void);