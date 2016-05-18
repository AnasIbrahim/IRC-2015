//edited multy dimension array to jagged arrays

void settingMapMatrix()
{
  //TODO: make sure that matrix is initilized as false - if not add that part
  
  //setting outter diameter as ture
  for (int y = 0; y < 5 + 4 - 1; y++) //yAxis = 5
  {
      editedMapMatrix[0][y] = true;
      editedMapMatrix[10 + 4 - 1][y] = true; //xAxis = 10
  }
  for (int x = 0; x < 10 + 4 - 1; x++) //xAxis = 10
  {
      editedMapMatrix[x][0] = true;
      editedMapMatrix[x][5 + 4 -1] = true; //yAxis = 5
  }
  
  //one of the next two functions is wrong or both are the same
  //adding original mapMatrix in the Edited one
  for (int x = 0; x < 10; x++) //xAxis = 10
  {
    for (int y = 0; y < 5; y++) //yAxis = 5
    {
        editedMapMatrix[x + 2][y + 2] = mapMatrix[x][y];
    }
  }
  
  refillMapMatrix();
  
  AddFalsePoints();
  
}

void refillMapMatrix()
{
    //adding original mapMatrix in the Edited one
    for (int x = 2; x < 10 + 4 - 2; x++) //xAxis = 10
    {
        for (int y = 2; y < 5 + 4 - 2; y++) //yAxis = 5
        {
            mapMatrix[x - 2][y - 2] = editedMapMatrix[x][y];
        }
    }
}

void AddFalsePoints()
//TODO: for pic make 2 first statements in the if statements together and the third in a nested if
{
    //adding memory for last change variable
      //already added in main file

    //1- U shape double node
    while (!checkequality())
    {
        //copy value to PreviouseditedMapMatrix
        copyValueToPreviouseditedMapMatrix();

        //changing map matrix value
        uShapeDoubleNodeChangeeditedMapMatrix();
    }

    //2- u shape one node
    while (!checkequality())
    {
        //copy value to PreviouseditedMapMatrix
        copyValueToPreviouseditedMapMatrix();

        //changing map matrix value
        //2- u shape one node
        uShapeOneNodeChangeeditedMapMatrix();
    }
}

void uShapeDoubleNodeChangeeditedMapMatrix()
{
    //1- U shape double node
    for (int x = 1; x <= 10 + 4 - 2; x++) //xAxis = 10
    {
        for (int y = 1; y <= 5 + 4 - 2; y++) //yAxis = 5
        {
            if (x == 9 & y == 2) { ;}
            if (editedMapMatrix[x][y] == false)
            {
                if ( x == 1 && y == 4) {;}
                if (checkExceptionPoints(x, y - 1) && checkExceptionPoints(x + 1, y - 1) && editedMapMatrix[x + 1][y] == false && editedMapMatrix[x - 1][y - 1] == false && editedMapMatrix[x + 2][y - 1] == false) { editedMapMatrix[x][ y - 1] = false; editedMapMatrix[x + 1][ y - 1] = false; }
                if (checkExceptionPoints(x - 1, y) && checkExceptionPoints(x - 1, y + 1) && editedMapMatrix[x][y + 1] == false && editedMapMatrix[x - 1][y - 1] == false && editedMapMatrix[x - 1][y + 2] == false) { editedMapMatrix[x - 1][ y] = false; editedMapMatrix[x - 1][ y + 1] = false; }
                if (checkExceptionPoints(x + 1, y) && checkExceptionPoints(x + 1, y + 1) && editedMapMatrix[x][y + 1] == false && editedMapMatrix[x + 1][y + 2] == false && editedMapMatrix[x + 1][y - 1] == false) { editedMapMatrix[x + 1][ y] = false; editedMapMatrix[x + 1][ y + 1] = false; }
                if (checkExceptionPoints(x, y + 1) && checkExceptionPoints(x + 1, y + 1) && editedMapMatrix[x + 1][y] == false && editedMapMatrix[x + 2][y + 1] == false && editedMapMatrix[x - 1][y + 1] == false) { editedMapMatrix[x][ y + 1] = false; editedMapMatrix[x + 1][ y + 1] = false; }
            }
        }
    }
}

void uShapeOneNodeChangeeditedMapMatrix()
{
  for (int x = 1; x < 10 + 4 - 2; x++) //xAxis = 10
  {
    for (int y = 1; y < 5 + 4 - 2; y++) //yAxis = 5
    {
      if (editedMapMatrix[x][y] == false)
      {
          if (checkExceptionPoints(x, y - 1) && editedMapMatrix[x - 1][ y - 1] == false && editedMapMatrix[x + 1][ y - 1] == false) { editedMapMatrix[x][ y - 1] = false; }
          if (checkExceptionPoints(x - 1, y) && editedMapMatrix[x - 1][ y - 1] == false && editedMapMatrix[x - 1][ y + 1] == false) { editedMapMatrix[x - 1][ y] = false; }
          if (checkExceptionPoints(x + 1, y) && editedMapMatrix[x + 1][ y + 1] == false && editedMapMatrix[x + 1][ y - 1] == false) { editedMapMatrix[x + 1][ y] = false; }
          if (checkExceptionPoints(x, y + 1) && editedMapMatrix[x + 1][ y + 1] == false && editedMapMatrix[x - 1][ y + 1] == false) { editedMapMatrix[x][ y + 1] = false; }
      }
    }
  }
}

boolean checkExceptionPoints(int x, int y)
{
  boolean result = true;

  //TODO: change code to add exception points of competition
  if (x == 2 && y == 8) { result = false; }

  return result;
}

void copyValueToPreviouseditedMapMatrix()
{
  for (int x = 0; x <= 10 + 4 - 1; x++) //xAxis = 10
  {
      for (int y = 0; y <= 5 + 4 - 1; y++) //yAxis = 5
      {
          previousEditedMapMatrix[x][y] = editedMapMatrix[x][y];
      }
  }   
}

boolean checkequality()
{
  boolean equal = true;
  //if there is a mistake it may not be catched
  for (int x = 2; x <= 10 + 4 - 1 - 2; x++) //xAxis = 10
  {
      for (int y = 2; y <= 5 + 4 - 1 - 2; y++) //yAxis = 5
      {
          if ( previousEditedMapMatrix[x][y] != editedMapMatrix[x][y])
          {
              equal = false;
              break;
          }
      }
  }
  return equal;
}
