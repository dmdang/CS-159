/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 7
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: 17916
*
*  Program Description: based on the user's input, this program converts each input value into a binary number and counts the number
of ones in each binary number. the number of ones in each binary is called the cardinality and the most occuring cardinality is determined
and displayed. if there is more than one reoccuring cardinality in the data set, the cardinality along with its decimal value is displayed.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE1 50

// Function Declarations
int getInput(long long int inputData[], long long int inputDataCopy[]);
void convertToBinary(long long int inputData[], long long int onesData[], int count);
int findMode(long long int onesData[], int count, long long int modeData[]);
void displayOutput(long long int modeData[], long long int onesData[], long long int indexData[], long long int inputDataCopy[], int sizeModeData, int count);

int main (void)
{
	// Local Declarations
	long long int inputData [ARRAY_SIZE1]; // the user's entered data
	int count; // number of array elements not equal to -1
	long long int onesData [ARRAY_SIZE1]; // array with the cardinalites of each binary representation of the user's data
	long long int modeData [ARRAY_SIZE1]; // array with the most occuring cardinalities
	long long int indexData [ARRAY_SIZE1]; // array with the indexes corresponding to the user's decimal numbers and the cardinalities in the onesData array
	long long int inputDataCopy [ARRAY_SIZE1]; // copy of the inputData array since the values in the original are changed through pass by address
	int sizeModeData; // number of elements in the modeData array
	
	// Statements
	count = getInput(inputData, inputDataCopy);
	convertToBinary(inputData, onesData, count);
	sizeModeData = findMode(onesData, count, modeData);
	displayOutput(modeData, onesData, indexData, inputDataCopy, sizeModeData, count);
	
	return (0);
} // main

/***************************************************************************
*
*  Function Information
*
*  Name of Function: getInput
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long int inputData[] // user's entered data
*    2. long long int inputDataCopy[] // a copy of the user's entered data since the original array is pass by address and the values change in 
		the function convertToBinary
*    3.
*
*  Function Description: This function allows the user to input a data set of their choice. A copy is made since the values change in the array
in the convertToBinary function
*
***************************************************************************/
int getInput(long long int inputData[], long long int inputDataCopy[])
{
	// Local Declarations
	long long int inputDataElement = 0; // user's data that is passed into the inputData and inputDataCopy arrays
	int count = 0; // counter that will act as the size of each array
	
	// Statements
	printf("Enter the data set now: ");

		while(inputDataElement != -1 && count < 50)
		{
		  scanf("%lld", &inputDataElement);
		  inputData[count] = inputDataElement;
		  inputDataCopy[count] = inputDataElement;
		  if(inputDataElement != -1)
		  {
			  count++;
		  }
		}
		
	return(count);
} // getInput

/***************************************************************************
*
*  Function Information
*
*  Name of Function: convertToBinary
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long int inputData[] // the user's entered data
*    2. long long int onesData[] // empty array that will be filled with the cardinalities of each binary number
*    3. int count // size of the inputData array
*
*  Function Description: This program converts the user's data into binary numbers and counts the number of ones in each number (cardinality). the 
cardinalities are then stored in another array called onesData
*
***************************************************************************/
void convertToBinary(long long int inputData[], long long int onesData[], int count)
{
	// Local Declarations
	int lcv; // loop control variable that scrolls through the user's entered data array
	int remainder; // the result of modding the user's input by 2
	int convElement = 0; // decimal number from input converted to binary
	int counter = 0; // counts the number of iterations of the while loop to update the binary number
	int numOnes = 0; // the number of ones in each binary number
	
	// Statements
	for (lcv = 0; lcv < count; lcv++)
	{
		convElement = 0;
		counter = 0;
		numOnes = 0;
		
		while (inputData[lcv] > 0)
		{
			remainder = inputData[lcv] % 2;
			if (remainder == 1)
			{
				numOnes++;
				onesData[lcv] = numOnes;
			}
			convElement = convElement + (remainder * pow(10, counter)); 			
			inputData[lcv] = inputData[lcv] / 2;
			counter++;
		}
	}
	
	return;
} // convertToBinary

