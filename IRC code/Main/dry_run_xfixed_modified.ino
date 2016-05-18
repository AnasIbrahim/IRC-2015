////determination of block places will be changed - block 1 place will be assumed from x = 0 to x = 4 and block 2 place will be assumed form x = 5 to x = 9
////in dry run make sure to make a delay after ariving to an intersection to overcome fillet in block places
//
//void dryRun()
//{
//  Serial.print("started dry run\n");
//  //changing PWM values - may not be needed
//    int PreviousY = Y;
//    int PreviousW = W;
//    int PreviousRotateSpeed = rotateSpeed;
//    int PreviousOneMotorSpeed = oneMotorSpeed;
//
//    rotateSpeed = 50;    
//    W = 140;
//    Y = W + rightMotorSpeedCorrection;
//    oneMotorSpeed = 70;
//    
//  RunStopBeforeAnyIntersection(); //getting to first node
//  Serial.print("walking y = 0\n");
//  walkLines(0, 'a'); //ascending
//  runForaWhile(); Turn('R', 1); Run('F'); Run('F'); RunStopBeforeAnyIntersection();
//  Serial.print("walking y = 3\n");
//  walkLines(3, 'd'); //right turn will be made in the inside codes - descending
//  runForaWhile(); Turn('R', 1); Run('F'); RunStopBeforeAnyIntersection();
//  Serial.print("walking y = 1\n");
//  walkLines(1, 'a'); //right turn will be made in the inside codes - ascending
//  runForaWhile(); Turn('R', 1); Run('F'); Run('F'); Run('F'); RunStopBeforeAnyIntersection();
//  Serial.print("walking y = 4\n");
//  walkLines(4, 'd'); //right turn will be made in the inside codes - descending
//  runForaWhile(); Turn('R', 1); Run('F'); RunStopBeforeAnyIntersection();
//  Serial.print("walking y = 2\n");
//  walkLines(2, 'a'); //left turn will be made in the inside codes - ascending
//  
//  // finished dry run
//  //adding exception points
//    addingExceptionPoints();
//    
//    signal();
//    
//  //returning PWM values to it's original
//    Y = PreviousY;
//    W = PreviousW;
//    rotateSpeed = PreviousRotateSpeed;
//    oneMotorSpeed = PreviousOneMotorSpeed;
//}
//
//void walkLines(int yCount, char dir)
//{
//  if (dir == 'a')
//  {
//    Serial.print("entered ascending mode\n");
//    if (yCount == 0) { setNode(0, 0); crossingAnyIntersection();}
//    if (yCount == 1) { setNode(0, 1); Turn('R', 1); crossingAnyIntersection();}
//    if (yCount == 2) { setNode(0, 2); Turn('R', 1); crossingAnyIntersection();}
//    for (int xCount = 1; xCount <= 9; xCount++)
//    {
//      RunStopBeforeAnyIntersection();
//      setNode(xCount, yCount);
//      crossingAnyIntersection();
//    }
//  }
//  else if (dir == 'd')
//  {
//    Serial.print("entered desscending mode\n");
//    if (yCount == 3) { setNode(9, 3); Turn('R', 1); RunStopBeforeAnyIntersection();}
//    if (yCount == 4) { setNode(9, 4); Turn('R', 1); RunStopBeforeAnyIntersection();}
//    for(int xCount = 8; xCount >= 0; xCount--)
//    {
//      RunStopBeforeAnyIntersection();
//      setNode(xCount, yCount);
//      crossingAnyIntersection();
//    }
//  }
//}
//
//void RunStopBeforeAnyIntersection()
//{
//  while(1)
//    {
//      runningForward();
//      //breaking at Any intersection
//      if      (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW) { break; }
//      else if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== HIGH  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW) { break; }
//      else if (digitalRead(FND)== HIGH && digitalRead(BND)== HIGH  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH) { break; }
//    }
//    
//    stopMotors();
//}
//
//void setNode(int xPlace,int yPlace)
//{
//  Serial.print("setting node: ");
//  if      (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW)
//  { mapMatrix[xPlace][yPlace] = true; Serial.print(xPlace); Serial.print(' '); Serial.print(yPlace); Serial.print(':'); Serial.print(mapMatrix[xPlace][yPlace]); Serial.print("\n");}
//  else if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== HIGH  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW)
//  { mapMatrix[xPlace][yPlace] = false; Serial.print(xPlace); Serial.print(' '); Serial.print(yPlace); Serial.print(':'); Serial.print(mapMatrix[xPlace][yPlace]); Serial.print("\n");}
//  else if (digitalRead(FND)== HIGH && digitalRead(BND)== HIGH  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH)
//  {
//    mapMatrix[xPlace][yPlace] = false;
//    if (xPlace <= 4) {block1X = xPlace; block1Y = yPlace;}
//    else             {block2X = xPlace; block2Y = yPlace;}
//    Serial.print(xPlace); Serial.print(' '); Serial.print(yPlace); Serial.print(':'); Serial.print(mapMatrix[xPlace][yPlace]); Serial.print("\n");
//  }
//}
//
//void addingExceptionPoints()
//{
//}
//
//void signal()
//{
//  
//}
