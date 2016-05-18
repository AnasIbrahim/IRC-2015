//last structure made for method that can be called from outside the file: 1- Run  2- RunBeforeIntersection
//TODO: if FR_LT and FL_LT both are on black the robot will continue to make the last signal applied to both motors - may need to be fixed

//TODO: changes must be made before using code on playground

//TODO:braking in stopMotors() function may be changed to brake faster

void Run(char R_Dir)
{
  RunStopBeforeIntersection(R_Dir);
  
  //stopping after intersection for both forward and backward
  if(R_Dir == 'F')
  {
    stoppingAfterIntersectionForward();
  }
  else if(R_Dir == 'B')
  {
    stoppingAfterIntersectionBackward();
  }
  
  //motors already shuted down
  stopMotors();
}

void RunStopBeforeIntersection(char R_Dir)
{
  if(R_Dir == 'F')
  { 
    //running forward
    while(1)
    {
      runningForward();
      //breaking at intersection
      if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW)
      {
        break;
      }
    }
  }
  
  if(R_Dir == 'B')
  {
    //running Backward
    while(1)
    {
      //breaking at intersection
      runningBackward();
      if(digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== LOW  && digitalRead(LND)== LOW )
      {
        break;
      }
    }
  }
   
  //shutting down all motors
  stopMotors(); 
}

void stoppingAfterIntersectionForward()
{
  while(1)
  {
    runningForward();
    if (digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH )
    {
      break;
    }
  }
  //shutting down all motors
  stopMotors(); 
}

void stoppingAfterIntersectionBackward()
{
  while(1)
  {
    runningBackward();
    if(digitalRead(FND)== LOW && digitalRead(BND)== LOW  && digitalRead(center)== LOW  && digitalRead(RND)== HIGH  && digitalRead(LND)== HIGH )
    {
      break;
    }
  }
  //shutting down all motors
  stopMotors(); 
}

void runningForward()
{
  if (digitalRead(FR_LT) == HIGH && digitalRead(FL_LT) == HIGH)
  {
    if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == LOW)
    {
      analogWrite(RightMotorForward,Y);
      analogWrite(LeftMotorForward,W);
//        digitalWrite(RightMotorForward, HIGH);
//        digitalWrite(LeftMotorForward, HIGH);
//        digitalWrite(RightMotorBack, LOW);
//        digitalWrite(LeftMotorBack, LOW);
    }
    else if (digitalRead(BR_LT) == HIGH && digitalRead(BL_LT) == LOW)
    {
      analogWrite(LeftMotorBack,0);
      analogWrite(RightMotorForward,0);
      analogWrite(LeftMotorForward,W + oneMotorSpeed);
      analogWrite(RightMotorBack,Y);
//        digitalWrite(RightMotorForward, LOW);
//        digitalWrite(LeftMotorForward, HIGH);
//        digitalWrite(RightMotorBack, LOW);
//        digitalWrite(LeftMotorBack, LOW);
    }
    else if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == HIGH)
    {
      analogWrite(LeftMotorBack,W);
      analogWrite(RightMotorForward,Y + oneMotorSpeed);
      analogWrite(LeftMotorForward,0);
      analogWrite(RightMotorBack,0);
//        digitalWrite(RightMotorForsward, HIGH);
//        digitalWrite(LeftMotorForward, LOW);
//        digitalWrite(RightMotorBack, LOW);
//        digitalWrite(LeftMotorBack, LOW);
    }
  }
  else if(digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW ) 
  {
    analogWrite(LeftMotorBack,X);
    analogWrite(RightMotorForward,Y);
    analogWrite(LeftMotorForward,W);
    analogWrite(RightMotorBack,Z);
//      digitalWrite(RightMotorForward, HIGH);
//      digitalWrite(LeftMotorForward, HIGH);
//      digitalWrite(RightMotorBack, LOW);
//      digitalWrite(LeftMotorBack, LOW);
  }
  else if (digitalRead(FR_LT) == HIGH && digitalRead(FL_LT) == LOW)
  {
    analogWrite(LeftMotorBack,W);
    analogWrite(RightMotorForward,Y + oneMotorSpeed);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,0);
//      digitalWrite(RightMotorForward, HIGH);
//      digitalWrite(LeftMotorForward, LOW);
//      digitalWrite(RightMotorBack, LOW);
//      digitalWrite(LeftMotorBack, LOW);
  }  
  else if (digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == HIGH)
  {
    analogWrite(LeftMotorBack,0);
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,W + oneMotorSpeed);
    analogWrite(RightMotorBack,Y);
