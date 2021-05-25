#include "vex.h"

//Physical Distances on the Bot, measured in inches from the center
float rWidth = 6;
float lWidth = 6;
float bLength = 6;

//Ratios of Odom Wheels, in Inches per Degrees: wheel circumference / 360
float rWheelRatio = -0.024948;
float lWheelRatio = 0.024742; 
float bWheelRatio = -0.024603; 

//Variables to Calulate Deltas in Encoder Values
float prevL = 0;
float prevR = 0; 
float prevB = 0;

//Variables for Position
float prevOrientationRad = 0;
float prevGlobalX = 0; 
float prevGlobalY = 0; 
float absOrientationRad = 0; 
float absOrientationDeg = 0; 

//Used as a Reference for Global X and Y
float localX = 0;
float localY = 0;

//Deltas in Wheels
float deltaL = 0; 
float deltaR = 0;
float deltaB = 0; 

//Absolute Positions
float absGlobalX = 0; 
float absGlobalY = 0; 

//Constants for Motion Control, where "P" is proportional and "D" is derivative.
float turnP = 1.2;
float driveP = 6;
float turnD = 20;
float driveD = 40;
float turnMax = 40;
float driveMax = 60;
float errorMarginBase = 1;
float errorMarginTurnDeg = 0.5;

float pi = 3.14159265359; //Pi

//Encoder Values
float currentL = 0;
float currentR = 0;
float currentB = 0;

float reduceAngle0to360( float angleDeg ) { //Takes an input angle in degrees and converts it to a positive angle value below 360.
  while(!(angleDeg >= 0 && angleDeg < 360)) {
    if( angleDeg < 0 ) { angleDeg += 360; }
    if(angleDeg >= 360) { angleDeg -= 360; }
  }
  return(angleDeg);
}

float reduceAngleMinus180to180( float angleDeg ) { //Takes an input angle in degrees and converts it to an angle between -180 and 180.
  while(!(angleDeg >= -180 && angleDeg < 180)) {
    if( angleDeg < -180 ) { angleDeg += 360; }
    if(angleDeg >= 180) { angleDeg -= 360; }
  }
  return(angleDeg);
}

void updateEncoders() { //Calculates the change in encoder values from the last cycle.
    currentL = (l.rotation(rotationUnits::deg))*(lWheelRatio); 
    currentR = (r.rotation(rotationUnits::deg))*(rWheelRatio); 
    currentB = (b.rotation(rotationUnits::deg))*(bWheelRatio); 

    deltaL = currentL - prevL; 
    deltaR = currentR - prevR;
    deltaB = currentB - prevB;

    prevL = currentL;
    prevR = currentR;
    prevB = currentB; 
}

void updatePosition() { //Approximates the motion of the robot as an arc, and updates its position accordingly
    absOrientationRad = (currentL-currentR)/(rWidth + lWidth); 

    absOrientationDeg = reduceAngle0to360(absOrientationRad*(180/pi)); 

    float deltaA = (deltaL-deltaR)/(rWidth + lWidth); //Change in angle.

    //Calulates coordinates relative to the chord of the robot's arc.
    if (deltaA == 0) { //Prevents divide by zero error.
        localX = deltaB;
        localY = deltaR;
    } else {
        localX = (2*sin(deltaA/2))*((deltaB/deltaA)+bLength); 
        localY = (2*sin(deltaA/2))*((deltaR/deltaA)+rWidth);
    }

    float localPolarAngle = 0;
    float localPolarLength = 0;

    //Caluclates polar coordinates.
    if (localX == 0 && localY == 0){ //Prevents two zeros from being passed to atan2.
        localPolarAngle = 0;
        localPolarLength = 0;
    } else {
        localPolarAngle = atan2(localY, localX); 
        localPolarLength = sqrt(pow(localX, 2) + pow(localY, 2)); 
    }

    //Converts polar coordinates to global coordinates.
    float globalPolarLength = localPolarLength; 
    float globalPolarAngle = localPolarAngle - prevOrientationRad - (deltaA/2);

    float globalX = globalPolarLength*cos(globalPolarAngle); 
    float globalY = globalPolarLength*sin(globalPolarAngle); 

    //Calulates absolute position and orientation.
    absGlobalX = prevGlobalX + globalX; 
    absGlobalY = prevGlobalY + globalY; 

    prevGlobalX = absGlobalX;
    prevGlobalY = absGlobalY;

    //Sets up the previous orientation for deltas.
    prevOrientationRad = absOrientationRad;
}

