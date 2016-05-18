//IRC 2015 - moskey team Automatic ROBOT program

//Problems:
//Automatic: 1- rotation after rotation: robot can get out of track
//                Solution: avoid rotation after rotation speacially in dry run and depend on that the logic of the competition will not make this condition
//           2- making turns in the nodes close the the balls
//                Solutions: make this points false and avoid it - but robot can get stuck
//                           reduce robot dimensions
//           3- block rotate when get lifted:
//                Solutions: add a servo in the arm
//                           add a mechanism in the manual to rotate block

//TODO: make dynamic exceptions points true after a block is deposited

#include <math.h>
#include <Servo.h>

//motors speeds
int rightMotorSpeedCorrection = 0; //can't exceed --
int leftMotorSpeedCorrection = 0; //can't exceed --
int oneMotorSpeed = 0;
byte rotateSpeed = 170; //WARNING: MAXIUM ROTATION SPEED IS --
int X= 0;
int W= 180; //WARNING: MAXIUM SPEED FOR W IS 210
int Y= W + rightMotorSpeedCorrection;
int Z= 0;

Servo catchServo;
Servo armServo;

int LeftMotorBack = 4;
int RightMotorForward = 5;
int LeftMotorForward = 6;
int RightMotorBack  = 7;

int FR_LT = 25 ; // Front-Right line tracking sensor //
int FL_LT = 23 ; // Front-Left line tracking sensor //
int BR_LT = 26 ; // Back-Right line tracking sensor //
int BL_LT = 28 ; // Back-Left line tracking sensor //
int FND = 27 ; // Front Node Detector //
int BND = 24 ; // Front Back Detector //
int LND  = 22 ; // Front Left Detector //
int RND  = 22 ; // Front Right Detector // //not used - changed from 30
int center  = 29 ; // center of Node Detector //
int RightRotation = 32;
int LeftRotation = 32; //chnaged from 37

int CPX = 0;
int CPY = 0;
char Look = 'F'; //intiallized with forward

boolean mapMatrix[10][5]; //x:10 y:5
boolean editedMapMatrix[10 + 4][5 + 4]; //x:10 y:5 - setting playground grid size for IRC - the +4 added are to overcome the exceptions when extracting special shapes (v shapes) - 2 lines for every shape
boolean previousEditedMapMatrix[10 + 4][5 + 4];
boolean track1[33][2];
boolean track2[33][2];
boolean track3[33][2];
boolean track4[33][2];
boolean track5[33][2];
byte xAxis = 10, yAxis = 5;
byte block1X = 0, block1Y = 0, block2X = 0, block2Y = 0;
  
void setup()
{
  pinMode( LeftMotorForward ,OUTPUT);
  pinMode( RightMotorForward ,OUTPUT);
  pinMode( LeftMotorBack ,OUTPUT);
  pinMode( RightMotorBack ,OUTPUT);

  pinMode( FR_LT ,INPUT);
  pinMode( FL_LT ,INPUT);
  pinMode( BR_LT ,INPUT);
  pinMode( BL_LT ,INPUT);
  pinMode( center  ,INPUT);
  pinMode( FND  ,INPUT);
  pinMode( BND  ,INPUT);
  pinMode( RND  ,INPUT);
  pinMode( LND  ,INPUT);
  pinMode(RightRotation, INPUT);
  pinMode(LeftRotation, INPUT);
  
  armServo.attach(9);
  catchServo.attach(8);

  Serial.begin(9600);
}

void loop()
{
//  dryRun();
  
//  while ( digitalRead() == LOW) { } //do nothing until button is pushed
  
  //determine first track to catch block - track1
//  if ( mapMatrix[block1X - 1, block1Y    ] == true) {track1 = getTrack(block1X - 1, block1Y    , 0, 0);}
//  if ( mapMatrix[block1X    , block1Y - 1] == true) {track1 = getTrack(block1X    , block1Y - 1, 0, 0);}
//  
//  if ( mapMatrix[block1X + 1, block1Y    ] == true) {track1 = getTrack(block1X + 1, block1Y    , 0, 0);}
//  if ( mapMatrix[block1X    , block1Y + 1] == true) {track1 = getTrack(block1X    , block1Y + 1, 0, 0);}

//  runningForward();

//  RunStopBeforeAnyIntersection();
  
//  digitalWrite(RightMotorForward, HIGH);
//  digitalWrite(LeftMotorForward, HIGH);
  
//  analogWrite(RightMotorForward,Y);
//  analogWrite(LeftMotorForward,W);
  
//  checkAllSensors();
//  delay(100);

  Run('F');
    Run('F');
      Run('F');
        Run('F');
          Run('F');
            Run('F');
              Run('F');
  Turn('R', 1);
  Run('F');
  Run('F');
  Turn('L', 1);
  Run('F');
  Turn('R', 1);
            Run('F');
            Run('F');
              Run('F');
//  Run('F');
//  Turn('L', 1);
  
//    Next_Look(1, 0);
//    Next_Look(1, 1);
//    Next_Look(1, 2);
//    Next_Look(2, 2);
//    Next_Look(2, 1);
//    Next_Look(3, 1);
  
  while(1){};
}
  //===================================================

