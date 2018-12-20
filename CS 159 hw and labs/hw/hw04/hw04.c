/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 4
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
*  Program Description: given the year and the number of days from last December 
*  to the start of the semester, this program will find the calendar dates
*  of the semester start, October break, and Thanksgiving Break.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

// Function Declarations
void getInput(int* year, int* beginFallSem);
int calcStartDay(int year);
int determineMonday(int year, int beginFallSem, int startDay);
int calcCalendarDay(int year, int beginFallSem, int determiningFactor, int* wrongDay);
void calcOctoberBreak(int beginFallSem, int* dayOfOctoberMon, int* dayOfOctoberTues, int year);
void calcThanksgiving(int beginFallSem, int* dayOfThanksDay1, int* dayOfThanksDay2, int startDay, int year);
void displayOutput(int year, int dayOfDate, int dayOfOctoberMon, int dayOfOctoberTues, int dayOfThanksDay1, int dayOfThanksDay2, int determiningFactor, int wrongDay);

int main (void)
{
  // Local Declarations
  int year; // year specified by user
  int beginFallSem; // day on which fall semester begins in the given year given by user
  int dayOfDate; // the day portion of the semester start date
  int startDay; // the day of the week of December 31 of the previous year
  int determiningFactor; // variable to determine if the day number input by the user is a Monday
  int dayOfOctoberMon; // first day of October Break
  int dayOfOctoberTues; // second day of October Break
  int dayOfThanksDay1; // first day of Thanksgiving Break
  int dayOfThanksDay2; // last day of Thanksgiving Break
  int wrongDay; // used when the user entered a day number which did not fall on a monday

  // Statements
  getInput(&year, &beginFallSem);
  startDay = calcStartDay(year);
  determiningFactor = determineMonday(year, beginFallSem, startDay);
  dayOfDate = calcCalendarDay(year, beginFallSem, determiningFactor, &wrongDay);
  calcOctoberBreak(beginFallSem, &dayOfOctoberMon, &dayOfOctoberTues, year);
  calcThanksgiving(beginFallSem, &dayOfThanksDay1, &dayOfThanksDay2, startDay, year);
  displayOutput(year, dayOfDate, dayOfOctoberMon, dayOfOctoberTues, dayOfThanksDay1, dayOfThanksDay2, determiningFactor, wrongDay);

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
*       1.int* year // calendar year specified by user
*       2.int* beginFallSem // day on which semester shall begin given by user
*       3.
*
*     Function Description: This function allows the user to input the year and the number of days 
*     from December of last year that the semester will begin
*
***************************************************************************/
void getInput(int* year, int* beginFallSem)
{
  // Statements
  printf("Enter the year: ");
  scanf("%d", year);
  printf("Enter the day number on which the fall semester begins: ");
  scanf("%d", beginFallSem);

  return;
} // getInput

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcStartDay
*
*     Programmer's Name: David
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year // year specified by user
*       2.
*       3.
*
*     Function Description: This function calculates the day of the week that December 31 of last year fell on
*     (0-sun, 1-mon, 2-tues, 3-wed, 4-thurs, 5-fri, 6-sat)
*
***************************************************************************/
int calcStartDay(int year)
{
  // Local Declarations
  int startDay; // variable made to hold day of the week of December 31 of previous year

  // Statements
  startDay = ((year - 1) * 365 + ((year - 1) / 4) - ((year - 1) / 100) + ((year - 1) / 400)) % 7;

  return (startDay);
} // calcStartDay

/***************************************************************************
*
*     Function Information
*
*     Name of Function: determineMonday
*
*     Programmer's Name: David
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year // year specified by user
*       2.int beginFallSem // day on which semester begins given by user
*       3.int startDay // day of the week on which Dec. 31 of last year fell on 
*
*     Function Description: This function calculates the day of the week for the day number that
*     the user input
*
***************************************************************************/
int determineMonday(int year, int beginFallSem, int startDay)
{
  // Local Declarations
  int determinant; // variable that holds the result of whether or not the user entered a number day that fell on monday

  // Statements
  determinant = (startDay + beginFallSem) % 7; 

  return (determinant);
} // determineMonday

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcCalendarDay
*
*     Programmer's Name: David
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int year // year given by user
*       2.int beginFallSem // day on which semester begins given by user 
*       3.int determiningFactor // variable that holds result of determining if the number day the user entered fell on monday 
*       4.int* wrongDay // variable that holds the day portion of the calendar date if 
*       the day on which the semester begins does not fall on monday
*
*     Function Description: This function calculates the calendar day that the semester will start on. if the day 
*     that the user entered does not fall on a monday, it will be assigned to the variable wrongDay. if the year happens to
*     be a leap year, it skips the first if statement and goes directly to the else statement.
*
***************************************************************************/
int calcCalendarDay(int year, int beginFallSem, int determiningFactor, int* wrongDay)
{
  // Local Declarations
  int semesterStart; // calendar day that the semester begins

  // Statements
  if ((year % 4) != 0)
  {
      if (determiningFactor == 1)
      {
         semesterStart = beginFallSem - 212;
      }
      else
      {
          *wrongDay = beginFallSem - 212;
      }
  }
  else
  {
      if (determiningFactor == 1)
      {
          semesterStart = beginFallSem - 213;
      }
      else
      {
          *wrongDay = beginFallSem - 213;
      }
  }
  return (semesterStart);
} // calcCalendarDay

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcOctoberBreak
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int beginFallSem // day on which semester begins given by user
*       2.int* dayOfOctoberMon // first day of October Break
*       3.int* dayOfOctoberTues // second day of October Break
*       4.int year // year that user entered
*
*     Function Description: This function decides if the year the user entered is a leap year and 
*     calculates the calendar days of the monday and tuesday of October break
***************************************************************************/
void calcOctoberBreak(int beginFallSem, int* dayOfOctoberMon, int* dayOfOctoberTues, int year)
{
  // Local Declarations
  int daysFromDecToMon; // days from December 31 of last year to monday of Oct. break
  int daysFromDecToTues; // days from December 31 of last year to tueday of Oct. break
 
 // Statements
   if ((year % 4) != 0)
   {
   daysFromDecToMon = beginFallSem + 49;
   daysFromDecToTues = beginFallSem + 50;
   *dayOfOctoberMon = daysFromDecToMon - 273;
   *dayOfOctoberTues = daysFromDecToTues - 273;
   }
   else
   {
   daysFromDecToMon = beginFallSem + 49;
   daysFromDecToTues = beginFallSem + 50;
   *dayOfOctoberMon = daysFromDecToMon - 274;
   *dayOfOctoberTues = daysFromDecToTues - 274;
   }

   return;
} // calcOctoberBreak

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calcThanksgiving
*
*     Programmer's Name: David
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1.int beginFallSem // day on which semester begins given by user
*       2.int* dayOfThanksDay1 // first day of thanksgiving break
*       3.int* dayOfThanksDay2 // last day of thanksgiving break
*       4.int startDay // day of the week that December 31 of last year fell on
*       5.int year // year given by user
*
*     Function Description: This function decides if the day is a leap year and if December 31 of last year fell on the weekend.
*     it then calculates the first and last days of Thanksgiving break
*
***************************************************************************/
void calcThanksgiving(int beginFallSem, int* dayOfThanksDay1, int* dayOfThanksDay2, int startDay, int year)
{
    // Local Declarations
    int daysFromDecToDay1; // number of days from december 31 of last year to the first day of thanksgiving break
    int daysFromDecToDay2; // number of days from december 31 of last year to the last day of thanksgiving break

    // Statements
    if (((year % 4) != 0) && (startDay == 0 || startDay == 6))
    {
    daysFromDecToDay1 = beginFallSem + 92;
    daysFromDecToDay2 = beginFallSem + 94;
    *dayOfThanksDay1 = daysFromDecToDay1 - 303;
    *dayOfThanksDay2 = daysFromDecToDay2 - 303;
    }
    else if (((year % 4) != 0) && (startDay != 0 || startDay != 6))
    {
     daysFromDecToDay1 = beginFallSem + 100;
     daysFromDecToDay2 = beginFallSem + 102;
     *dayOfThanksDay1 = daysFromDecToDay1 - 304;
     *dayOfThanksDay2 = daysFromDecToDay2 - 304;
    }
    else
    {
     daysFromDecToDay1 = beginFallSem + 92;
     daysFromDecToDay2 = beginFallSem + 94;
     *dayOfThanksDay1 = daysFromDecToDay1 - 304;
     *dayOfThanksDay2 = daysFromDecToDay2 - 304;
    }

    return;
} // calcThanksgiving

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
*       1.int year // year specified by user
*       2.int dayOfDate // calendar day on which semester begins
*       3.int dayOfOctoberMon // calendar day of the monday of october break
*       4.int dayOfOctoberTues // calendar day of the tuesday of october break
*       5.int dayOfThanksDay1 // calendar day of the first day of thanksgiving break
*       6.int dayOfThanksDay2 // calendar day of the last day of thanksgiving break
*       7.int determiningFactor // variable that holds result of determining if the number day the user entered fell on monday
*       8.int wrongDay //  variable that holds the day portion of the calendar date if
*       the day on which the semester begins does not fall on monday
*
*
*     Function Description: This function displays the calendar start day of the semester, the dates of october break, and the dates of thanksgiving break for the academic year. if the day number the user entered did not fall on monday, the program will alert them that their input did not fall on monday
*
***************************************************************************/
void displayOutput(int year, int dayOfDate, int dayOfOctoberMon, int dayOfOctoberTues, int dayOfThanksDay1, int dayOfThanksDay2, int determiningFactor, int wrongDay)
{
  // Statements
  if (determiningFactor == 1)
  {
  printf("\nSemester start date: 08/%d/%4d", dayOfDate, year);
  printf("\nOctober Break %4d: 10/%02d - 10/%02d", year, dayOfOctoberMon, dayOfOctoberTues);
  printf("\nThanksgiving Break %4d: 11/%02d - 11/%02d\n", year, dayOfThanksDay1, dayOfThanksDay2);
  }
  else
  {
   printf("\nThe date: 08/%d/%4d does not fall on a Monday.\n", wrongDay, year);
  }
  return;
} // displayOutput