//      digitalWrite(RightMotorForward, LOW);
//      digitalWrite(LeftMotorForward, HIGH);
//      digitalWrite(RightMotorBack, LOW);
//      digitalWrite(LeftMotorBack, LOW);
  }
}

void runningBackward()
{
  if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == LOW )
  {
    analogWrite(LeftMotorBack,Y);
    analogWrite(RightMotorForward,X);
    analogWrite(LeftMotorForward,Z);
    analogWrite(RightMotorBack,W);
  }
  else if (digitalRead(BR_LT) == HIGH && digitalRead(BL_LT) == LOW )
  {
    analogWrite(LeftMotorBack,0);
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,W);
  }  
  else if (digitalRead(BR_LT) == LOW && digitalRead(BL_LT) == HIGH )
  {
    analogWrite(LeftMotorBack,Y);
    analogWrite(RightMotorForward,0);
    analogWrite(LeftMotorForward,0);
    analogWrite(RightMotorBack,0);
  }
}
//===================================================
void Turn (char Dir , byte times)
{
  int x = 0 ;
  if (Dir == 'R')
  {
    while (x < times)
    {
      turnRight();
      delay(700);
      stopMotors();
      while(1)
      {
        turnRight();
        if( digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW)
        {
          x++;
          break;
        }
//        if (RightRotation == HIGH) {analogWrite(RightMotorBack, rotateSpeed);}
//        if (LeftRotation == HIGH) {analogWrite(LeftMotorForward, rotateSpeed);}
//        if (RightRotation == LOW && LeftRotation == LOW) { crossingAnyIntersection(); x++; break;}
      }
    }
  }
  else if (Dir == 'L')
  {
    while (x < times)
    {
      turnLeft();
      delay(700);
      stopMotors();
      while(1)
      {
        turnLeft();
        if( digitalRead(FR_LT) == LOW && digitalRead(FL_LT) == LOW)
        {
          x++;
          break;
        }
//        if (RightRotation == HIGH) {analogWrite(RightMotorForward, rotateSpeed);}
//        if (LeftRotation == HIGH) {analogWrite(LeftMotorBack, rotateSpeed);}
//        if (RightRotation == LOW && LeftRotation == LOW) { crossingAnyIntersection(); x++; break;}
      }
    }
  }
  stopMotors();
}

void turnRight()
{
  analogWrite(LeftMotorForward, rotateSpeed);
  analogWrite(RightMotorBack, rotateSpeed );
  
//  digitalWrite(LeftMotorForward, HIGH);
//  digitalWrite(RightMotorBack, HIGH);
}

void turnLeft()
{
  analogWrite(LeftMotorBack, rotateSpeed);
  analogWrite(RightMotorForward, rotateSpeed);
  
//digitalWrite(LeftMotorBack, HIGH);
//digitalWrite(RightMotorForward, HIGH);
}

void stopMotors()
{
  digitalWrite(LeftMotorForward, HIGH);
  digitalWrite(RightMotorForward, HIGH);
  digitalWrite(LeftMotorBack, HIGH);
  digitalWrite(RightMotorBack, HIGH);
  
  delay(200);
  
  digitalWrite(LeftMotorForward, LOW);
  digitalWrite(RightMotorForward, LOW);
  digitalWrite(LeftMotorBack, LOW);
  digitalWrite(RightMotorBack, LOW);
}

void runForaWhile()
{
  for (int count = 0; count <= 20; count++)
  runningForward();
  delay(50);
}

void crossingAnyIntersection()
{ 
  boolean previousLND, currentLND;
  boolean previousRND, currentRND;
  
  if (digitalRead(LND)== HIGH) {previousLND = HIGH;} else {previousLND = LOW;}
  if (digitalRead(RND)== HIGH) {previousRND = HIGH;} else {previousRND = LOW;}
  
  if (digitalRead(LND)== HIGH) {currentLND = HIGH;} else {currentLND = LOW;}
  if (digitalRead(RND)== HIGH) {currentRND = HIGH;} else {currentRND = LOW;}
  
  while(previousLND == currentLND && previousRND == currentRND)
  {
    runningForward();
      
    if (digitalRead(LND)== HIGH) {currentLND = HIGH;} else {currentLND = LOW;}
    if (digitalRead(RND)== HIGH) {currentRND = HIGH;} else {currentRND = LOW;}
  }
  
  stopMotors();
}
//===================================================
