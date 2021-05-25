using namespace vex;

extern  task positiontrackingtask;

//Physical Distances on the Bot
extern float rWidth;
extern float lWidth;
extern float bLength;

//Ratios of Odom Wheels
extern float rWheelRatio;
extern float lWheelRatio; 
extern float bWheelRatio; 

//Variables to Calulate Deltas
extern float prevL;
extern float prevR; 
extern float prevB;

//Variables for Position
extern float prevOrientationRad;
extern float prevGlobalX; 
extern float prevGlobalY; 
extern float absOrientationRad; 
extern float absOrientationDeg; 

//Used as a Reference for Global X and Y
extern float localX;
extern float localY;

//Deltas in Wheels
extern float deltaL; 
extern float deltaR;
extern float deltaB; 

//Absolute Positions
extern float absGlobalX; 
extern float absGlobalY; 

//Constants for Motion Control
extern float turnP;
extern float driveP;
extern float turnD;
extern float driveD;
extern float turnMax;
extern float driveMax;
extern float errorMarginBase;
extern float errorMarginTurnDeg;

extern float pi;

//Encoder Values
extern float currentL;
extern float currentR;
extern float currentB;

//Odometry Functions
float reduceAngle0to360( float angleDeg );

float reduceAngleMinus180to180( float angleDeg );

void updateEncoders();

void updatePosition();

int positionTrack();

void driveReset ( float X = 0, float Y = 0, float OrientationDeg = 0 );

void calibratePositionTrackers( void );