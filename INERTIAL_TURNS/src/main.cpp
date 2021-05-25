#include "vex.h"

using namespace vex;
using namespace std;

int main() {
 // Initializing Robot Configuration. DO NOT REMOVE!
  vexcodeInit();
  Inertial.calibrate();
  // waits for the Inertial Sensor to calibrate
  while (Inertial.isCalibrating()) {
    wait(100, msec);
  }
}
