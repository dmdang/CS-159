/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 6
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
*  Program Description: given 30 days of data on prices,
*  this program calculates the total number of increases and decreases,
*  the average increase and decrease, and the changes in price between each day.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>
#define ARRAY_SIZE1 30
#define ARRAY_SIZE2 29

// Function Declarations
void getPriceData(float priceData[]);
void calcChanges(float priceData[], float changeData[]);
void calcIncreaseDecrease(float changeData[], int* numIncreases, int* numDecreases);
void calcAverages(float changeData[], int numIncreases, int numDecreases, float*, float*);
void displayOutput(int numIncreases, int numDecreases, float averageIncrease, float averageDecrease, float changeData[]);

int main (void)
{
	// Local Declarations
	float priceData [ARRAY_SIZE1]; // array that stores the prices for the thirty days entered by the user
	float changeData [ARRAY_SIZE2]; // array that stores the differences in prices between each day
	int numIncreases = 0; // the number of increases through the 30 days
	int numDecreases = 0; // the number of decreases through the 30 days
	float averageIncrease; // the average increase through the 30 days
	float averageDecrease; // the average decrease through the 30 days
	
	// Statements
	getPriceData(priceData);
	calcChanges(priceData, changeData);
	calcIncreaseDecrease(changeData, &numIncreases, &numDecreases);
	calcAverages(changeData, numIncreases, numDecreases, &averageIncrease, &averageDecrease);
	displayOutput(numIncreases, numDecreases, averageIncrease, averageDecrease, changeData);
	
	return (0);
	
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getPriceData
*
*     Programmer's Name: David 
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.float priceData[] // empty array to be filled with the prices through the 30 days
*       2.
*       3.
*
*     Function Description: This function allows the user to input the price data for the 30 days into the array
*     priceData
*
***************************************************************************/
void getPriceData(float priceData[])
{
	// Local Declarations
	int i; // loop control variable
	
	// Statements
	printf("Enter the price data for 30 days: ");
	for (i = 0; i < 31; i++)
	{
		scanf("%f", &priceData[i]);
	}
	
	return;
} // getPriceData

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcChanges
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.float priceData[] // data entered by user for the 30 days stored in array
*       2.float changeData[] // empty array to be filled with calculated price changes
*       3.
*
*     Function Description: This function populates the changeData array with the difference in prices between each of the
*     30 days. 
*
***************************************************************************/
void calcChanges(float priceData[], float changeData[])
{
	// Local Declarations
	int i; // loop control variable
	
	// Statements
	for (i = 0; i < 29; i++)
	{
		changeData[i] = priceData[i + 1] - priceData[i];
	}
	
	return;
} // calcChanges

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcIncreaseDecrease
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. float changeData[] // array that holds the data representing the changes in prices 
*       2. int* numIncreases // variable in main that represents the number of increases in prices
*       3. int* numDecreases // variable in main that represents the number of decreases in prices
*
*     Function Description: This function calculates the number of increases and decreases in prices for the 30 days 
*
***************************************************************************/
void calcIncreaseDecrease(float changeData[], int* numIncreases, int* numDecreases)
{
	// Local Declarations
	int i; // loop control variable
	// Statements
	for (i = 0; i < 29; i++)
	{
		if (changeData[i] > 0)
		{
			(*numIncreases)++;
		}
		else if (changeData[i] < 0)
		{
			(*numDecreases)++;
		}
		
	}
	
	return;
} // calcIncreaseDecrease

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcAverages
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. float changeData[] // array that holds the data representing the changes in prices
*       2. int numIncreases // number of increases in prices
*       3. int numDecreases // number of decreases in prices
*       4. float* averageIncrease // variable in main that represents the average increase in prices
*       5. float* averageDecrease // variable in main that represents the average decrease in prices
*
*     Function Description: This function calculates the average increase and decrease in prices for the 30 days
*
***************************************************************************/
void calcAverages(float changeData[], int numIncreases, int numDecreases, float* averageIncrease, float* averageDecrease)
{
	// Local Declarations
	int i; // loop control variable
	float totalIncrease = 0; // running total of the increases
	float totalDecrease = 0; // running total of the decreases
	
	// Statements
	for (i = 0; i < 29; i++)
	{
		if (changeData[i] > 0)
		{
			totalIncrease += changeData[i];
		}
		else
		{
			totalDecrease += changeData[i];
		}
	}
	
	*averageIncrease = totalIncrease / numIncreases;
	*averageDecrease = (totalDecrease / numDecreases) * -1;
	
	return;
} // calcAverages

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayOutput
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int numIncreases // the number of increases in prices 
*       2. int numDecreases // the number of decreases in prices
*       3. float averageIncrease // the average increase in prices 
*       4. float averageDecrease // the average decrease in prices
*       5. float changeData[] // array that holds that data on price changes for the 30 days
*
*
*     Function Description: This function displays the number of increases and decreases, the average increase and decrease, and 
*     the change in price for each of the 30 days. 
*
***************************************************************************/
void displayOutput(int numIncreases, int numDecreases, float averageIncrease, float averageDecrease, float changeData[])
{
	// Local Declarations
	int i; // loop control variable
	int counter = 0; // counter used to print 5 values for each line
	
	// Statements
	if (numIncreases > 0 && numDecreases == 0) 
	{
		printf("\n\nTotal increases: %d Average increase: $ %.2f\n", numIncreases, averageIncrease);
	}
	else if (numDecreases > 0 && numIncreases == 0)
	{
		printf("\n\nTotal decreases: %d Average decrease: $ %.2f\n", numDecreases, averageDecrease);
	}
	else if (numDecreases > 0 && numIncreases > 0)
	{
		printf("\n\nTotal increases: %d Average increase: $ %.2f", numIncreases, averageIncrease);
		printf("\nTotal decreases: %d Average decrease: $ %.2f\n", numDecreases, averageDecrease);
	}
	else if (numDecreases == 0 && numIncreases == 0)
	{
		printf("\n");
	}
	
	printf("\nPrice changes for past 30 days: \n");
	for (i = 0; i < 29; i++)
	{
		if (changeData[i] < 0)
		{
			printf("$%7.2f ", changeData[i]);
		}
		else 
		{
			printf("$%+7.2f ", changeData[i]);
		}
		
		counter++;
		
		if (counter % 5 == 0)
		{
			printf("\n");
		}
	}
	
	printf("\n\n");
	
	return;
} // displayOutput








