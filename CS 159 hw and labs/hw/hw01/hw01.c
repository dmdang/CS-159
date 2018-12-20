
/***************************************************************************
*
*  Programmer and Purdue Email Address:
*  1. dangd@purdue.edu
*
*  Homework #:01
*
*  Academic Integrity Statement:
*
*       I have not used source code obtained from
*       any other unauthorized source, either modified
*       or unmodified.  Neither have I provided access
*       to my code to another. The project I am submitting
*       is my own original work.
*
*  Lab Division and Section: Thursday, 11:30 - 1:20, SC 189
*
*  Program Description: The purpose of this program is to find the volume and surface area of a half cylinder (that is, a cylinder cut in half lengthwise) for values of the radius (rad) and the length (height) specified by the user.  
*
***************************************************************************/

#include <stdio.h>
#define PI 3.1416 // set variable PI equal to 3.1416

int main()
{
  // Local Declarations
     float rad; // declare radius as rad
     float height; // declare height as height
     float vol; // declare volume as vol
     float surf; // declare surface area as surf
     
  // Statements
     printf("Please enter the value of the radius: ");
     scanf("%f", &rad);
     printf("Please enter the value of the length: ");
     scanf("%f", &height);

  // Calculations
     vol = 0.5 * (PI * rad * rad * height); // calculate volume as a function of radius and height
     surf = (PI * rad * rad) + (2 * rad * height) + (PI * rad * height); // calculate surface area as a function of radius and height

  // Output
     printf("\n-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
     printf("Surface Area: %19.2f\n", surf);
     printf("Volume: %25.2f\n", vol);
     printf("-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
  
  return 0;
} // main
