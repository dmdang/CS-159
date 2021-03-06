
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 02
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Thursday 11:30 - 1:20, SC 189, L08 
*
*  Program Description: The purpose of this program is to assist the user in changing their 5 number bank PIN in such a way that a number in their current bank PIN is not in the same place as their new PIN. The program will also output the number of invalid digits.  
*
***************************************************************************/

#include <stdio.h>
#include <math.h>

int main (void)
{
  // Local Declarations
  int currentPin; // user's current pin
  int newPin; // user's new pin
  int invalDigit; // # invalid digits
  int remainderTenthsC; // remainder after modding current pin by 100
  int remainderHundredC; // remainder after modding current pin by 1000
  int remainderThousandC; // remainder after modding current pin by 10000
  int remainderTenThousandC; // remainder after modding current pin by 100000
  int remainderTenthsN; // remainder after modding new pin by 100
  int remainderHundredN; // remainder after modding new pin by 1000
  int remainderThousandN; // remainder after modding new pin by 10000
  int remainderTenThousandN; // remainder after modding new pin by 100000
  int digitOnesC; // ones digit of current pin
  int digitTenthsC; // tens digit of current pin
  int digitHundredC; // hundreds digit of current pin
  int digitThousandC; // thousands digit of current pin
  int digitTenThousandC; // ten thousands digit of current pin
  int digitOnesN; // ones digit of new pin
  int digitTenthsN; // tens digit of new pin
  int digitHundredN; // hundreds digit of new pin
  int digitThousandN; // thousands digit of new pin
  int digitTenThousandN; // ten thousands digit of new pin

  // Statements
  printf("Enter your current PIN: ");
  scanf("%d", &currentPin);
  printf("Enter your new PIN: ");
  scanf("%d", &newPin);

  // Calculations
  digitOnesC = currentPin % 10; // ones digit of current pin
  remainderTenthsC = currentPin % 100; // calculates remainder after modding current pin by 100
  digitTenthsC = ((remainderTenthsC) - digitOnesC) * 0.1; //  tens digit of current pin
  remainderHundredC = currentPin % 1000; // calculates remainder after modding current pin by 1000
  digitHundredC = ((remainderHundredC) - (digitTenthsC * 10 + digitOnesC)) * .01; // hundreds digit of current pin 
  remainderThousandC = currentPin % 10000; // calculates remainder after modding current pin by 10000
  digitThousandC = ((remainderThousandC) - (digitHundredC * 100 + digitTenthsC * 10 + digitOnesC)) * .001; // thousands digit of current pin
  remainderTenThousandC = currentPin % 100000; // calculates remainder after modding current pin by 100000
  digitTenThousandC = ((remainderTenThousandC) - (digitThousandC * 1000 + digitHundredC * 100 + digitTenthsC * 10 + digitOnesC)) * .0001; // ten thousands digit of current pin

  digitOnesN = newPin % 10; // ones digit of new pin
  remainderTenthsN = newPin % 100; // calculates remainder after modding new pin by 100
  digitTenthsN = ((remainderTenthsN) - digitOnesN) * 0.1; // tens digit of new pin
  remainderHundredN = newPin % 1000; // calculates remainder after modding new pin by 1000
  digitHundredN = ((remainderHundredN) - (digitTenthsN * 10 + digitOnesN)) * .01; // hundreds digit of new pin
  remainderThousandN = newPin % 10000; // calculates remainder after modding new pin by 10000
  digitThousandN = ((remainderThousandN) - (digitHundredN * 100 + digitTenthsN * 10 + digitOnesN)) * .001; // thousands digit of new pin
  remainderTenThousandN = newPin % 100000; // calculates remainder after modding new pin by 100000
  digitTenThousandN = ((remainderTenThousandN) - (digitThousandN * 1000 + digitHundredN * 100 + digitTenthsN * 10 + digitOnesN)) * .0001; // ten thousands digit of current pin

  invalDigit = (((digitTenThousandC + 1) / (digitTenThousandN + 1)) * ((digitTenThousandN + 1) / (digitTenThousandC + 1))) + (((digitThousandC + 1) / (digitThousandN + 1)) * ((digitThousandN + 1) / (digitThousandC + 1))) + (((digitHundredC + 1) / (digitHundredN + 1)) * ((digitHundredN + 1) / (digitHundredC + 1))) + (((digitTenthsC + 1) / (digitTenthsN + 1)) * ((digitTenthsN + 1) / (digitTenthsC + 1))) + (((digitOnesC + 1) / (digitOnesN + 1)) * ((digitOnesN + 1) / (digitOnesC + 1))); // calculates number of invalid digits 

  // Output
  printf("\nTotal number of invalid digits: %d\n", invalDigit);

return 0;
} // main