int positionTrack() { //Background thread used to position track full time.
  while(1){
    updateEncoders();
    updatePosition();

    Brain.Screen.printAt(1, 20, "Absolute X: %f Inches", absGlobalX);
    Brain.Screen.printAt(1, 40, "Absolute Y: %f Inches", absGlobalY);
    Brain.Screen.printAt(1, 60, "Absolute Rotation: %f Radians, %f Degrees", absOrientationRad, absOrientationDeg);
    Brain.Screen.printAt(1, 80, "Left Wheel: %f Inches, %f Degrees", currentL, l.rotation(vex::rotationUnits::deg));
    Brain.Screen.printAt(1, 100, "Right Wheel: %f Inches, %f Degrees", currentR, r.rotation(vex::rotationUnits::deg));
    Brain.Screen.printAt(1, 120, "Back Wheel: %f Inches, %f Degrees", currentB, b.rotation(vex::rotationUnits::deg));
  }
}

void driveReset(float X, float Y, float OrientationDeg) { //Tells the robot its position on the field at the beginning of a match.
  l.setRotation(0, rotationUnits::deg);
  r.setRotation((rWidth+lWidth)*(pi/180)*(OrientationDeg)/(lWheelRatio), rotationUnits::deg);
  b.setRotation(0, rotationUnits::deg);

  prevL = 0;
  prevR = 0;
  prevB = 0;

  updateEncoders();
  updatePosition();

  prevGlobalX = 0;
  prevGlobalY = 0;

  prevGlobalX = X;
  prevGlobalY = Y;
}

void calibratePositionTrackers( void ) { //Used to find the most exact values for distances between encoders and wheel ratios.
  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Move the robot forward 96 inches. Tap to begin. ");
  }
  while(Brain.Screen.pressing()){ }

  driveReset(0, 0, 0);
  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Move the robot forward 96 inches. Tap to end.");
  }
  while(Brain.Screen.pressing()){ }
  float leftwheelratio = 96/l.rotation(vex::rotationUnits::deg);
  float rightwheelratio = 96/r.rotation(vex::rotationUnits::deg);

  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Move the robot right 96 inches. Tap to begin. ");
  }
  while(Brain.Screen.pressing()){ }

  driveReset(0, 0, 0);
  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Move the robot right 96 inches. Tap to end.");
  }
  while(Brain.Screen.pressing()){ }
  float backwheelratio = 96/b.rotation(vex::rotationUnits::deg);

  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Spin the robot clockwise four times. Tap to begin. ");
  }
  while(Brain.Screen.pressing()){ }

  driveReset(0, 0, 0);
  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "Spin the robot clockwise four times. Tap to end.");
  }
  while(Brain.Screen.pressing()){ }
  float drivedistance = ((l.rotation(rotationUnits::deg))*(leftwheelratio)-(r.rotation(rotationUnits::deg))*(rightwheelratio))/(16*pi);

  Brain.Screen.clearScreen();
  while(not(Brain.Screen.pressing())){
    Brain.Screen.printAt(1, 20, "lWheelRatio: %f", leftwheelratio);
    Brain.Screen.printAt(1, 40, "rWheelRatio: %f", rightwheelratio);
    Brain.Screen.printAt(1, 60, "bWheelRatio: %f", backwheelratio);
    Brain.Screen.printAt(1, 80, "Drive Distance (all): %f", drivedistance);
  }
  while(Brain.Screen.pressing()){ }
}