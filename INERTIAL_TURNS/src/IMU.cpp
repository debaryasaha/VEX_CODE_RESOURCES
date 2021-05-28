#include "vex.h"

using namespace vex;
using namespace std;


void IMU::pTurns(double degrees)
{
  double target = degrees;
  double error = target - Inertial.rotation();
  double kP = 0.0; // this is for you to tune
  
  while (abs(error) > 1)
  {
    error = target - Inertial.rotation();
    double percent = kP * error + 20 * error / abs(error);
    LeftMotor.spin(directionType::fwd, percent, pct);
    RightMotor.spin(directionType::rev, percent, pct);
    vex::task::sleep(downTime);
  }
  LeftMotor.stop();
  RightMotor.stop();
} 

void IMU::pdTurns(double degrees)
{
  double target = degrees;
  double error = target - Inertial.rotation();
  double kP = 0.7; // this is for you to tune, however, this tuning should work pretty well
  double kD = 0.1; // // this is for you to tune, however, this tuning should work pretty well
  double prevError = error;
  
  while (abs(error) > 1)
  {
    error = target - Inertial.rotation();
    double derivative = (error - prevError)/downTime;
    double percent = kP * error + kD * derivative;
    LeftMotor.spin(directionType::fwd, percent, pct);
    RightMotor.spin(directionType::rev, percent, pct);
    vex::task::sleep(downTime);
    prevError = error;
  }
  LeftMotor.stop();
  RightMotor.stop();
}
