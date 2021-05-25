#pragma once

using namespace vex;
using namespace std;

class IMU
{
  private:
  public:
  IMU();
  static const int downTime = 20;
  static void pTurns(double degrees);
  static void pdTurns(double degrees);
};