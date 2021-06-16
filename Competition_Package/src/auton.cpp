#include "vex.h"

using namespace vex;
using namespace std;

// defining variables

float pi = 3.14159265359;
const double wheelDiameter = 3.25;
const float wheelCircumference = wheelDiameter * pi;
const float turningDiameter = 18.0; // distance (in inches) from top-left wheel to bottom-right wheel
const float gearRatio = 1; // 1 turn of the motor = 1 turn of the wheel
const int AUTON_DRIVE_PCT = 50; //motor set to 50% power

double kP = 0;
double kI = 0;
double kD = 0;

double error;
double prevError = 0;
double totalError = 0;
double derivative;



void driveForward(float inches)
{
  float inchesPerDegree = wheelCircumference / 360;
  float degrees = inches / inchesPerDegree;
  l.rotateFor(degrees * gearRatio, vex::rotationUnits::deg, AUTON_DRIVE_PCT, vex::velocityUnits::pct, false); // doesnt wait for completion (async)
  r.rotateFor(degrees * gearRatio, vex::rotationUnits::deg, AUTON_DRIVE_PCT, vex::velocityUnits::pct); // both functions run parallel
}

void Turn(float degrees)
{
  // Note: +90 degrees is a right turn; -90 is a left turn
    float turningRatio = turningDiameter / wheelDiameter;
    float wheelDegrees = turningRatio * degrees;    
    // Divide by two because each wheel provides half the rotation
    l.rotateFor(wheelDegrees * gearRatio / 2, vex::rotationUnits::deg, AUTON_DRIVE_PCT, vex::velocityUnits::pct);
    r.rotateFor(wheelDegrees * gearRatio / 2, vex::rotationUnits::deg, AUTON_DRIVE_PCT, vex::velocityUnits::pct);
}

void drivePID(double desiredValue, bool resetSensors)
{
  while (true)
  {
    if (resetSensors == true)
    {
      resetSensors = false;
      l.setPosition(0, degrees);
      r.setPosition(0, degrees);
    }
    int RightFront = RightFrontMotor.position(degrees);
    int LeftFront = LeftFrontMotor.position(degrees);
    int RightRear = RightRearMotor.position(degrees);
    int LeftRear = LeftRearMotor.position(degrees);
    double averagePosition = (RightFront + LeftFront + RightRear + LeftRear)/2;


    error = averagePosition - desiredValue;

    derivative = error - prevError;

    totalError += error;

    double linearMotorPower = (error * kP + derivative * kD + totalError * kI);

    l.spin(fwd, linearMotorPower, voltageUnits::volt);
    r.spin(fwd, linearMotorPower, voltageUnits::volt);


    prevError = error;
    vex::task::sleep(20);
  }
}

void resetSensors()
{
  l.setPosition(0, degrees);
  r.setPosition(0, degrees);
}