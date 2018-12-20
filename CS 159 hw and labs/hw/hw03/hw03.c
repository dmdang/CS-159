
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #: 03
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.

*  Lab Division and Section: Thursdays 11:30 - 1:20, SC 189, L08 
*
*  Program Description: This program calculates the probability of there being a number of defective microprocessors in a given sample size. the user will input the percentage of defective units produced, the number of units to sample, and the number of defective units in the sample. 
*
***************************************************************************/
#include <stdio.h>
#include <math.h>

// Function Declarations
void getInput (int* percentDefective, int* unitsSampled, int* defectiveInSample);
float convertPercent (int);
float calculateGFactorial (int);
int sampleMinusDefective (int, int);
float calculateProbability (int, int, float, float, float, float);
void displayOutput (int percentDefective, int unitsSampled, int defectiveInSample, float resultantProbability, float resultantProbabilityZeroD, int zeroDefects);  

int main (void)
{
  // Local Declarations
  int percentDefective; // percentage of defective units produced
  int zeroDefects = 0; // similar to number of defective units in the sample, except it's for the case where there are zero defects in the sample 
  int unitsSampled; // number of units to sample
  int defectiveInSample; // number of defective units in the sample
  float zeroFromG; // factorial result after inputting zeroDefects into the Gosper equation
  int resultSampleMinusDefective; // sample size minus number of defective units (for use in binomial distribution formula)
  float unitsSampledFactorial; // factorial result after  inputting number of units to sample into the Gosper equation
  float defectiveInSampleFactorial; // factorial result after inputting number of defective units in the sample into the Gosper eqution
  float sampleMinusDefectiveFactorial; // factorial result after inputting sample size minus number of defects into gosper equation (for binomial distribution)
  float resultantProbability; // calculated probability of getting a sample size with 'x' number of defects
  float resultantProbabilityZeroD; // calculated probability of getting a sample size with 0 defects
  float percentDefectiveDec; // decimal form of percentage of defective units produced
  int resultSampleMinusDefectiveZero; // sample size minus 0 number of defects (for binomial distribution)
  float sampleMinusDefectiveFactorialZero; // factorial result after inputting sample size minus 0 number of defects into gosper equation (for binomial distribution)

  // Statements
  getInput (&percentDefective, &unitsSampled, &defectiveInSample);
  resultSampleMinusDefective = sampleMinusDefective (unitsSampled, defectiveInSample);
  resultSampleMinusDefectiveZero = sampleMinusDefective (unitsSampled, zeroDefects);
  percentDefectiveDec = convertPercent (percentDefective);
  unitsSampledFactorial = calculateGFactorial (unitsSampled);
  defectiveInSampleFactorial = calculateGFactorial (defectiveInSample);
  sampleMinusDefectiveFactorial = calculateGFactorial (resultSampleMinusDefective);
  sampleMinusDefectiveFactorialZero = calculateGFactorial (resultSampleMinusDefectiveZero);
  zeroFromG = calculateGFactorial (zeroDefects);
  resultantProbability = calculateProbability (unitsSampled, defectiveInSample, percentDefectiveDec, sampleMinusDefectiveFactorial, defectiveInSampleFactorial, unitsSampledFactorial);
  resultantProbabilityZeroD = calculateProbability (unitsSampled, zeroDefects, percentDefectiveDec, sampleMinusDefectiveFactorialZero, zeroFromG, unitsSampledFactorial);
  displayOutput (percentDefective, unitsSampled, defectiveInSample, resultantProbability, resultantProbabilityZeroD, zeroDefects);

  return (0);
} // main

/***************************************************************************
*
*     Function Information
*
*     Name of Function: getInput
*
*     Programmer's Name: David Dang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int* percentDefective // percent of defective units given by user
*       2. int* unitsSampled // number of units sampled given by user
*       3. int* defectiveInSample // number of defects in sample given by user
*
*     Function Description: This function allows the user to input values for percentDefective, unitsSampled, and defectiveInSample through pass by address
*
***************************************************************************/
void getInput (int* percentDefective, int* unitsSampled, int* defectiveInSample)
{
  // Statements
  printf("Enter percentage of defective units produced: ");
  scanf("%d", percentDefective);
  printf("Enter number of units to sample: ");
  scanf("%d", unitsSampled);
  printf("Enter number of defective units in sample: ");
  scanf("%d", defectiveInSample);

  return;
} // getInput

