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
void displayMotionSubMenu();

/********************************************************************
*                      FUNCTION DEFINITIONS
*********************************************************************/

//This function displays the menu on screen for user
void displayMenu()
{
  cout << "------------------------------------------------" << endl;
  cout << "|              Physics Calculator              |" << endl;
  cout << "|                  Main Menu                   |" << endl;
  cout << "------------------------------------------------" << endl;
  cout << "Please select one of the following calculations to perform by entering one of the alphabetical letter that precedes it: "<< endl << endl;
  cout << "(A) Velocity" << endl;
  cout << "(B) Acceleration" << endl;
  cout << "(C) Motion" << endl;
  cout << "(D) Force - Newton's Second Law" << endl;
  cout << "(E) Weight (planet Earth)" << endl;
  cout << "(F) Momentum" << endl << endl;
}

//This function displays the sub menu for the 4 equations of motion 
// if the user selects "(C) Motion" from the main menu
void displayMotionSubMenu()
{
  cout << "Please select one of the equations of motion to calculate by entering the number that precedes it: " << endl << endl;
  cout << "(1) First Equation of Motion: Solve for Velocity" << endl;
  cout << "(2) Second Equation of Motion: Solve for Position" << endl;
  cout << "(3) Third Equation of Motion: Solve for Velocity Squared" << endl;
  cout << "(4) Fourth Equation of Motion: Solve for Average Velocity" << endl << endl;
}
#endif