/***************************************************************************
*
*  Function Information
*
*  Name of Function: findMode
*
*  Function Return Type: int
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long int onesData[] // the array that holds the cardinalities of each binary representation of the user's data
*    2. int count // the size of the user's data which happens to be the same size as the onesData array
*    3. long long int modeData[] // empty array that will be filled with the most occuring cardinalties
*
*  Function Description: This function first scrolls through the onesData array and compares each element. if an element
is equal to another element, the match variable increases by one. the second "if else" structure
in the second for loop begins to populate the modeData array with the most occuring cardinalites
from the onesData array. 
***************************************************************************/
int findMode(long long int onesData[], int count, long long int modeData[])
{
	// Local Declarations
	int lcv1; // loop control variable that scrolls through the onesData array to see if there are matching cardinalities
	int lcv2; // loop control variable that scrolls through the onesData array starting one index ahead of lcv1 to see if cardinalities match
	int match = 0; // variable that holds the number of matches within the onesData array
	int maxMatch = 0; // the greatest number of matches (or the frequency) when comparing each cardinality in the onesData array
	int sizeModeData = 0; // the number of elements in the modeData array that holds the most occuring cardinalities
	
	// Statements
	
	for (lcv1 = 0; lcv1 < count; lcv1++)
	{
		match = 0;
		
		for (lcv2 = lcv1 + 1; lcv2 < count; lcv2++)
		{
			if (onesData[lcv1] == onesData[lcv2])
			{
				match++;				
			}
		
		}
		
		if ((match > maxMatch) && (match != 0))
		{
			sizeModeData = 0;
			maxMatch = match;
			modeData[sizeModeData] = onesData[lcv1];
			sizeModeData++;
		}
		else if (match == maxMatch)
		{
			modeData[sizeModeData] = onesData[lcv1];
			sizeModeData++;
		}
	}
	
	return(sizeModeData);
} // findMode

/***************************************************************************
*
*  Function Information
*
*  Name of Function: displayOutput
*
*  Function Return Type: void
*
*  Parameters (list data type, name, and comment one per line):
*    1. long long int modeData[] // the most occuring cardinalities of the onesData array
*    2. long long int onesData[] // the cardinalities of the user's input
*    3. long long int indexData[] // the indexes at which the most common cardinalities occur in the onesData array
*    4. long long int inputDataCopy[] // copy of the user's input since the original was used previously in the convertToBinary function and the values all became zero
     5. int sizeModeData // number of elements
	 6. int count // number of elements in the input data which happens to be the same size as the onesData array
	 
*  Function Description: This function first determines if there is more than one number that occurs most often. If there is, then the function
 finds the indexes of the reoccuring cardinalities in the array storing the cardinality values (onesData) and a new
array called indexData is made to hold these indexes. the maximum decimal value and cardinality is then determined by comparing each element in the inputDataCopy array
at the indexes given by the indexData array. if there is just one cardinality that occurs most often, then it is displayed. 
*
***************************************************************************/
void displayOutput(long long int modeData[], long long int onesData[], long long int indexData[], long long int inputDataCopy[], int sizeModeData, int count)
{
	// Local Declarations
	int lcv2; // loop control variable that scrolls through the onesData array to help find the indexes of the reoccuring cardinalities 
	int lcv1; // loop control variable that scrolls through the modeData array to help find the indexes of the reoccuring cardinalities
	int lcv4; // loop control variable that scrolls through the inputDataCopy array to help find the maximum decimal value and its cardinality 
	int sizeIndexData = 0; // number of elements in the indexData array
	int maxVal; // maximum decimal value of the user's input
	int maxValCardinality; // cardinality value which corresponds to the max decimal value 
	
	// Statements
	if (sizeModeData > 1)
	{
		printf("\nMultiple cardinality values occur most frequently!\n");
		
		for (lcv2 = 0; lcv2 < count; lcv2++)
		{
			for (lcv1 = 0; lcv1 < sizeModeData; lcv1++)
			{
				if (modeData[lcv1] == onesData[lcv2])
				{
					indexData[lcv2] = lcv2;
					sizeIndexData++;
				}
			}
			
		}
	
		maxVal = inputDataCopy[indexData[0]];
		
		for (lcv4 = 1; lcv4 < count; lcv4++)
		{
				if (maxVal < inputDataCopy[indexData[lcv4]])
				{
					maxVal = inputDataCopy[indexData[lcv4]];
					maxValCardinality = onesData[indexData[lcv4]];
				}
		}
		
	printf("Cardinality value %d with a maximum decimal value of: %d\n\n", maxValCardinality, maxVal);
	
	}
	else
	{
		printf("\nMost frequently occuring cardinality in data set: %lld\n\n", modeData[0]);
	}
	
	return;
} // displayOutput

