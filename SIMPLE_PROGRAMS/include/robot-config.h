#pragma once

using namespace vex;


extern brain Brain;

// VEXcode devices
extern drivetrain Drivetrain;
extern motor RightIntake;
extern motor LeftIntake;
extern motor RightLift;
extern motor LeftLift;
extern motor RightFrontMotor;
extern motor LeftFrontMotor;
extern motor RightRearMotor;
extern motor LeftRearMotor;
extern controller Controller1;

extern motor_group l;
extern motor_group r;

/**
 * Used to initialize code/tasks/devices added using tools in VEXcode Text.
 * 
 * This should be called at the start of your int main function.
 */
void  vexcodeInit( void );