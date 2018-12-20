/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. dangd@purdue.edu
*	 2. boyces@purdue.edu
*	 3. pbuisson@purdue.edu 
*
*  Lab #: 7 
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
*  Program Description: This program converts the specified place digit from three 4-digit numbers into three separate binary numbers and then concatenates them. From the concatenated binary number, a final decimal number is calculated. Then, the decimal number is used as a seed to generate a random number from 1 to 15 which corresponds to a combination of manipulations to be made to the binary representation of each place digit the user chose. Finally, the program concatenates the new binary number. 
*
***************************************************************************/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

// Function Declaration
void getInput(char* place, int* intOne, int* intTwo, int* intThree);
int getIntegers(char place, int integer);
int convertBinary(int digit);
void splitBinary(int* binaryD1, int* binaryD2, int* binaryD3, int* binaryD4, int binaryNumber);
int calcBinary(int digitOnes, int digitTens, int digitHundreds, int digitThousands, int power);
int addBinary(int binaryValue1, int binaryValue2, int binaryValue3);
int genRandomNum(int binaryValue);
int calcSwitch(int rand_num, int binaryD1, int binaryD2, int binaryD3, int binaryD4);
void displayOutput(int binaryOne, int binaryTwo, int binaryThree, int binaryValue, int rand_num, int new_binary1, int new_binary2, int new_binary3);

