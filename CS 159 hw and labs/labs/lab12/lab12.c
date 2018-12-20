/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*        1. santos45@purdue.edu
*        2. dangd@purdue.edu
*        3. askipwor@purdue.edu (delete line if no third partner)
*
*  Lab #: 11
*:Q1

*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: 11:30-1:20 Thursdays L08 17916
*
*  Program Description: This program receives 25 integers as input and displays the mean
and standard deviation of the data. The program also looks for outliers in the data and
calculates a new mean and standard deviation with the outliers excluded from the data set
if there happens to be outliers at all.
*
***************************************************************************/
#include<stdio.h>
#include<math.h>
#include<stdlib.h>

// Function Declarations

int getArrayData(int*);
float getMeanArray(int*,int);
float getStandardDeviation(int*,float,int);
float checkForOutliers(int*,float,float,int);
float getMeanWithoutOutliers(int*,float,float,float,int);
float getSDWithoutOutliers(int*,float,float,float,float,int);
void bubbleSort(int*,int);
void outputFunction(float,float,float,float,float,int);

int main(void)
{
  int IntegerArray[50]; // an array created to store the data set entered by the user
  float MeanOfArray = 0; // the average of the array with outliers
  float StandardDeviation = 0; // the standard deviation of the array with outliers
  float TotalOutliers = 0; // the number of outliers in the data set
  float MeanWithoutOutliers = 0; // the average of the array without the outliers
  float SDWithoutOutliers = 0; // the standard deviation of the array without the outliers
  int Size = 0;

        Size = getArrayData(IntegerArray);
        MeanOfArray = getMeanArray(IntegerArray,Size);
        StandardDeviation = getStandardDeviation(IntegerArray,MeanOfArray,Size);
        TotalOutliers = checkForOutliers(IntegerArray,MeanOfArray,StandardDeviation,Size);
        MeanWithoutOutliers = getMeanWithoutOutliers(IntegerArray,TotalOutliers,MeanOfArray,StandardDeviation,Size);
        SDWithoutOutliers = getSDWithoutOutliers(IntegerArray,TotalOutliers,MeanWithoutOutliers,MeanOfArray,StandardDeviation,Size);
		bubbleSort(IntegerArray,Size);
        outputFunction(MeanOfArray,StandardDeviation,TotalOutliers,MeanWithoutOutliers,SDWithoutOutliers,Size);
	   
        return(0);
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getArrayData
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array to store data entered by user
*       2.
*       3.
*
*     Function Description: this function takes the data set given by the user and stores it
*     in an array called "IntegerArray"
*
***************************************************************************/
int getArrayData(int IntArray[])
{
  // Local Declarations
  int lcv = 0; // loop control variable to access each index of the array
  int IntArrayElement = 0;

  // Statements
        printf("\nEnter data now: ");
        while(IntArray[lcv] != -1 && lcv < 50)
        {
            scanf("%d",&IntArrayElement);
			IntArray[lcv] = IntArrayElement;
			if(IntArrayElement != -1)
				{
					lcv++;
				}
        }
	return(lcv);
} // getArrayData

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getMeanArray
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array used to store data set entered by user
*       2.
*       3.
*
*     Function Description: This function calculates the mean of the data set
*
***************************************************************************/
float getMeanArray(int IntArray[],int size)
{
  // Local Declarations
  int lcv;
  float sumofarray = 0; // sum of all elements in the array
  float meanofarray = 0; // mean of the elements in the array
 
  // Statements
        for(lcv = 0; lcv < size; lcv++)
                {
                        sumofarray += IntArray[lcv];
                }
       
        meanofarray = sumofarray / size;
       
        return(meanofarray);
} // getMeanArray

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getStandardDeviation
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array used to store data set entered by user
*       2.float meanofarray // mean of the elements in the array
*       3.
*
*     Function Description: This function calculates the standard deviation of the data set
*
***************************************************************************/
float getStandardDeviation(int IntArray[], float meanofarray, int size)
{
  // Local Declarations
  int lcv;
  float standarddeviationofarray = 0; // variable that holds the standard deviation of the array
  float sumofdifference = 0; // sum of the differences between the array elements and the mean of the array
 
  // Statements
        for(lcv = 0; lcv < size; lcv++)
        {
                sumofdifference += pow((IntArray[lcv] - meanofarray),2);
        }
       
        standarddeviationofarray = sqrt((1.0 / (size - 1.0)) * sumofdifference);
       
        return(standarddeviationofarray);
} // getStandardDeviation
/***************************************************************************
*
*     Function Information
*
*     Name of Function: bubbleSort
*
*     Programmer's Name: William Crum (Book)
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array that stores data set entered by user
*       2.float meanofarray // mean of all the elements in the array
*       3.float standarddeviationofarray // standard deviation of the elements in the array
*
*     Function Description: This function checks the user's data for any outliers and counts the number of
*     outliers (a number is an outlier if the difference between the mean and the array element is greater than
*     1.5 times the standard deviation of the array)
*
***************************************************************************/
void bubbleSort(int IntArray[], int size)
{
	int numPasses;
	int lcv; //
	int temp;
	
	for(numPasses = 0; numPasses < size; numPasses++)
		{
			for(lcv = 0; lcv < size - numPasses; lcv++)
				{
					if(IntArray[lcv] < IntArray[lcv + 1])
						{
							temp = IntArray[lcv];
							IntArray[lcv] = IntArray[lcv + 1];
							IntArray[lcv + 1] = temp;
						}//END OF IF
				}//END OF NEIGHBOR COMPARING LOOP
		}//END OF PASSES LOOP
}//END OF FUNCTION
/***************************************************************************
*
*     Function Information
*
*     Name of Function: checkForOutliers
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array that stores data set entered by user
*       2.float meanofarray // mean of all the elements in the array
*       3.float standarddeviationofarray // standard deviation of the elements in the array
*
*     Function Description: This function checks the user's data for any outliers and counts the number of
*     outliers (a number is an outlier if the difference between the mean and the array element is greater than
*     1.5 times the standard deviation of the array)
*
***************************************************************************/
float checkForOutliers(int IntArray[], float meanofarray, float standarddeviationofarray, int size)
{
  // Local Declarations
  int lcv;
  float numofoutliers = 0; // the number of outliers in the data set
 
  // Statements
        for(lcv = 0; lcv < size; lcv++)
                {
                        if(fabs(meanofarray - IntArray[lcv]) > (1.5 * standarddeviationofarray))
                                {
                                        numofoutliers++;
                                }
                }
        return(numofoutliers);
} // checkForOutliers
/***************************************************************************
*
*     Function Information
*
*     Name of Function: getMeanWithoutOutliers
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array that holds the user's data
*       2.float numofoutliers // number of outliers found in the data set
*       3.float meanofarray // mean of the elements in the data set
*       4.float standarddeviationofarray // standard deviation of the elements in the data set
*
*     Function Description: This function finds the mean of the data set while excluding the outliers according to
*     our definition of an outlier
*
***************************************************************************/
float getMeanWithoutOutliers(int IntArray[], float numofoutliers, float meanofarray, float standarddeviationofarray, int size)
{
  // Local Declarations
  int lcv = 0;
  float sumofarray = 0; // sum of the elements in the array without the outliers
  float meanofarraywithoutoutliers = 0; // mean of the elements in the array without the outliers
  int temp; // variable that acts as temporary storage for the array element
 
  // Statements
        for(lcv = 0; lcv < size; lcv++)
                {
                        temp = IntArray[lcv];
                        if(fabs(meanofarray - IntArray[lcv]) > (1.5 * standarddeviationofarray))
                                {
                                        IntArray[lcv] = 0;
                                }
						sumofarray += IntArray[lcv];
                        IntArray[lcv] = temp;
                }
        meanofarraywithoutoutliers = sumofarray / (size - numofoutliers);
        return(meanofarraywithoutoutliers);
} // getMeanWithoutOutliers

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getSDWithoutOutliers
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1.int IntArray[] // array that holds the user's data set
*       2.float numofoutliers // number of outliers found in the original data set
*       3.float meanofarraywithoutoutliers // mean of the array elements excluding outliers
*       4.float meanofarray // mean of the original array
*       5.float standarddeviationofarray // standard deviation of the original array
*
*     Function Description: This function excludes the outliers in the original data set and calculates the
*     new standard deviation for the modified data set
*
***************************************************************************/
float getSDWithoutOutliers(int IntArray[], float numofoutliers, float meanofarraywithoutoutliers, float meanofarray, float standarddeviationofarray, int size)   
{
  // Local Declarations
  int lcv;
  float sumofdifference = 0; // sum of the difference between each array element and the mean of the data set without outliers
  float sdwithoutoutliers = 0; // the standard deviation without outliers

  // Statements
        for(lcv = 0; lcv < size; lcv++)
                {
                        if(fabs(IntArray[lcv] - meanofarray) <= (1.5 * standarddeviationofarray))
                                {
                                        //sumofdifference += 0;
                                       
                                        sumofdifference += pow(((double)IntArray[lcv] - meanofarraywithoutoutliers),2);
                                }
                 
                }
        sdwithoutoutliers = sqrt((1.0 / (size - 1.0 - numofoutliers)) * sumofdifference);
        return(sdwithoutoutliers);
} // getSDWithoutOutliers
/***************************************************************************
*
*     Function Information
*
*     Name of Function: outputFunction
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.float meanofarray // mean of the data set including outliers
*       2.float standarddeviationofarray // standard deviation of the data set including outliers
*       3.float numofoutliers // number of outliers found in data set
*       4.float meanofarraywithoutoutliers // mean of the data set without outliers
*       5.float sdwithoutoutliers // standard deviation of the data set without outliers
*
*     Function Description: This function displays the mean and standard deviation of the original data set, the number of
*     outliers in the original data set, and the mean and standard deviation of the data set without the outliers
*
***************************************************************************/
//int getQuartiles(int IntArray[], int size)
//{
//	int medianindex = size / 2
//	
//	for(lcv = 0; lcv < medianindex; lcv++)
//		{
//			

/***************************************************************************
*
*     Function Information
*
*     Name of Function: outputFunction
*
*     Programmer's Name: Jordan, Anthony, David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.float meanofarray // mean of the data set including outliers
*       2.float standarddeviationofarray // standard deviation of the data set including outliers
*       3.float numofoutliers // number of outliers found in data set
*       4.float meanofarraywithoutoutliers // mean of the data set without outliers
*       5.float sdwithoutoutliers // standard deviation of the data set without outliers
*
*     Function Description: This function displays the mean and standard deviation of the original data set, the number of
*     outliers in the original data set, and the mean and standard deviation of the data set without the outliers
*
***************************************************************************/
void outputFunction(float meanofarray, float standarddeviationofarray, float numofoutliers, float meanofarraywithoutoutliers, float sdwithoutoutliers, int size)
{
int medianofArray = size / 2;
int quartile1index = medianofArray / 2;
int quartile3index = size - quartile1index;
  // Statements
        printf("\n\nMean of original data: %.2f\n", meanofarray);
        printf("Standard Deviation of original data: %.2f\n", standarddeviationofarray);
		if(size % 2 == 0)
		{
			printf("\nQuartile #1 index: %d",quartile1index);
			printf("\nQuartile #3 index: %d",quartile3index - 1);
			printf("\nMedian indexes: %d and %d\n", medianofArray - 1, medianofArray);
			//printf("Interquartile Range * 1.5: %f\n",quartileRange);
		}
		if(size % 2 == 1)
		{
			printf("\nQuartile #1 index: %d and %d",quartile1index, quartile1index + 1);
			printf("\nQuartile #3 index: %d and %d",quartile3index - 2, quartile3index - 1);
			printf("\nMedian index: %d\n",medianofArray);
			//printf("Interquartile Range * 1.5: %f\n",quartileRange);
		}
        if(numofoutliers > 0)
        {
                printf("\nTotal Outliers: %.0f\n", numofoutliers);
                printf("Mean without outliers: %.2f\n", meanofarraywithoutoutliers);
                printf("Standard Deviation without outliers: %.2f\n", sdwithoutoutliers);
        }
} // outputFunction
