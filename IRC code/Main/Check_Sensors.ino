//used to check if senors is connected or not and determine it's state (white or Black)
//you should add delay between senors reading statements
bool checkSensor(int sensor)
{
    if (digitalRead(sensor) == HIGH)
    { 
      Serial.print("b");
    }
    else
    {
      Serial.print("w");
    }
    Serial.print(" ");
}

void checkAllSensors()
{
  checkSensor(FR_LT);
  checkSensor(FL_LT);
  checkSensor(FND);
  checkSensor(center);
  checkSensor(BND);
  checkSensor(BR_LT);
  checkSensor(BL_LT);
  Serial.print("    ");
  checkSensor(LND);
  checkSensor(RND);
  Serial.print("    ");
  checkSensor(LeftRotation);
  checkSensor(RightRotation);

  Serial.print("\n");
}


