
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. dangd@purdue.edu
*	 2. agranito@purdue.edu
*	 3. eshelto@purdue.edu 
*
*  Lab #: 4 
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section: Thursday 11:30 - 1:20, SC 189, L08
*
*  Program Description: This program helps the user find the total number of ways to organize a team of  engineers and managers. First, the user enters the number of engineers, managers, and employees on the team. After that, the number of ways of getting a team of approximately half engineers and half managers is given by the Gosper and Stirling equations.  
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

// Function Declarations
   int getTeamManagers (int numEmployees); 
   int getTeamEngineers (int numEmployees, int TeamManagers);
   int getNumMinusTeam (int, int);
   float getSFactorial (int);
   float getGFactorial (int);
   float getPossibleCombos (float, float, float, float, float, float);

int main (void)
{
  // Local Declarations
  int numEngineers; // total number of engineers specified by user
  int numManagers; // total number of managers specified by user
  int numEmployees; // total number of employees specified by user
  int TeamManagers; // number of managers on a team
  int TeamEngineers; // number of engineers on a team
  int numMinusTeamEng; // total # of engineers minus # of engineers allowed on a team
  int numMinusTeamMang; // total # of managers minus # of managers allowed on a team
  float numManagersStirling; // total # of managers used in Stirling equation
  float numEngineersStirling; // total # of engineers used in Stirling equation
  float ManagersStirling; // number of managers on a team used in Stirling equation
  float EngineersStirling; // number of engineers on a team used in Stirling equation
  float numMinusTeamEngStirling; // total # of engineers minus # of engineers allowed on a team used in Stirling equation
  float numMinusTeamMangStirling; // total # of managers minus # of managers allowed on a team used in Stirling equation
  float numManagersGosper; // total # of managers used in Gosper equation
  float numEngineersGosper; // total # of engineers used in Gosper equation
  float ManagersGosper; // number of managers on team used in Gosper equation
  float EngineersGosper; // number of engineers on team used in Gosper equation
  float numMinusTeamEngGosper; //  total # of engineers minus # of engineers allowed on a team used in Gosper equation
  float numMinusTeamMangGosper; // total # of managers minus # of managers allowed on a team used in Gosper equation
  float PossibleCombosS; // number of possible combinations using the Stirling equation
  float PossibleCombosG; // number of possible combinations using the Gosper equation

  // Statements
  printf("Enter number of engineers on team: ");
  scanf("%d", &numEngineers);
  printf("Enter number of managers on team: ");
  scanf("%d", &numManagers);
  printf("Enter number of employees on team: ");
  scanf("%d", &numEmployees);

  TeamManagers = getTeamManagers (numEmployees);
  TeamEngineers = getTeamEngineers (numEmployees, TeamManagers);
  numMinusTeamEng = getNumMinusTeam (numEngineers, TeamEngineers);
  numMinusTeamMang = getNumMinusTeam (numManagers, TeamManagers);
  numManagersStirling = getSFactorial (numManagers);
  numEngineersStirling = getSFactorial (numEngineers);
  ManagersStirling = getSFactorial (TeamManagers);
  EngineersStirling = getSFactorial (TeamEngineers);
  numMinusTeamEngStirling = getSFactorial (numMinusTeamEng);
  numMinusTeamMangStirling = getSFactorial (numMinusTeamMang);
  numManagersGosper = getGFactorial (numManagers);
  numEngineersGosper = getGFactorial (numEngineers);
  ManagersGosper = getGFactorial (TeamManagers);
  EngineersGosper = getGFactorial (TeamEngineers);
  numMinusTeamEngGosper = getGFactorial (numMinusTeamEng);
  numMinusTeamMangGosper = getGFactorial (numMinusTeamMang);
  PossibleCombosS = getPossibleCombos (numEngineersStirling, numManagersStirling, EngineersStirling, ManagersStirling, numMinusTeamEngStirling, numMinusTeamMangStirling);
  PossibleCombosG = getPossibleCombos (numEngineersGosper, numManagersGosper, EngineersGosper, ManagersGosper, numMinusTeamEngGosper, numMinusTeamMangGosper);

  // Output
  printf("\nSelecting Engineers (%d of %d) and Managers (%d of %d).\n", TeamEngineers, numEngineers, TeamManagers, numManagers);
  printf("Possible combinations using Stirling: %.1f\n", PossibleCombosS);
  printf("Possible combinations using Gosper: %.1f\n", PossibleCombosG);
  
  return (0);
} // main


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getTeamManagers
*
*     Programmer's Name:David, Alyssa, Erin
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int numEmployees // number of employees input by user
*       2.
*       3.
*
*     Function Description: finds number of managers given number of employees on team
*
***************************************************************************/
int getTeamManagers (int numEmployees)
{
  // Statements
  return (numEmployees / 2);
} // getTeamManagers


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getTeamEngineers
*
*     Programmer's Name: David, Alyssa, Erin
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1.int numEmployees // number of employees input by user
*       2.int TeamManagers // number of managers on a team
*       3.
*
*     Function Description: finds number of enginers given number of team managers and number of employees
*
***************************************************************************/
int getTeamEngineers (int numEmployees, int TeamManagers)
{
  // Statements
  return (numEmployees - TeamManagers);
} // getTeamEngineers


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getNumMinusTeam
*
*     Programmer's Name: David, Alyssa, Erin
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int numProfession // number of Engineers/Managers specified by user
*       2. int TeamProfession // number of Engineers/Managers to be placed on a team
*       3.  
*
*     Function Description: finds difference between number of Engineers/managers specified by the user and the number of Engineers/managers on a team. This will be used in the function to calculate the total number of combinations
***************************************************************************/
int getNumMinusTeam(int numProfession, int TeamProfession)
{
  // Local Declarations
  int numMinusTeam; // number of Engineers/Managers specified minus number of Engineers/Managers on a team

  // Statements
  numMinusTeam = numProfession - TeamProfession;

  return (numMinusTeam);
} // getNumMinusTeam


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getSFactorial
*
*     Programmer's Name: David, Alyssa, Erin
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. int number // acts as the 'x' in the stirling equation
*       2.
*       3.
*
*     Function Description: finds Stirling approximation for team combinations
*
***************************************************************************/
float getSFactorial (int number)
{
  // Local Declarations
  float SFactorial; // Stirling factorial

  // Statements
  SFactorial = (pow(number, number) * (pow(M_E, -1 * number))) * sqrt(2 * M_PI * number);

  return (SFactorial);
} // getSFactorial


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getGFactorial
*
*     Programmer's Name: David, Alyssa, Erin
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. int number // acts as the 'x' in the gosper equation
*       2.
*       3.
*
*     Function Description: finds Gosper approximation for team combinations
*
***************************************************************************/
float getGFactorial (int number)
{
  // Local Declarations
  float GFactorial; // Gosper factorial

  // Statements
  GFactorial = (pow(number, number) * (pow(M_E, -1 * number))) * sqrt(((2 * number) + ((float) 1 / 3)) * M_PI);

  return (GFactorial);
} // getGFactorial


