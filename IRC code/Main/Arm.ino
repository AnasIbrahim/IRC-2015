int openAngleCatch = 30;
int closingAngleCatch = 75;
int upAngleArm = 10;
int downAngleArm = 140;

void catchBlock()
{
  catchServo.write(openAngleCatch);
  delay(2000);
  armServo.write(downAngleArm);
  delay(2000);
  catchServo.write(closingAngleCatch);
  delay(2000);
  armServo.write(upAngleArm);
  delay(2000);
}

void releaseBlock()
{
  armServo.write(downAngleArm);
  delay(2000);
  catchServo.write(openAngleCatch);
  delay(2000);
  armServo.write(upAngleArm);
  delay(2000);
}