/***************************************************************************
*
*     Function Information
*
*     Name of Function: sampleMinusDefective
*
*     Programmer's Name: David Dang
*
*     Function Return Type: int
*
*     Parameters (list data type, name, and comment one per line):
*       1. int Sample  // number of units sampled 
*       2. int Defective // number of defects in sample 
*       3.
*
*     Function Description: This function finds the difference between the sample size and the number of defects for later use in the binomial distribution formula
*
***************************************************************************/
int sampleMinusDefective (int Sample, int Defective)
{
  return (Sample - Defective);

} // sampleMinusDefective


/***************************************************************************
*
*     Function Information
*
*     Name of Function: convertPercent
*
*     Programmer's Name: David Dang
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. int percentage // percentage to be converted in decimal form
*       2.
*       3.
*
*     Function Description: This program converts the percent input into decimal form
*
***************************************************************************/
float convertPercent (int percentage)
{
  // Statements
  
  return ((float) percentage / 100);

} // convertPercent


/***************************************************************************
*
*     Function Information
*
*     Name of Function: calculateGFactorial
*
*     Programmer's Name: David Dang
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. int number // represents x in the Gosper equation
*       2. 
*       3. 
*
*     Function Description: This function calculates the factorial form of the sample size, number of defects, and the difference between the two
*
***************************************************************************/
float calculateGFactorial (int number)
{
  // Local Declarations
  float resultGFactorial; // factorial form of the input integer

  // Statements
  resultGFactorial = (pow(number, number) * (pow(M_E, -1 * number))) * sqrt(((2 * number) + ((float) 1 / 3)) * M_PI);

  return (resultGFactorial);

} // calculateGFactorial

/***************************************************************************
*
*     Function Information
*
*     Name of Function: calculateProbability
*
*     Programmer's Name: David Dang
*
*     Function Return Type: float
*
*     Parameters (list data type, name, and comment one per line):
*       1. int unitsSampled // number of units sampled given by user  
*       2. int defectiveInSample // number of defective units in sample given by user
*       3. float sampleMinusDefectiveFactorial // sample size minus defective units (factorial form)  
*       4. float defectiveInSampleFactorial // number of defects in sample (factorial form)
*       5. float unitsSampledFactorial // number of units sampled (factorial form)
*       6. int percentDefectiveDec // percentage of defective units in decimal form
*
*     Function Description: This function calculates the probability of selecting a given nuber of units with a specified number of defects in the sample
*
***************************************************************************/
float calculateProbability (int unitsSampled, int defectiveInSample, float percentDefectiveDec, float sampleMinusDefectiveFactorial, float defectiveInSampleFactorial, float unitsSampledFactorial)
{
  // Local Declarations
  float calculatedProbability; // probability calculated with binomial distribution
  float part1; // factorial quotient portion of the binomial distribution formula
  float part2; // decimal percentage to the power of defective units in the sample
  float part3; // (1 - decimal percentage) to the (sample size - number of defects in sample) power

  // Statements
  part1 = (unitsSampledFactorial) / (defectiveInSampleFactorial * sampleMinusDefectiveFactorial);
  part2 = pow(percentDefectiveDec, defectiveInSample);
  part3 = pow(1 - percentDefectiveDec, unitsSampled - defectiveInSample);
  calculatedProbability = part1 * part2 * part3;

  return (calculatedProbability);

} // calculatedProbability

/***************************************************************************
*
*     Function Information
*
*     Name of Function: displayOutput
*
*     Programmer's Name: David Dang
*
*     Function Return Type: void
*
*     Parameters (list data type, name, and comment one per line):
*       1. int percentDefective // percent of defective units given by user
*       2. int unitsSampled // sample size given by user
*       3. int defectiveInSample // number of defects in sample given by user
*       4. float resultantProbability // probability of selecting a given number of units with another number being defective
*       5. float resultantProbabilityZeroD // probability of selecting a given number of  units with 0 being defective 
*
*     Function Description: This program displays the percentage of defects and the probabilities of choosing sample sizes with varying numbers of defective units
*
***************************************************************************/
void displayOutput (int percentDefective, int unitsSampled, int defectiveInSample, float resultantProbability, float resultantProbabilityZeroD, int zeroDefects)
{
  // Statements
  printf("\nAverage number of defective units produced: %d%%", percentDefective);
  printf("\nSelecting %d units with %d being defective has a probability of: %.4f", unitsSampled, defectiveInSample, resultantProbability);
  printf("\nSelecting %d units with %d being defective has a probability of: %.4f\n", unitsSampled, zeroDefects, resultantProbabilityZeroD);

  return;
} // displayOutput


