//int goToPoint(int xfinalPosition, int yfinalPosition)
//{
//  int xfixedStartTrack[10][2] = {getATrack(xfinalPosition, yfinalPosition, true) };
//  int yFixedStartTrack[10][2] = {getATrack(xfinalPosition, yfinalPosition, false)};
//  int finalTrack[10][2] = {compareTracksTime(xfixedStartTrack[][], yFixedStartTrack[][])};
//  
//  return finalTrack[][];
//}
//
//int getATrack(int xfinalPosition, int yfinalPosition, boolean xFixed)
//{
//  //TODO: CPX & CPY may be deleted
//  //storing start point
//  int previousXCurrentPoint = CPX;
//  int previousYCurrentPoint = CPY;
//
//  int nextTrackPoint;
//  xfinalPosition += 2;
//  yfinalPosition += 2;
//
//  boolean previousXFixed = xFixed;
//  unsigned char restartCounter;
//
//  restart:
//  nextTrackPoint = -1;
//  int track[33][2]; //maximum length of track = ((xAxis * yAxis) * 3) / 2
//
//  //intializing track array with -1 to avoid garbage when comparing non intialized points in track
//  for (int i = 0; i < 33; i++)
//  {
//    track[i][0] = -1;
//    track[i][1] = -1;
//  }
//
//  //adding cP to track array to avoid turning back
//  track[0][0] = CPX;
//  track[0][1] = CPY;
//  nextTrackPoint++;
//
//  completeTrack:
//  restartCounter = 0;
//  nextTrackPoint++;
//  while (CPX != xfinalPosition || CPY != yfinalPosition)
//  {
//    //1-  if xFixed == true
//    if (xFixed == true)
//    {
//      boolean positiveYClear = false;
//      boolean negativeYClear = false;
//
//      //checking if +ve direction is clear
//      if (editedMapMatrix[CPX][CPY + 1] == true && findIfExistinTrack(CPX, CPY + 1, track))
//      {
//        positiveYClear = true;
//      }
//      //checking if -ve direction is clear
//      if (editedMapMatrix[CPX][CPY - 1] == true && findIfExistinTrack(CPX, CPY - 1, track))
//      {
//        negativeYClear = true;
//      }
//
//      //determining which track to go - if both ways are clear choose one and assign the other as false
//      if (positiveYClear && negativeYClear)
//      {
//        if (abs(yfinalPosition - (CPY + 1)) <= abs(yfinalPosition - (CPY - 1)))
//        {
//          negativeYClear = false;
//        }
//        else if (abs(yfinalPosition - (CPY - 1)) < abs(yfinalPosition - (CPY + 1)))
//        {
//          positiveYClear = false;
//        }
//      }
//
//      //going in +ve y direction
//      if (positiveYClear)
//      {
//        addPoint(CPX, CPY + 1, track, nextTrackPoint);
//        CPY++;
//        goto completeTrack;
//      }
//      //going in -ve y direction
//      else if (negativeYClear)
//      {
//        addPoint(CPX, CPY - 1, track, nextTrackPoint);
//        CPY--;
//        goto completeTrack;
//      }
//      Fixed = false;
//      restartCounter++;
//    }
//    //2-  if xFixed == false
//    else if (xFixed == false)
//    {
//      bool positiveXClear = false;
//      bool negativeXClear = false;
//
//      //checking if +ve direction is clear
//      if (editedMapMatrix[CPX + 1][CPY] == true && findIfExistinTrack(CPX + 1, CPY, track))
//      {
//        positiveXClear = true;
//      }
//      //checking if -ve direction is clear
//      if (editedMapMatrix[CPX - 1][CPY] == true && findIfExistinTrack(CPX - 1, CPY, track))
//      {
//        negativeXClear = true;
//      }
//
//      //determining which track to go - if both ways are clear choose one and assign the other as false
//      if (positiveXClear && negativeXClear)
//      {
//        if (abs(xfinalPosition - (CPX + 1)) <= abs(xfinalPosition - (CPX - 1)))
//        {
//          negativeXClear = false;
//        }
//        else if (abs(xfinalPosition - (CPX - 1)) < abs(xfinalPosition - (CPX + 1)))
//        {
//          positiveXClear = false;
//        }
//      }
//
//      //going in +ve x direction
//      if (positiveXClear)
//      {
//        addPoint(CPX + 1, CPY, track, nextTrackPoint);
//        CPX++;
//        goto completeTrack;
//      }
//      //going in -ve y direction
//      if (negativeXClear)
//      {
//        addPoint(CPX - 1, CPY, track, nextTrackPoint);
//        CPX--;
//        goto completeTrack;
//      }
//
//      xFixed = true;
//      restartCounter++;
//    }
//
//    if (restartCounter > 1)
//    {
//      //TODO: checkException may be added before assigning False
//      //TODO: Changed value may be returned true after current track is finished
//      editedMapMatrix[CPX][CPY] = false;
//      CPX = previousXCurrentPoint;
//      CPY = previousYCurrentPoint;
//      xFixed = previousXFixed;
//      goto restart;
//    }
//  }
//}
//
//  CPX = previousXCurrentPoint;
//  CPY = previousYCurrentPoint;
//  return track;
//}
//
//boolean findIfExistinTrack(float x, float y, int (&track)[][])
//{
//  boolean result = true;
//  for (int element = 0; element < 33; element++) //not sure if track.length / 2 is right
//  {
//    if (track[element][0] == x && track[element][1] == y)
//    {
//      result = false;
//    }
//  }
//  return result;
//}
//
//void addPoint(int x, int y, int (&track)[][], int nextTrackPoint)
//{
//  track[nextTrackPoint][0] = x;
//  track[nextTrackPoint][1] = y;
//  //setting next point in track for a value(2 * (xAxis * yAxis)) cannot be pratically real to use it in other method later
//  track[nextTrackPoint + 1][0] = 2 * (xAxis * yAxis);
//  track[nextTrackPoint + 1][1] = 2 * (xAxis * yAxis);
//}
//
//int determineNumberOfPoint(int (&trackArray)[][])
//{
//  int numberOfPoints = 0;
//  for (int count = 0; trackArray[count][0] != 2 * (xAxis * yAxis) && trackArray[count][1] != 2 * (xAxis * yAxis); count++)
//  {
//    //stop condition for loop is read if the next point have the unpracticall value assigned previously in addPoint method
//    numberOfPoints++;
//  }
//  return numberOfPoints;
//}
//
//int measurenumberOfTurns(int (&trackArray)[][], int numberOfPoints)
//{
//  int numberOfTurns = 0;
//  for (int count = 0; count <= numberOfPoints - 2; count++)
//  { 
//    if (trackArray[count][0] != trackArray[count + 2][0] && trackArray[count][1] != trackArray[count + 2][1])
//    {
//      numberOfTurns++;
//    }
//  }
//  return numberOfTurns;
//}
//int compareTracksTime(int (&xfixedStartTrack)[][], int (&yFixedStartTrack)[][])
//{
//  int numberOFPoints1 = 0;
//  int numberOFPoints2 = 0;
//  int numberOFTurns1 = 0;
//  int numberOFTurns2 = 0;
//  
//  //determine number of point in each track
//  numberOFPoints1 = determineNumberOfPoint(xfixedStartTrack[][]);
//  numberOFPoints2 = determineNumberOfPoint(yFixedStartTrack[][]);
//  
//  numberOFTurns1 = measurenumberOfTurns(xfixedStartTrack[][], numberOFPoints1);
//  numberOFTurns2 = measurenumberOfTurns(yFixedStartTrack[][], numberOFPoints2);
//  
//  if (numberOFTurns1 < numberOFTurns2)
//  {
//    return xfixedStartTrack;
//  }
//  else if (numberOFTurns2 < numberOFTurns1)
//  {
//    return yFixedStartTrack;
//  }
//  else if (numberOFTurns1 == numberOFTurns2)
//  {
//    return xfixedStartTrack;
//  }
//  return xfixedStartTrack; //won't be used in excuetion
//}
////---------------------------------------------------
////---------------------------------------------------
////---------------------------------------------------