int main (void)
{
  // Local Declarations
  char place; // power of ten character that user selects
  int intOne; // first four digit number input by user
  int intTwo; // second four digit number input by user
  int intThree; // third four digit number input by user
  int digitOne; // isolated place digit of first four digit number 
  int digitTwo; // isolated place digit of second four digit number
  int digitThree; // isolated place digit of third four digit number
  int binaryOne; // binary representation of isolated place digit of first number input
  int binaryTwo; // binary representation of isolated place digit of second number input
  int binaryThree; // binary representation of isolated place digit of third number input
  int binaryOneD1; // ones digit of the first binary number
  int binaryOneD2; // tens digit of the first binary number
  int binaryOneD3; // hundreds digit of the first binary number
  int binaryOneD4; // thousands digit of the first binary number
  int binaryTwoD1; // ones digit of the second binary number
  int binaryTwoD2; // tens digit of the second binary number
  int binaryTwoD3; // hundreds digit of the second binary number
  int binaryTwoD4; // thousands digit of the second binary number
  int binaryThreeD1; // ones digit of the third binary number
  int binaryThreeD2; // tens digit of the third binary number
  int binaryThreeD3; // hundreds digit of the third binary number
  int binaryThreeD4; // thousands digit of the third binary number
  int binaryValue; // value of the concatenated binary number
  int binaryValue1; // decimal value of the first binary number
  int binaryValue2; // decimal value of the second binary number
  int binaryValue3; // decimal value of the third binary number
  int power = 11; // power to which each place of the concatenated binary number is raised
  int rand_num; // random number generated
  int new_binary1; // new first binary number
  int new_binary2; // new second binary number
  int new_binary3; // new third binary number
  
  // Executable Statements
  getInput(&place, &intOne, &intTwo, &intThree);
  digitOne = getIntegers(place, intOne);
  digitTwo = getIntegers(place, intTwo);
  digitThree = getIntegers(place, intThree);
  binaryOne = convertBinary(digitOne);
  binaryTwo = convertBinary(digitTwo);
  binaryThree = convertBinary(digitThree);
  splitBinary(&binaryOneD1, &binaryOneD2, &binaryOneD3, &binaryOneD4, binaryOne);
  splitBinary(&binaryTwoD1, &binaryTwoD2, &binaryTwoD3, &binaryTwoD4, binaryTwo);
  splitBinary(&binaryThreeD1, &binaryThreeD2, &binaryThreeD3, &binaryThreeD4, binaryThree);
  binaryValue1 = calcBinary(binaryOneD1, binaryOneD2, binaryOneD3, binaryOneD4, power);
  binaryValue2 = calcBinary(binaryTwoD1, binaryTwoD2, binaryTwoD3, binaryTwoD4, power - 4);
  binaryValue3 = calcBinary(binaryThreeD1, binaryThreeD2, binaryThreeD3, binaryThreeD4, power - 8);
  binaryValue = addBinary(binaryValue1, binaryValue2, binaryValue3);
  rand_num = genRandomNum(binaryValue);
  new_binary1 = calcSwitch(rand_num, binaryOneD1, binaryOneD2, binaryOneD3, binaryOneD4);
  new_binary2 = calcSwitch(rand_num, binaryTwoD1, binaryTwoD2, binaryTwoD3, binaryTwoD4);
  new_binary3 = calcSwitch(rand_num, binaryThreeD1, binaryThreeD2, binaryThreeD3, binaryThreeD4);

  displayOutput(binaryOne, binaryTwo, binaryThree, binaryValue, rand_num, new_binary1, new_binary2, new_binary3);

  return (0);
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getInput
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1 char* place // the desired place of each four-digit number
*       2.int* intOne // first four-digit number entered by user
*       3.int* intTwo // second four-digit number entered by user
*       4.int* intThree // third four-digit number entered by user
*
*     Function Description: This function prompts the user to enter 3 four-digit numbers and select the desired place of each digit inthe numbers entered
*
***************************************************************************/
void getInput(char* place, int* intOne, int* intTwo, int* intThree)
{
  // Statements
  printf("I - Ones place\n");
  printf("X - Tens place\n");
  printf("C - Hundreds place\n");
  printf("M - Thousands place\n");
  printf("Enter character for place selection: ");
  scanf("%c", place);
  printf("\nEnter 4-digit integer #1: ");
  scanf("%d", intOne);
  printf("Enter 4-digit integer #2: ");
  scanf("%d", intTwo);
  printf("Enter 4-digit integer #3: ");
  scanf("%d", intThree);
  
  return;
} // getInput

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getIntegers
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.char place // character that resembles the place of the digit (I,X,C,M)
*       2.int integer // each four-digit number the user entered
*       3.
*
*     Function Description: This funtion finds the digit in the place that the user specified
*
***************************************************************************/
int getIntegers(char place, int integer)
{
  // Local Declarations
  int placeNum; // identifier for digit in place user selected

  // Statements
  if (place == 'I')
  {
    placeNum = (integer % 1000);
    placeNum %= 100;
    placeNum %= 10;
  }
  else if (place == 'X')
  {
    placeNum = (integer % 1000);
    placeNum %= 100;
    placeNum /= 10;
  }
  else if (place == 'C')
  {
    placeNum = (integer % 1000);
    placeNum /= 100;
  }
  else
  {
    placeNum = integer / 1000;
  }

  return (placeNum);
} // getIntegers

/***************************************************************************
*
*     Function Information
*
*     Name of Function: convertBinary
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int digit // represents the three digits in the place the user selected
*       2.
*       3.
*
*     Function Description: This function assigns the binary equivalent to each digit in the place the user selected
*
***************************************************************************/
int convertBinary(int digit)
{
  // Local Declarations
  int binary; // binary representation of each digit

  // Statements
  if (digit == 0)
  {
    binary = 0;
  }
  else if (digit == 1)
  {
    binary = 1;
  }
  else if (digit == 2)
  {
    binary = 10;
  }
  else if (digit == 3)
  {
    binary = 11;
  }
  else if (digit == 4)
  {
    binary = 100;
  }
  else if (digit == 5)
  {
    binary = 101;
  }
  else if (digit == 6)
  {
    binary = 110;
  }
  else
  {
    binary = 111;
  }

  return (binary);
} // convertBinary

/***************************************************************************
*
*     Function Information
*
*     Name of Function: splitBinary
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int* binaryD1 // one or zero in the ones place of the binary number
*       2.int* binaryD2 // one or zero in the tens place of the binary number
*       3.int* binaryD3 // one or zero in the hundreds place of the binary number
*       4.int* binaryD4 // one or zero in the thousands place of the binary number
*       5.int binaryNumber // binary representation of the digit chosen by the user
*
*     Function Description: This function splits each binary number into ones and zeroes and stores them in four different variables 
*
***************************************************************************/
void splitBinary(int* binaryD1, int* binaryD2, int* binaryD3, int* binaryD4, int binaryNumber)
{
  // Statements
  *binaryD1 =  binaryNumber % 1000;
  *binaryD1 %= 100;
  *binaryD1 %= 10;
  *binaryD2 = binaryNumber % 1000;
  *binaryD2 %= 100;
  *binaryD2 /= 10;
  *binaryD3 = binaryNumber % 1000;
  *binaryD3 /= 100;
  *binaryD4 = binaryNumber / 1000;

  return;
} // splitBinary

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcBinary
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int digitOnes // ones place of binary number
*       2.int digitTens // tens place of binary number
*       3.int digitHundreds // hundreds place of binary number
*       4.int digitThousands // thousands place of binary number
*       5.int power // power associated with each place in the concatenated binary number
*
*     Function Description: This function calculates the decimal value of each of the binary representations of the digits the user picked
*
***************************************************************************/
int calcBinary(int digitOnes, int digitTens, int digitHundreds, int digitThousands, int power)
{
  // Local Declarations
  int binaryValue; // decimal value of the four digit binary number
  int value1; // result of taking 2 to the corresponding place value in the concatenated binary number
  int value2; // result of taking 2 to the corresponding place value in the concatenated binary number
  int value3; // result of taking 2 to the corresponding place value in the concatenated binary number
  int value4; // result of taking 2 to the corresponding place value in the concatenated binary number

  // Statements
  if (digitThousands == 1)
  {
  value1 = pow(2, power);
  }
  else
  {
  value1 = 0;
  }
  if (digitHundreds == 1)
  {
  value2 = pow(2, power - 1);
  }
  else
  {
  value2 = 0;
  }
  if (digitTens == 1)
  {
  value3 = pow(2, power - 2);
  }
  else
  {
  value3 = 0;
  }
  if (digitOnes == 1)
  {
  value4 = pow(2, power - 3);
  }
  else
  {
  value4 = 0;
  }

  binaryValue = value1 + value2 + value3 + value4;

  return (binaryValue);
} // calcBinary

/***************************************************************************
*
*     Function Information
*
*     Name of Function: addBinary
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int binaryValue1 // value of binary number in positions 11-8 of concatenated number
*       2.int binaryValue2 // value of binary number in postions 7-4 of concatenated number
*       3.int binaryValue3 // value of binary number in positions 3-0 of concatenated number
*
*     Function Description: This function adds the binary number in positions 11-8, 7-4, and 3-0 in the concatenated binary number to obtain the total decimal value
*
***************************************************************************/
int addBinary(int binaryValue1, int binaryValue2, int binaryValue3)
{
  // Local Declarations
  int binaryTotal; // sum of all three binary values to find concatenated decimal value
  
  // Statements
  binaryTotal = binaryValue1 + binaryValue2 + binaryValue3;

  return (binaryTotal);
} // addBinary

/***************************************************************************
*
*     Function Information
*
*     Name of Function: genRandomNum
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int binaryValue // decimal value of the first concatenated binary number  
*       2.
*       3.
*
*     Function Description: This function generates a random value from 1 to 15 using the decimal value of the previous
*     concatenated binary value as the seed.
*
***************************************************************************/
int genRandomNum(int binaryValue)
{
  // Local Declarations
  int rand_num; // random number from 1 to 15

  //Executable Statements
  srand(binaryValue);
  rand_num = (rand() % 15) + 1;

  return (rand_num);
} //genRandomNum

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcSwitch
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int rand_num // random number from 1 to 15
*       2.int binaryD1 // ones digit of the individual 4 digit binary number
*       3.int binaryD2 // tens digit of the individual 4 digit binary number
*       4.int binaryD3 // hundreds digit of the individual 4 digit binary number
*       5.int binaryD4 // thousands digit of the individual 4 digit binary number
*
*     Function Description: This function changes the previous three binary numbers into different binary numbers based on the 
*     random number generated
*
***************************************************************************/
int calcSwitch(int rand_num, int binaryD1, int binaryD2, int binaryD3, int binaryD4)
{
  // Local Declarations
  int new_binary; // new binary number after switching values of each digit of the previous binary number

  // Executable Statemets
  switch (rand_num)
  {
    case 1: binaryD1 = !binaryD1;
            break;
    case 2: binaryD2 = !binaryD2;
            break;
    case 3: binaryD3 = !binaryD3;
            break;
    case 4: binaryD4 = !binaryD4;
            break;
    case 5: binaryD1 = !binaryD1;
            binaryD2 = !binaryD2;
            break;
    case 6: binaryD1 = !binaryD1;
            binaryD3 = !binaryD3;
            break;
    case 7: binaryD1 = !binaryD1;
            binaryD4 = !binaryD4;
            break;
    case 8: binaryD2 = !binaryD2;
            binaryD3 = !binaryD3;
            break;
    case 9: binaryD2 = !binaryD2;
            binaryD4 = !binaryD4;
            break;
    case 10: binaryD4 = !binaryD4;
             binaryD3 = !binaryD3;
             break;
    case 11: binaryD2 = !binaryD2;
             binaryD3 = !binaryD3;
             binaryD1 = !binaryD1;
             break;
    case 12: binaryD2 = !binaryD2;
             binaryD4 = !binaryD4;
             binaryD1 = !binaryD1;
             break;
    case 13: binaryD1 = !binaryD1;
             binaryD4 = !binaryD4;
             binaryD3 = !binaryD3;
             break;
    case 14: binaryD2 = !binaryD2;
             binaryD4 = !binaryD4;
             binaryD3 = !binaryD3;
             break;
    case 15: binaryD4 = !binaryD4;
             binaryD2 = !binaryD2;
             binaryD3 = !binaryD3;
             binaryD1 = !binaryD1;
  }
  
  new_binary = binaryD1 + (10 * binaryD2) + (100 * binaryD3) + (1000 * binaryD4);

  return (new_binary);
} //calcSwtich

/***************************************************************************
*
*     Function Information
*
*     Name of Function: diplayOutput
*
*     Programmer's Name: David, Phillipine, Sydney
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int binaryOne // binary number positions 11-8 of concatenated number
*       2.int binaryTwo // binary number in positions 7-4 of concatenated number
*       3.int binaryThree // binary number in positions 3-0 in concatenated number
*       4.int binaryValue // decimal value of concatenated number
*
*     Function Description: This function displays the concatenated binary, its decimal value, the random number generated 
*     and the new concatenated binary number
*
***************************************************************************/
void displayOutput(int binaryOne, int binaryTwo, int binaryThree, int binaryValue, int rand_num, int new_binary1, int new_binary2, int new_binary3)
{
  // Statements
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Concatenated binary number: %04d%04d%04d\n", binaryOne, binaryTwo, binaryThree);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Conversion of concatenated binary: %2d\n", binaryValue);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Generated Number (1-15): %d\n", rand_num);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Concatenated binary number: %04d%04d%04d\n", new_binary1, new_binary2, new_binary3);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return;
} // displayOutput

