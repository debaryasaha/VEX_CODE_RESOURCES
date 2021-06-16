#pragma once

void driveForward(float inches);
void Turn(float degrees);
void drivePID(double desiredValue, bool resetsensors);
void resetSensors();