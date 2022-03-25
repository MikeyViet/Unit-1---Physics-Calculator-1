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
#include<iomanip>
#include"Input_Validation_Extended.h"

/********************************************************************
*                      FUNCTION PROTOTYPES
*********************************************************************/

void displayMenu();
void displayMotionSubMenu();
void processMainMenuSelection(char);
void calculateVelocity();
void calculateAcceleration();
void calculateForce();
void calculateWeight();
void calculateMomentum();

/********************************************************************
*                      FUNCTION DEFINITIONS
*********************************************************************/

//This function displays the menu on screen for user
void displayMenu()
{
  cout << "                    Physics Calculator: Main Menu                " << endl;
  cout << "\nPlease select one of the following calculations to perform by entering one of the alphabetical letters that precedes it. "<< endl << endl;
  cout << "(V) Velocity" << endl;
  cout << "(A) Acceleration" << endl;
  cout << "(M) Motion" << endl;
  cout << "(F) Force - Newton's Second Law" << endl;
  cout << "(W) Weight (planet Earth)" << endl;
  cout << "(I) Impulse and Momentum" << endl << endl;
  cout << "(X) Clear the Screen" << endl;
  cout << "(E) Exit out of the Menu" << endl << endl;


}

//This function displays the sub menu for the 4 equations of motion 
// if the user selects "(C) Motion" from the main menu
void displayMotionSubMenu()
{
  cout << endl;
  cout << "                    Physics Calculator: Motion Menu             " << endl;
  cout << "\nPlease select one of the equations of motion to calculate by entering the number that precedes it: " << endl << endl;
  cout << "(1) First Equation of Motion: Solve for Velocity" << endl;
  cout << "(2) Second Equation of Motion: Solve for Position" << endl;
  cout << "(3) Third Equation of Motion: Solve for Velocity Squared" << endl;
  cout << "(4) Fourth Equation of Motion: Solve for Average Velocity" << endl << endl;
}

//This function will accept the selected input (char) and select the
// matching calculation to perform
void processMainMenuSelection(char selection)
{
  switch(toupper(selection))
    {
      case 'V': cout << "\nYou selected option V: Calculate Velocity." <<endl;
                calculateVelocity();
                break;
      case 'A': cout << "\nYou selected option A: Calculate Acceleration." << endl;
                calculateAcceleration();
                break;
      case 'M': cout << "\nYou selected option M: Calculate Motion." << endl;
                displayMotionSubMenu();
                break;
      case 'F': cout << "\nYou selected option F: Calculate Force." << endl;
                calculateForce();
                break;
      case 'W': cout << "\nYou selected option W: Calculate Weight on Earth." << endl;
                calculateWeight();
                break;
      case 'I': cout << "\nYou selected option I: Calculate Impulse and Momentum." << endl;
                break;

      case 'E': cout << "\nYou selected option E: Exiting Program" << endl;
                break;
      case 'X': cout << "\nYou selected option X: Clearing the Screen." << endl;
                //Clear screen action borrowed from Dr. T's Starter Code
                string reset = "\x1b[0m";
                //Linux Umbunu
                cout << reset; 
                cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
                //Windows: system("cls"); 
                system("clear"); //for ubuntu Linux Option 2 of 2
                break;
    }
}

