/********************************************************************
*  Header file to hold all the function prototypes and definitions
*
*  Assignment: Unit 1
*  Title:      Physics Calculator
*  Student:    Michael Nguyen
*  Teacher:    Tyson McMillan
*  Date:       03/25/2022
*********************************************************************/
#ifndef FUNCTIONS_H
#define FUNCTIONS_H

#include<iostream>
#include<string>
#include"Input_Validation_Extended.h"

/********************************************************************
*                      FUNCTION PROTOTYPES
*********************************************************************/

void displayMenu();


/********************************************************************
*                      FUNCTION DEFINITIONS
*********************************************************************/

//This function displays the menu on screen for user
void displayMenu()
{
  cout << "Please select one of the following calculations to perform by entering one of the alphabetical letter that precedes it: "<< endl << endl;
  cout << "(A) Velocity" << endl;
  cout << "(B) Acceleration" << endl;
  cout << "(C) Motion" << endl;
  cout << "(D) Force - Newton's Second Law" << endl;
  cout << "(E) Weight (planet Earth)" << endl;
  cout << "(F) Momentum" << endl;
}

#endif