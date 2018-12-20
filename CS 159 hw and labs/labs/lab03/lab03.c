
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. dangd@purdue.edu
*	 2. agranito@purdue.edu
*	 3. eshelto@purdue.edu (delete line if no third partner)
*
*  Lab #: 3
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
*  Program Description: The purpose of this program is to calculate the Nitrogen Oxide and Carbon Monoxide emissions for a vehicle. The user will be asked which emission they want to calculate and they will then enter the number of miles the vehicle has travelled. The total emissions will be displayed in grams.  
*
***************************************************************************/

#include <stdio.h>
#define FIRSTMAX 50000
#define SECONDMAX 100000

int main (void)
{
  // Local Declarations
  int Pollutant; // pollutant (Nitrogen Oxide or Carbon Monoxide)
  float Mileage; // # miles vehicle has travelled
  int FirstTest; // checks if mileage is <= 50000 miles
  int SecondTest; // checks if mileage is above 100000 miles
  int MiddleRange; // checks if mileage is between 50001 and 100000 miles
  float Emissions1range1; // emissions for first 50000 miles (Carbon Monoxide)
  float Emissions1range2; // emissions for 50001 to 100000 miles (Carbon Monoxide)
  float Emissions1range3; // emissions above 100000 miles (Carbon Monoxide)
  float Emissions2range1; // emissions for first 50000 miles (Nitrogen Oxide)
  float Emissions2range2; // emissions for 50001 to 100000 miles (Nitrogen Oxide)
  float Emissions2range3; // emissions above 100000 miles (Nitrogen Oxide)
  float Emissions; // total emissions for all three ranges of either pollutant

  // Statements
  printf("Select (1) Carbon Monoxide or (2) Nitrogen Oxides: ");
  scanf("%d", &Pollutant);
  printf("Enter current mileage: ");
  scanf("%f", &Mileage);
  FirstTest = Mileage / FIRSTMAX; // outputs 1 or 0 to determine if mileage is <= 50000 miles
  SecondTest = Mileage / SECONDMAX; // outputs 1 or 0 to determin if mileage is greater than 100000 miles
  MiddleRange = FIRSTMAX * SecondTest + ((int) Mileage % FIRSTMAX) * (1 - SecondTest); // outputs 1 or 0 to determine if mileage is between 50000 and 100000 miles

  // Calculations
  Emissions1range1 = ((1 / Pollutant) * ((Mileage - ((FirstTest + 2) % (FirstTest + 1)) * ((int) MiddleRange % FIRSTMAX) - ((int) Mileage % SECONDMAX) * SecondTest)) * 3.4); // calculates emissions <= 50000 miles for Carbon Monoxide
  Emissions1range2 = ((1 / Pollutant) * (MiddleRange * FirstTest * 4.2)); // calculates emissions between 50001 and 100000 miles for Carbon Monoxide
  Emissions1range3 = ((1 / Pollutant) * ((int) Mileage % SECONDMAX) * SecondTest * 5); // calculates emissions above 100000 miles for Carbon Monoxide

  Emissions2range1 = ((Pollutant / 2) * (Mileage - ((FirstTest + 2) % (FirstTest + 1)) * ((int) MiddleRange % FIRSTMAX) - ((int) Mileage % SECONDMAX) * SecondTest)) * 0.5; // calculates emissions <= 50000 miles for Nitrogen Oxide
  Emissions2range2 = ((Pollutant / 2) * (MiddleRange * FirstTest * 0.6)); // caluclates emissions between 50001 and 100000 miles for Nitrogen Oxide
  Emissions2range3 = ((Pollutant / 2) * ((int) Mileage % SECONDMAX) * SecondTest * 0.7); // calculates emissions above 100000 miles for Nitrogen Oxide
  Emissions = Emissions1range1 + Emissions1range2 + Emissions1range3 + Emissions2range1 + Emissions2range2 + Emissions2range3; // adds all of the ranges for both pollutants to find total emissions
 
  // Output
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Total emissions: %-16.1f grams\n", Emissions);
  printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return (0);
} // main