//This function calculates the velocity from user input
void calculateVelocity()
{
  //variable definitions
  double ds = 0.0;    //change in distance
  double dt = 0.0;    //change in time
  string sUnits = ""; //unit of measurement for distance
  string tUnits = ""; //unit of measurement for time

  cout << "The formula for calculating velocity is below: " << endl;
  cout << endl << endl;
  cout << "                    ds" << endl;
  cout << "              v = ------" << endl;
  cout << "                    dt" << endl;
  cout << endl;
  cout << "Please enter a value of type double for distance (ds): ";
  ds = validateDouble(ds);
  cout << "Please enter the unit of measurement for distance (ie. km, mi, m): ";
  sUnits = validateString(sUnits);
  cout << "Please enter a value of type double for the time (dt): ";
  dt = validateDouble(dt);
  cout << "Please enter the unit of measurement for time (ie. min, hour, sec): ";
  tUnits = validateString(tUnits);
  cout << "\nWith a distance of " << ds << " and time of " << dt << ", the velocity is " << fixed << setprecision(4) << ds/dt << sUnits << "/" << tUnits << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl << endl;
  cout << fixed << setprecision(2) << "                    ds     " << ds << sUnits << endl;
  cout << "              v = ------ = ------ = " << fixed << setprecision(4) << ds/dt << sUnits << "/" << tUnits << endl;
  cout << fixed << setprecision(2) << "                    dt     " << dt << tUnits << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function calculates the acceleration from user input
void calculateAcceleration()
{
  //variable definitions
  double dv = 0.0;    //change in velocity
  double dt = 0.0;    //change in time
  string vUnits = ""; //unit of measurement for velocity
  string tUnits = ""; //unit of measurement for time

  cout << "The formula for calculating acceleration is below: " << endl;
  cout << endl << endl;
  cout << "                    dv" << endl;
  cout << "              a = ------" << endl;
  cout << "                    dt" << endl;
  cout << endl;
  cout << "Please enter a value of type double for velocity (dv): ";
  dv = validateDouble(dv);
  cout << "Please enter the unit of measurement for velocity (ie. ): ";
  vUnits = validateString(vUnits);
  cout << "Please enter a value of type double for the time (dt): ";
  dt = validateDouble(dt);
  cout << "Please enter the unit of measurement for time (ie. min, hour, sec): ";
  tUnits = validateString(tUnits);
  cout << "\nWith a velocity of " << dv << " and time of " << dt << ", the accleration is " << fixed << setprecision(4) << dv/dt << vUnits << "/" << tUnits << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl << endl;
  cout << fixed << setprecision(2) << "                    dv     " << dv << vUnits << endl;
  cout << fixed << setprecision(4) << "              a = ------ = ------ = " << dv/dt << vUnits << "/" << tUnits << endl;
  cout << fixed << setprecision(2) << "                    dt     " << dt << tUnits << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function calculates the Force from user input
void calculateForce()
{
  //variable definitions
  double m = 0.0;    //mass of object
  double a = 0.0;    //acceleration of object
  string mUnits = ""; //unit of measurement for mass
  string aUnits = ""; //unit of measurement for acceleration

  cout << "The formula for calculating acceleration is below: " << endl;
  cout << endl;
  cout << "              F = m * a" << endl;
  cout << endl;
  cout << "Please enter a value of type double for mass (m): ";
  m = validateDouble(m);
  cout << "Please enter the unit of measurement for mass (ie. ): ";
  mUnits = validateString(mUnits);
  cout << "Please enter a value of type double for the acceleration (a): ";
  a = validateDouble(a);
  cout << "Please enter the unit of measurement for time (ie. min, hour, sec): ";
  aUnits = validateString(aUnits);
  cout << "\nWith a mass of " << m << " and acceleration of " << a << ", the Force is " << fixed << setprecision(4) << m*a << mUnits << " " << aUnits << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              F = m * a = " << m << " * " << a << " = " << fixed << setprecision(4) << m*a << mUnits << " " << aUnits << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function calculates the Weight from user input
void calculateWeight()
{
  //variable definitions
  double m = 0.0;    //mass of object
  double g = 0.0;    //acceleration due to gravity
  string mUnits = ""; //unit of measurement for mass
  string gUnits = ""; //unit of measurement for gravity

  cout << "The formula for calculating Weight is below: " << endl;
  cout << endl;
  cout << "              W = m * g" << endl;
  cout << endl;
  cout << "Please enter a value of type double for mass (m): ";
  m = validateDouble(m);
  cout << "Please enter the unit of measurement for mass (ie. ): ";
  mUnits = validateString(mUnits);
  cout << "Please enter a value of type double for the gravity (g): ";
  g = validateDouble(g);
  cout << "Please enter the unit of measurement for gravity: ";
  gUnits = validateString(gUnits);
  cout << "\nWith a mass of " << m << " and gravity of " << g << ", the Weight is " << fixed << setprecision(4) << m*g << mUnits << " " << gUnits << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              W = m * g = " << m << " * " << g << " = " << fixed << setprecision(4) << m*g << mUnits << " " << gUnits << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function calculates the Momentum from user input
void calculateMomentum()
{
  //variable definitions
  double m = 0.0;    //mass of object
  double v = 0.0;    //acceleration due to velocity
  string mUnits = ""; //unit of measurement for mass
  string vUnits = ""; //unit of measurement for velocity

  cout << "The formula for calculating Momentum is below: " << endl;
  cout << endl;
  cout << "              M = m * v" << endl;
  cout << endl;
  cout << "Please enter a value of type double for mass (m): ";
  m = validateDouble(m);
  cout << "Please enter the unit of measurement for mass (ie. ): ";
  mUnits = validateString(mUnits);
  cout << "Please enter a value of type double for the velocity (v): ";
  v = validateDouble(v);
  cout << "Please enter the unit of measurement for velocity: ";
  vUnits = validateString(vUnits);
  cout << "\nWith a mass of " << m << " and velocity of " << v << ", the Momentum is " << fixed << setprecision(4) << m*v << mUnits << " " << vUnits << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              M = m * v = " << m << " * " << v << " = " << fixed << setprecision(4) << m*v << mUnits << " " << vUnits << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}
#endif