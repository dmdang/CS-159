/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*  1. santos45@purdue.edu
*  2. askipwor@purdue.edu
*  3. dangd@purdue.edu (delete line if no third partner)
*
*  Lab #: 9
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: 17916
*
*  Program Description:
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

// Function Declarations
void getOctal(int* octalNum);
void displayError();
int evaluationLoop(int octal);

int main (void)
{
  // Local Declarations
  int octalNum;

  // Statements
  getOctal(&octalNum);

  return (0);
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getOctal
*
*     Programmer's Name: David, Jordan, Anthony 
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* octalNum // the octal number input by the user
*       2.
*       3.
*
*     Function Description: this function excludes negative integers and integers with digits greater than or equal
to eight from being entered as input.
*
***************************************************************************/
void getOctal(int* octalNum)
{
  // Local Declarations
  int conditionTest; // tests to see if the code determined the octal number to be invalid
 
  // Statements
  do
  {

  conditionTest = 0;
  printf("Enter octal number: ");
  scanf("%d", octalNum);

  // Input Validation
  if (*octalNum >= 0)
  {

    conditionTest = evaluationLoop(*octalNum);

  if (conditionTest == 1)
  {
    displayError();
  }
  else
  {
    return;
  }

  }

  else
  {
    printf("\nError! Negative numbers are invalid!!\n\n");
  }

  }while((*octalNum < 0) || (conditionTest == 1));
} // getOctal

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayError
*
*     Programmer's Name: David, Jordan, Anthony 
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. this function has no parameters
*       2.
*       3.
*
*     Function Description: this function prints an error message if the user input contains an integer
with digits greater than or equal to 8
*
***************************************************************************/
void displayError(void)
{
  // Statements
  printf("\nError! Input contains invalid digit!!\n\n");

  return;
} // displayError

/***************************************************************************
*
*     Function Information
*
*     Name of Function: evaluationLoop
*
*     Programmer's Name: David, Jordan, Anthony 
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int octal // the octal number input by the user
*       2.
*       3.
*
*     Function Description: this function analyzes each digit in the octal number to see if any digits are
greater than or equal to 8
*
***************************************************************************/
int evaluationLoop (int octal)
{
	// Local Declarations
	int conditionTest; // test to see if code determined the octal number to be invalid
	int max = 8; // max value of digits in the octal number
	
	// Statements
	while (octal > 0)
   {

      if (octal % 10 >= max)
      {
        conditionTest = 1;
      }

     octal /= 10;
    }
	
	return(conditionTest);
} // evaluationLoop
