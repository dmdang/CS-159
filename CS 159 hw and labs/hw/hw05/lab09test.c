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
int getOctal();
void displayError();
int main (void)
{
  // Local Declarations
  int octalNumValue;

  // Statements
  octalNumValue = getOctal();
  printf("octalNumValue: %d\n", octalNumValue);

  return (0);
} // main


int getOctal()
{
  // Local Declarations
  int octalNum;
  int conditionTest; // tests to see if the code determined the octal number to be invalid
  int max = 8; // each octal digit cannot be greater than the maximum value of 7

  // Statements
  do
  {

  conditionTest = 0;
  printf("Enter octal number: ");
  scanf("%d", &octalNum);

  // Input Validation
  if (octalNum >= 0)
  {

    while (octalNum > 0)
   {

      if (octalNum % 10 >= max)
      {
        conditionTest = 1;
      }

     octalNum /= 10;
    }

  if (conditionTest == 1)
  {
    displayError();
  }
  else
  {
    return (octalNum);
  }

  }

  else
  {
    printf("\nError! Negative numbers are invalid!!\n\n");
  }

  }while((octalNum < 0) || (conditionTest == 1));
} // getInput

void displayError(void)
{
  // Statements
  printf("\nError! Input contains invalid digit!!\n\n");

  return;
} // displayError