/***************************************************************************
*
*     Function Information
*
*     Name of Function: getPossibleCombos
*
*     Programmer's Name: David, Alyssa, Erin
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. float numEngineersFactorial // factorial of the number of  engineers input by user (calculated with either Gosper or Stirling)
*       2. float numManagersFactorial // factorial of the number of managers input by user (calculatd with Gosper or Stirling) 
*       3. float EngineersFactorial // factorial of the number of engineers on a team (calculated with Gosper or Stirling)
*       4. float ManagersFactorial // factorial of the number of managers on a team (calculated with Gosper or Stirling)
*       5. float numMinusTeamEng // factorial of number of engineers input by user minus engineers on a team (Gosper/Stirling)
*       6. float numMinusTeamMang // factorial of number of managers input by user minus managers on a team (Gosper/Stirling)
*
*     Function Description: finds total number of possible combinations where the team can be made of approximately half engineers and half managers
*
***************************************************************************/
float getPossibleCombos (float numEngineersFactorial, float numManagersFactorial, float EngineersFactorial, float ManagersFactorial, float numMinusTeamEng, float numMinusTeamMang)
{
  // Local Declarations
  float PossibleCombos; // Possible Combinations

  // Statements
  PossibleCombos = ((numEngineersFactorial) / (EngineersFactorial * (numMinusTeamEng))) * ((numManagersFactorial) / (ManagersFactorial * (numMinusTeamMang)));

  return (PossibleCombos);
} // getPossibleCombos


