#include "vex.h"

using namespace vex;
using namespace std;

double kP = 0;
double kI = 0;
double kD = 0;

double error;
double prevError = 0;
double totalError = 0;
double derivative;

bool resetSensors = false;

void drivePID(double desiredValue, bool resetSensors)
{
  while (true)
  {
    if (resetSensors == true)
    {
      resetSensors = false;
      LeftMotor.setPosition(0, degrees);
      RightMotor.setPosition(0, degrees);
    }
    int leftMotorPosition = LeftMotor.position(degrees);
    int rightMotorPosition = RightMotor.position(degrees);
    double averagePosition = (leftMotorPosition + rightMotorPosition)/2;

    error = averagePosition - desiredValue;

    derivative = error - prevError;

    totalError += error;

    double linearMotorPower = (error * kP + derivative * kD + totalError * kI);

    LeftMotor.spin(fwd, linearMotorPower, voltageUnits::volt);
    RightMotor.spin(fwd, linearMotorPower, voltageUnits::volt);


    prevError = error;
    vex::task::sleep(20);
  }
}