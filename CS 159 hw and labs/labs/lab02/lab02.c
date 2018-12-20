
/***************************************************************************
*
*  Programmers and Purdue Email Addresses:
*	 1. dangd@purdue.edu
*	 2  agranito@purdue.edu
*	 3. eshelto@purdue.edu
*
*  Lab #:2
*
*  Academic Integrity Statement:
*
*       We have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have we provided access 
*       to our code to another. The project we are submitting
*       is our own original work.
*
*  Lab Division and Section:L08 11:30 - 2:20, Thursday, SC 189
*
*  Program Description: This program calculates the area of circles, common area between the circles, and percent overlap of two circles when given radius and
*  distance between centers.
*
***************************************************************************/
#include <stdio.h>
#include <math.h>


int main (void) 
{  
  // Local Declarations
  double radius; // radius of circles  
  double xDistance; // distance between centers of circles on x axis
  double areaC; // area of one circle
  double areaO; // area of overlap between circles
  double areaPercentage; // percentage of overlap
  int precision; // determine precision of decimal place for outputs

  // Statements
  printf("Enter  radius of circles: "); 
  scanf("%lf", &radius);
  printf("Enter distance between centers of circles: ");
  scanf("%lf", &xDistance);

  areaO = 2 * radius * radius * acos(xDistance / (2 * radius)) - .5 * xDistance * sqrt( 4 * radius * radius - xDistance * xDistance);
  // calculate area of overlap
  areaC = radius * radius * M_PI; // calculate area of a circle
  areaPercentage =  (areaO / areaC) * 100; // calculate percentage of overlap
  precision = (int)(areaPercentage * 10) % 10; // use 10ths place as precision for outputs

  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  printf("Area of circles: %16.*lf", precision, areaC);
  printf("\nCommon Area is: %17.*lf", precision, areaO);
  printf("\nPercent Overlap: %16.*lf", precision, areaPercentage); 
  printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

  return(0);
} // main
