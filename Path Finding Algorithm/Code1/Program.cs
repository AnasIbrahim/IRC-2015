using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;
using System.Collections;

namespace Code1
{
    class Program
    //TODO: use embedded point class if the microcontroller support it
    //TODO: erase false points that been added by gototrack points
    {
        static byte xAxis, yAxis;
        static bool[,] mapMatrix; //map matrix get changed according to grid size
        static bool[,] EditedMapMatrix;
        static byte[,] exceptionMatrix = new byte[5, 2];
        
        //TODO: value of currentPoint added in editedMapMatrix //TODO: make current point dynamic
        static int cPX = 2;
        static int cPY = 2;

        static int xStartZone , yStartZone;

        static void Main(string[] args)
        {
            settingMapMatrix(); //won't be written in microntroller
            dryRun(); //fill mapMatrix - fill //TODO: exception for block places

            //adding static Exception (value in EditedMapMatrix)
            xStartZone = 2; yStartZone = 1;

            //adding Exception points (static and dynamic)
            AddExceptionPoint();

            mapMatrixEdit();

            viewEditedMapMatrix(); //delete in pic
            AddFalsePoints();
            viewEditedMapMatrix(); //delete in pic

            refillMapMatrix();
            viewMapMatrix(); //delete in pic

            goToPoint(0, 6);
        }

        private static void refillMapMatrix()
        {
            //adding original mapMatrix in the Edited one
            for (int x = 2; x < xAxis + 4 - 2; x++)
            {
                for (int y = 2; y < yAxis + 4 - 2; y++)
                {
                    mapMatrix[x - 2, y - 2] = EditedMapMatrix[x, y];
                }
            }
        }

        private static void AddExceptionPoint() //added in dry run in microcontroller
        //static Exception Point (for competition exception point)
        //1- Automatic Start Zone (added in EditedMapMatrix() method)
        //2- Automatic End Zone
        //3- Entry Point for sub Grid Point(4,7)
        //4- block Desposit Zones (3 Zones)
        //dynamic Exception Point: Block Places
        //Erase block places Exception after removing eack block
        {
            exceptionMatrix[0, 0] = 0;//x for End Zone - in mapMatrix
            exceptionMatrix[0, 0] = 7;//y for End Zone - in mapMatrix
            //TODO: complete Code for exception and relate it with check exception points
        }

        private static void AddFalsePoints() //will be called extractingVShapes in microcontroller
        //TODO: for pic make 2 first statements in the if statements together and the third in a nested if
        {
            //adding memory for last change variable
            bool[,] previousEditedMapMatrix = new bool[xAxis + 4, yAxis + 4];

            //1- U shape double node
            while (!checkequality(previousEditedMapMatrix))
            {
                //copy value to PreviousEditedMapMatrix
                copyValueToPreviousEditedMapMatrix(previousEditedMapMatrix);

                //changing map matrix value
                uShapeDoubleNodeChangeEditedMapMatrix();
            }

            //2- u shape one node
            while (!checkequality(previousEditedMapMatrix))
            {
                //copy value to PreviousEditedMapMatrix
                copyValueToPreviousEditedMapMatrix(previousEditedMapMatrix);

                //changing map matrix value
                //2- u shape one node
                uShapeOneNodeChangeEditedMapMatrix();
            }

            //closing start point after finish editing
            EditedMapMatrix[xStartZone, yStartZone] = false;
        }

        private static void uShapeDoubleNodeChangeEditedMapMatrix()
        {
            //1- U shape double node
            for (int x = 1; x <= xAxis + 4 - 2; x++)
            {
                for (int y = 1; y <= yAxis + 4 - 2; y++)
                {
                    if (x == 9 & y == 2) { ;}
                    if (EditedMapMatrix[x, y] == false)
                    {
                        if ( x == 1 && y == 4) {;}
                        if (checkExceptionPoints(x, y - 1) && checkExceptionPoints(x + 1, y - 1) && EditedMapMatrix[x + 1, y] == false && EditedMapMatrix[x - 1, y - 1] == false && EditedMapMatrix[x + 2, y - 1] == false) { EditedMapMatrix[x, y - 1] = false; EditedMapMatrix[x + 1, y - 1] = false; }
                        if (checkExceptionPoints(x - 1, y) && checkExceptionPoints(x - 1, y + 1) && EditedMapMatrix[x, y + 1] == false && EditedMapMatrix[x - 1, y - 1] == false && EditedMapMatrix[x - 1, y + 2] == false) { EditedMapMatrix[x - 1, y] = false; EditedMapMatrix[x - 1, y + 1] = false; }
                        if (checkExceptionPoints(x + 1, y) && checkExceptionPoints(x + 1, y + 1) && EditedMapMatrix[x, y + 1] == false && EditedMapMatrix[x + 1, y + 2] == false && EditedMapMatrix[x + 1, y - 1] == false) { EditedMapMatrix[x + 1, y] = false; EditedMapMatrix[x + 1, y + 1] = false; }
                        if (checkExceptionPoints(x, y + 1) && checkExceptionPoints(x + 1, y + 1) && EditedMapMatrix[x + 1, y] == false && EditedMapMatrix[x + 2, y + 1] == false && EditedMapMatrix[x - 1, y + 1] == false) { EditedMapMatrix[x, y + 1] = false; EditedMapMatrix[x + 1, y + 1] = false; }
                    }
                }
            }
        }

        private static void uShapeOneNodeChangeEditedMapMatrix()
        {
            for (int x = 1; x < xAxis + 4 - 2; x++)
            {
                for (int y = 1; y < yAxis + 4 - 2; y++)
                {
                    if (EditedMapMatrix[x, y] == false)
                    {
                        if (checkExceptionPoints(x, y - 1) && EditedMapMatrix[x - 1, y - 1] == false && EditedMapMatrix[x + 1, y - 1] == false) { EditedMapMatrix[x, y - 1] = false; }
                        if (checkExceptionPoints(x - 1, y) && EditedMapMatrix[x - 1, y - 1] == false && EditedMapMatrix[x - 1, y + 1] == false) { EditedMapMatrix[x - 1, y] = false; }
                        if (checkExceptionPoints(x + 1, y) && EditedMapMatrix[x + 1, y + 1] == false && EditedMapMatrix[x + 1, y - 1] == false) { EditedMapMatrix[x + 1, y] = false; }
                        if (checkExceptionPoints(x, y + 1) && EditedMapMatrix[x + 1, y + 1] == false && EditedMapMatrix[x - 1, y + 1] == false) { EditedMapMatrix[x, y + 1] = false; }
                    }
                }
            }
        }

        private static bool checkExceptionPoints(int x, int y)
        {
            bool result = true;

            //TODO: change code to add exception points of competition
            if (x == 2 && y == 8) { result = false; }

            return result;
        }

        private static void copyValueToPreviousEditedMapMatrix(bool[,] previousEditedMapMatrix)
        {
            for (int x = 0; x <= xAxis + 4 - 1; x++)
            {
                for (int y = 0; y <= yAxis + 4 - 1; y++)
                {
                    previousEditedMapMatrix[x, y] = EditedMapMatrix[x, y];
                }
            } 
        }

        private static bool checkequality(bool[,] previousEditedMapMatrix)
        {
            bool equal = true;
            //if there is a mistake it may not be catched
            for (int x = 2; x <= xAxis + 4 - 1 - 2; x++)
            {
                for (int y = 2; y <= yAxis + 4 - 1 - 2; y++)
                {
                    if ( previousEditedMapMatrix[x, y] != EditedMapMatrix[x, y])
                    {
                        equal = false;
                        break;
                    }
                }
            }
            return equal;
        }

        private static void settingMapMatrix()
        {
            //setting height and length
            xAxis = 7; //5 for IRC
            yAxis = 7; //10 for IRC
            mapMatrix = new bool[xAxis, yAxis];
            
            //setting map matrix as true - will be changed for pic
            for (int x = 0; x < xAxis; x++)
            {
                for (int y = 0; y < yAxis; y++)
                {
                    mapMatrix[x, y] = true;
                }
            }
        }

        private static void mapMatrixEdit() //static was erased
        {
            //making new matrix with edges
            EditedMapMatrix = new bool[xAxis + 4, yAxis + 4];

            //adding false for inner edges - not needed

            //adding exception static of Automatic Start Zone
            EditedMapMatrix[xStartZone, yStartZone] = true;

            //adding true for outter edges - not needed
            
            //four corners are added twice - may be edited later
            
            for (int y = 0; y < yAxis + 4 - 1; y++)
            {
                EditedMapMatrix[0, y] = true;
                EditedMapMatrix[xAxis + 4 - 1, y] = true;
            }
            for (int x = 0; x < xAxis + 4 - 1; x++)
            {
                EditedMapMatrix[x, 0] = true;
                EditedMapMatrix[x, yAxis + 4 -1] = true;
            }

            //adding original mapMatrix in the Edited one
            for (int x = 0; x < xAxis; x++)
            {
                for (int y = 0; y < yAxis; y++)
                {
                    EditedMapMatrix[x + 2, y + 2] = mapMatrix[x, y];
                }
            }
        }

        private static void dryRun()
        {
            //TODO: nodes added manually - change code for pic
            mapMatrix[0, 1] = false;
            mapMatrix[0, 4] = false;
            mapMatrix[0, 2] = false;
            mapMatrix[1, 4] = false;
            mapMatrix[2, 2] = false;
            mapMatrix[2, 3] = false;
            mapMatrix[2, 4] = false;
            mapMatrix[3, 0] = false;
            mapMatrix[3, 2] = false;
            mapMatrix[4, 2] = false;
            mapMatrix[4, 6] = false;
            mapMatrix[5, 4] = false;
            mapMatrix[6, 2] = false;
        }

        private static void viewEditedMapMatrix()
        {
            //viewing Edited map Matrix on screen
            for (int y = yAxis + 2 - 1; y > 1; y--)
            {
                for (int x = 2; x < xAxis + 2; x++)
                {
                    Console.Write("{0} ", Convert.ToInt32(EditedMapMatrix[x, y]));
                }
                Console.Write("\n");
            }
            Console.WriteLine("\n\n");
        }

        private static void viewMapMatrix()
        {
            //viewing Edited map Matrix on screen
            for (int y = yAxis - 1; y >= 0; y--)
            {
                for (int x = 0; x < xAxis; x++)
                {
                    Console.Write("{0} ", Convert.ToInt32(mapMatrix[x, y]));
                }
                Console.Write("\n");
            }
            Console.WriteLine("\n\n");
        }

        public static void goToPoint(int xfinalPosition, int yfinalPosition)
        {
            int[,] finalTrack;
            int[,] xfixedStartTrack = getATrack(xfinalPosition, yfinalPosition, true);
            int[,] yFixedStartTrack = getATrack(xfinalPosition, yfinalPosition, false);
            finalTrack = compareTracksTime(xfixedStartTrack, yFixedStartTrack);
        }

        private static int[,] getATrack(int xfinalPosition, int yfinalPosition, bool xFixed) //xStart and yStart values in mapMatrix
        //TODO: cPX & cPY may be deleted
        {
            //storing start point
            int previousXCurrentPoint = cPX;
            int previousYCurrentPoint = cPY; 

            int nextTrackPoint;
            xfinalPosition += 2;
            yfinalPosition += 2;

            bool previousXFixed = xFixed;
            byte restartCounter;


            restart:
            nextTrackPoint = -1;
            int[,] track = new int[Convert.ToInt32(((xAxis * yAxis) * 2) / 3), 2]; //maximum length of track = ((xAxis * yAxis) * 3) / 2

            //track need to be intialized before used in microcontrollers as most of them depend on c++

            //adding cP to track array to avoid turning back
            track[0, 0] = cPX;
            track[0, 1] = cPY;
            nextTrackPoint++;

            completeTrack:
            restartCounter = 0;
            nextTrackPoint++;
            while(cPX != xfinalPosition || cPY != yfinalPosition)
            {
            //1-  if xFixed == true
                if (xFixed == true)
                {
                    bool positiveYClear = false;
                    bool negativeYClear = false;
                    
                    //checking if +ve direction is clear
                    if (EditedMapMatrix[cPX, cPY + 1] == true && findIfExistinTrack(cPX, cPY + 1, track)) { positiveYClear = true; }
                    //checking if -ve direction is clear
                    if (EditedMapMatrix[cPX, cPY - 1] == true && findIfExistinTrack(cPX, cPY - 1, track)) { negativeYClear = true; }
                    
                    //determining which track to go - if both ways are clear choose one and assign the other as false
                    if (positiveYClear && negativeYClear)
                    {
                        if      (Math.Abs(yfinalPosition - (cPY + 1)) <= Math.Abs(yfinalPosition - (cPY - 1))) { negativeYClear = false; }
                        else if (Math.Abs(yfinalPosition - (cPY - 1)) <  Math.Abs(yfinalPosition - (cPY + 1))) { positiveYClear = false; }
                    }
                    
                    //going in +ve y direction
                    if      (positiveYClear) { addPoint(cPX, cPY + 1, track, nextTrackPoint); cPY++; goto completeTrack; }
                    //going in -ve y direction
                    else if (negativeYClear) { addPoint(cPX, cPY - 1, track, nextTrackPoint); cPY--; goto completeTrack; }

                    xFixed = false;
                    restartCounter++;
                }
                //2-  if xFixed == false
                else if (xFixed == false)
                {
                    bool positiveXClear = false;
                    bool negativeXClear = false;
                    
                    //checking if +ve direction is clear
                    if (EditedMapMatrix[cPX + 1, cPY] == true && findIfExistinTrack(cPX + 1, cPY, track)) { positiveXClear = true; }
                    //checking if -ve direction is clear
                    if (EditedMapMatrix[cPX - 1, cPY] == true && findIfExistinTrack(cPX - 1, cPY, track)) { negativeXClear = true; }

                    //determining which track to go - if both ways are clear choose one and assign the other as false
                    if(positiveXClear && negativeXClear)
                    {
                        if      (Math.Abs(xfinalPosition - (cPX + 1)) <= Math.Abs(xfinalPosition - (cPX - 1))) { negativeXClear = false; }
                        else if (Math.Abs(xfinalPosition - (cPX - 1)) <  Math.Abs(xfinalPosition - (cPX + 1))) { positiveXClear = false; }
                    }

                    //going in +ve x direction
                    if (positiveXClear) { addPoint(cPX + 1, cPY, track, nextTrackPoint); cPX++; goto completeTrack; }
                    //going in -ve y direction
                    if (negativeXClear) { addPoint(cPX - 1, cPY, track, nextTrackPoint); cPX--; goto completeTrack; }

                    xFixed = true;
                    restartCounter++;
                }
                
                
                if (restartCounter > 1)
                {

                    //TODO: checkException may be added before assigning False
                    //TODO: Changed value may be returned true after current track is finished
                    EditedMapMatrix[cPX, cPY] = false;
                    cPX = previousXCurrentPoint;
                    cPY = previousYCurrentPoint;
                    xFixed = previousXFixed;
                    goto restart;
                }
            }

            cPX = previousXCurrentPoint;
            cPY = previousYCurrentPoint;
            return track;
        }

        private static bool findIfExistinTrack(float x, float y, int[,] track)
        {
            bool result = true;
            for (int element = 0; element < track.Length / 2; element++) //not sure if track.length / 2 is right
            {
                if (track[element, 0] == x && track[element, 1] == y) { result = false; }

            }
            return result;
        }

        private static void addPoint(int x, int y, int[,] track, int nextTrackPoint)
        {
            track[nextTrackPoint, 0] = x;
            track[nextTrackPoint, 1] = y;

            //setting next point in track for a value(2 * (xAxis * yAxis)) cannot be pratically real to use it in other method later
            track[nextTrackPoint + 1, 0] = 2 * (xAxis * yAxis);
            track[nextTrackPoint + 1, 1] = 2 * (xAxis * yAxis);
        }

        private static int[,] compareTracksTime(int[,] xfixedStartTrack, int[,] yFixedStartTrack)
        {
            int numberOFPoints1 = 0;
            int numberOFPoints2 = 0;
            int numberOFTurns1 = 0;
            int numberOFTurns2 = 0;

            //determine number of point in each track
            numberOFPoints1 = determineNumberOfPoint(xfixedStartTrack);
            numberOFPoints2 = determineNumberOfPoint(yFixedStartTrack);

            numberOFTurns1 = measurenumberOfTurns(xfixedStartTrack, numberOFPoints1);
            numberOFTurns2 = measurenumberOfTurns(yFixedStartTrack, numberOFPoints2);

            if      (numberOFTurns1 < numberOFTurns2)  { return xfixedStartTrack; }
            else if (numberOFTurns2 < numberOFTurns1)  { return yFixedStartTrack; }
            else if (numberOFTurns1 == numberOFTurns2) { return xfixedStartTrack; }
            return xfixedStartTrack; //won't be used in excuetion
        }

        private static int determineNumberOfPoint(int[,] trackArray)
        {
            int numberOfPoints = 0;
            for (int count = 0; trackArray[count, 0] != 2 * (xAxis * yAxis) && trackArray[count, 1] != 2 * (xAxis * yAxis); count++)
            //stop condition for loop is read if the next point have the unpracticall value assigned previously in addPoint method
            {
                numberOfPoints++;
            }
            return numberOfPoints;
        }

        private static int measurenumberOfTurns(int[,] trackArray, int numberOfPoints)
        {
            int numberOfTurns = 0;
            for (int count = 0; count <= numberOfPoints - 2; count++)
            {
                if (trackArray[count, 0] != trackArray[count + 2, 0] && trackArray[count, 1] != trackArray[count + 2, 1])
                {
                    numberOfTurns++;
                }
                
            }
            return numberOfTurns;
        }
    }
}