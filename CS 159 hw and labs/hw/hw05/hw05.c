/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 5
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
*  Program Description: This program allows the user to input an octal number and a key digit. the octal number is encrypted using
the key digit and the encryption is then displayed
*
***************************************************************************/
#include<stdio.h>
#include<math.h>

// Function Declarations
void getInput(int* octalNum, int* keyDigit);
void displayError(void);
int calcEncryptedVal(int octalNum, int keyDigit, int lengthNum);
int findLength(int octalNum);
void displayOutput(int encryptedVal, int lengthNum);

int main (void)
{
  // Local Declarations
  int octalNum; // octal number entered by user
  int keyDigit; // key digit entered by user
  int encryptedVal; // encrypted value to be output
  int lengthNum; // length of octal number

  // Statements
  getInput(&octalNum, &keyDigit);
  lengthNum = findLength(octalNum);
  encryptedVal = calcEncryptedVal(octalNum, keyDigit, lengthNum);
  displayOutput(encryptedVal, lengthNum);

  return (0);
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getInput
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* octalNum // octal number to be input by user
*       2. int* keyDigit // key digit to be input by user
*       3.
*
*     Function Description: This function first tests if the octal number is negative. if it is, the user is prompted 
to input a non-negative number. When the user enters a non-negative number, each digit in the octal number is analyzed 
to see if it is greater than 7. if a digit is greater than 7, the variable conditionTest is set to 1 and the user must
input a new octal number with digits less than 7. when this has been satisfied, the user is prompted to enter the octal key
digit. the octal key digit must be greater than zero and be less than 7 as well. 
*
***************************************************************************/
void getInput(int* octalNum, int* keyDigit)
{
  // Local Declarations
  int conditionTest; // tests to see if the code determined the octal number to be invalid
  int max = 7; // each octal digit cannot be greater than the maximum value of 7
  
  // Statements
  do
  {
  printf("Enter octal number: ");
  scanf("%d", octalNum);

  // Input Validation
  if (*octalNum > 0)
  {
	  
    while (*octalNum > 0)
    {
	  
      if (*octalNum % 10 > max)
      {
        conditionTest = 1;
      }
  
      else
      {
        do
        {
          printf("Enter octal key digit: ");
          scanf("%d", keyDigit);

          if ((*keyDigit < 0) || (*keyDigit > 7))
          {
            printf("\nError! invalid octal digit value!!\n\n");
          }

        }while((*keyDigit < 0) || (*keyDigit > 7));

        return;
       }
  
     *octalNum /= 10;
     }
	  
  if (conditionTest == 1)
  {
    displayError();  
  }
  }

  else
  {
    printf("\nError! Negative numbers are invalid!!\n\n");
  }

  }while((*octalNum < 0) || (conditionTest == 1));
} // getInput

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayError
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. void // this program has no parameters
*       2.
*       3.
*
*     Function Description: This function is called by the getInput function if the user input an octal number
with digits greater than 7
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
*     Name of Function: findLength
*
*     Programmer's Name: David
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int octalNum // the octal number the user entered
*       2.
*       3.
*
*     Function Description: This function finds the length of the octal number the user entered
*
***************************************************************************/
int findLength(int octalNum)
{
  // Local Declarations
  int lengthNum = 0; // number of digits in octal number
	
  // Statements
  while (octalNum != 0)
  {
    lengthNum++;
    octalNum /= 10;
  }

  return (lengthNum);
} // findLength

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcEncryptedVal
*
*     Programmer's Name: David
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int octalNum // the octal number the user entered
*       2. int keyDigit // the key digit the user entered
*       3. int lengthNum // length of the octal number
*
*     Function Description: This function uses a 'for' loop to obtain the left most digit of the octal number. after
the left most digit is known, the key digit is added to the left most digit and is stored in 'newDigit'. if 'newDigit' is 
greater than 7, it will wrap around to 0 and then the encrypted number will be updated with the new digit appended to the end.
The key digit is then assigned the value of 'newDigit' after each pass.
*
***************************************************************************/
int calcEncryptedVal(int octalNum, int keyDigit, int lengthNum)
{
  // Local Declarations
  int testCondition; // loop control variable for the 'for' loop
  int newDigit; // result of adding the key digit to the left most octal digit
  int octalLeftDigit; // left most digit of the octal number the user entered
  int encryptedVal = 0; // the octal number in the encrypted form

  // Statements
  for (testCondition = 1; testCondition <= lengthNum; testCondition++)
  {
		
    if (lengthNum - (lengthNum - testCondition) == 1)
    {
      octalLeftDigit = octalNum / (pow(10, (lengthNum - testCondition)));
    }
    else
    {
      octalLeftDigit = ((int)(octalNum / (pow(10, (lengthNum - testCondition))))) % 10;
    } 

    newDigit = keyDigit + octalLeftDigit;
		
    if (newDigit > 7)
    {
      newDigit = newDigit % 8;
      encryptedVal = (encryptedVal * 10) + newDigit;
      keyDigit = newDigit;
    }
    else
    {
      encryptedVal = (encryptedVal * 10) + newDigit;
      keyDigit = newDigit;
    }
  
  }

  return (encryptedVal);
} // calcEncryptedVal

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
*       1. int encryptedVal // encrypted form of the octal number
*       2. int lengthNum // length of the octal number
*       3.
*
*     Function Description: This function displays the encrypted octal number
*
***************************************************************************/
void displayOutput(int encryptedVal, int lengthNum)
{
  // Local Declarations
  int testCondition; // loop control variable for the 'for' loop
  int stringLength; // length of the octal number plus the length of the string 'Encrypted value: ' 
	
  // Statements
  stringLength = 17 + lengthNum;
	
  printf("\n");
  
  for (testCondition = 0; testCondition < stringLength; testCondition++)
  {
    printf("%c", '-');
  }

  printf("\nEncrypted value: %0*d\n", lengthNum, encryptedVal);
  
  for (testCondition = 0; testCondition < stringLength; testCondition++)
  {
    printf("%c", '-');
  }
  
  printf("\n");
  
  return;
} // displayOutput





