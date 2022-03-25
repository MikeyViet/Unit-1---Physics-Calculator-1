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
#include<math.h>
#include"Input_Validation_Extended.h"

/********************************************************************
*                      GLOBAL VARIABLES
*********************************************************************/

//Change-Reset Color borrowed from Dr. T's Starter Code. (thank you sir)
string option = ""; //the option local to int main()
string color = "\x1b[" + to_string(32) + ";1m";
string reset = "\x1b[0m";

/********************************************************************
*                      FUNCTION PROTOTYPES
*********************************************************************/

void displayMenu();
void displayMotionSubMenu();
void processMainMenuSelection(char);
void processMotionMenuSelection(int);
void calculateVelocity();
void calculateAcceleration();
void calculateForce();
void calculateWeight();
void calculateMomentum();
void calculateMotion1();  //First Equation of Motion solving for final velocity
void calculateMotion2();  //Second Equation of Motion solving for position
void calculateMotion3();  //Third Equation of Motion solving for velocity squared
void calculateMotion4();  //Fourth Equation of Motion solving for average velocity

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
  int motionSelection = 0;  //holds the selection from Motion Sub Menu
  
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

                do
                  {
                    cout << "Please Enter a number between 1 - 4: ";
                    motionSelection = validateInt(motionSelection);
                    }while(motionSelection < 1 || motionSelection > 4);
        
                processMotionMenuSelection(motionSelection);
                break;
      case 'F': cout << "\nYou selected option F: Calculate Force." << endl;
                calculateForce();
                break;
      case 'W': cout << "\nYou selected option W: Calculate Weight on Earth." << endl;
                calculateWeight();
                break;
      case 'I': cout << "\nYou selected option I: Calculate Impulse and Momentum." << endl;
                calculateMomentum();
                break;

      case 'E': cout << "\nYou selected option E: Exiting Program" << endl;
                break;
      case 'X': cout << "\nYou selected option X: Clearing the Screen." << endl;
                //Clear screen action borrowed from Dr. T's Starter Code
                //string reset = "\x1b[0m";
                //Linux Umbunu
                cout << reset; 
                cout << "\033[2J\033[1;1H";  //for ubuntu Linux Option 1 of 2
                //Windows: system("cls"); 
                system("clear"); //for ubuntu Linux Option 2 of 2
                break;
    }
}

//Function will accept the selected user input (int) and select the 
// matching calculation to perform
void processMotionMenuSelection(int selection)
{
  switch(selection)
    {
      case 1: cout << "\nYou selected option 1: The First Equation of Motion" << endl;
                calculateMotion1();
                break;
      case 2: cout << "\nYou selected option 2: The Second Equation of Motion" << endl;
                calculateMotion2();
                break;
      case 3: cout << "\nYou selected option 3: The Third Equation of Motion" << endl;
                calculateMotion3();
                break;
      case 4: cout << "\nYou selected option 4: The Fourth Equation of Motion" << endl;
                calculateMotion4();
                break;
      default: cout << "Please enter a number between 1 - 4" << endl;
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
  cout << "\nWith a distance of " << ds << " and time of " << dt << ", the velocity is " << fixed << setprecision(4) << color << ds/dt << sUnits << "/" << tUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl << endl;
  cout << fixed << setprecision(2) << "                    ds     " << ds << sUnits << endl;
  cout << "              v = ------ = ------ = " << fixed << setprecision(4) << color << ds/dt << sUnits << "/" << tUnits << reset << endl;
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
  cout << "\nWith a velocity of " << dv << " and time of " << dt << ", the accleration is " << fixed << setprecision(4) << color << dv/dt << vUnits << "/" << tUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl << endl;
  cout << fixed << setprecision(2) << "                    dv     " << dv << vUnits << endl;
  cout << fixed << setprecision(4) << "              a = ------ = ------ = " << color << dv/dt << vUnits << "/" << tUnits << reset << endl;
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
  cout << "\nWith a mass of " << m << " and acceleration of " << a << ", the Force is " << fixed << setprecision(4) << color << m*a << mUnits << " " << aUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              F = m * a = " << m << " * " << a << " = " << fixed << setprecision(4) << color << m*a << mUnits << " " << aUnits << reset << endl;
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
  cout << "\nWith a mass of " << m << " and gravity of " << g << ", the Weight is " << fixed << setprecision(4) << color << m*g << mUnits << " " << gUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              W = m * g = " << m << " * " << g << " = " << fixed << setprecision(4) << color << m*g << mUnits << " " << gUnits << reset << endl;
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
  cout << "              P = m * v" << endl;
  cout << endl;
  cout << "Please enter a value of type double for mass (m): ";
  m = validateDouble(m);
  cout << "Please enter the unit of measurement for mass (ie. ): ";
  mUnits = validateString(mUnits);
  cout << "Please enter a value of type double for the velocity (v): ";
  v = validateDouble(v);
  cout << "Please enter the unit of measurement for velocity: ";
  vUnits = validateString(vUnits);
  cout << "\nWith a mass of " << m << " and velocity of " << v << ", the Momentum is " << fixed << setprecision(4) << color << m*v << mUnits << " " << vUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              P = m * v = " << m << " * " << v << " = " << fixed << setprecision(4) << color << m*v << mUnits << " " << vUnits << reset << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function solves for velocity using the First Equation of Motion
void calculateMotion1()
{
  //variable definitions
  double Vo = 0.0;    //initial velocity
  double t = 0.0;     //time
  double a = 0.0;     //acceleration
  string aUnits = ""; //unit of measurement for acceleration
  string tUnits = ""; //unit of measurement for time
  string vUnits = ""; //unit of measurement for velocity

  cout << "The First Equation of Motion solving for final velocity (V) is below: " << endl;
  cout << endl;
  cout << "              V = Vo + at" << endl;
  cout << endl;
  cout << "Please enter a value of type double for initial velocity (Vo): ";
  Vo = validateDouble(Vo);
  cout << "Please enter the unit of measurement for initial velocity (ie. ): ";
  vUnits = validateString(vUnits);
  cout << "Please enter a value of type double for the time (t): ";
  t = validateDouble(t);
  cout << "Please enter the unit of measurement for time: ";
  tUnits = validateString(tUnits);
  cout << "Please enter a value of type double for the acceleration (a): ";
  a = validateDouble(a);
  cout << "Please enter the unit of measurement for acceleration: ";
  aUnits = validateString(aUnits);
  cout << "\nWith an initial velocity of " << Vo << ", acceleration of " << a << ", and time of " << t << ", the final velocity is " << fixed << setprecision(4) << color << Vo+(a*t) << vUnits << " " << aUnits << tUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(2) << "              V = Vo + at = " << Vo << " + (" << a << " * " << t << ") = " << fixed << setprecision(4) << color << Vo+(a*t) << vUnits << " " << aUnits << " " << tUnits << reset << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function solves for position at some time using the Second Equation of Motion
void calculateMotion2()
{
  //variable definitions
  double Vo = 0.0;    //initial velocity
  double t = 0.0;     //time
  double a = 0.0;     //acceleration
  double So = 0.0;     //initial Position
  string aUnits = ""; //unit of measurement for acceleration
  string tUnits = ""; //unit of measurement for time
  string vUnits = ""; //unit of measurement for velocity

  cout << "The Second Equation of Motion solving for Position (P) is below: " << endl;
  cout << endl;
  cout << "                              1" << endl;
  cout << "              S = So + Vot + --- at" << endl;
  cout << "                              2" << endl;
  cout << endl;
  cout << "Please enter a value of type double for initial velocity (Vo): ";
  Vo = validateDouble(Vo);
  cout << "Please enter the unit of measurement for initial velocity (ie. ): ";
  vUnits = validateString(vUnits);
  cout << "Please enter a value of type double for the time (t): ";
  t = validateDouble(t);
  cout << "Please enter the unit of measurement for time: ";
  tUnits = validateString(tUnits);
  cout << "Please enter a value of type double for the acceleration (a): ";
  a = validateDouble(a);
  cout << "Please enter the unit of measurement for acceleration: ";
  aUnits = validateString(aUnits);
  cout << "Please enter a value of type double for the initial position (So): ";
  So = validateDouble(So);
  cout << "Please enter the unit of measurement for acceleration: ";
  //aUnits = validateString(aUnits);
  cout << "\nWith an initial velocity of " << Vo << ", acceleration of " << a << ", and time of " << t << ", the final velocity is " << fixed << setprecision(4) << color << Vo+(a*t) << vUnits << " " << aUnits << " " << tUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << "                              1" << endl;
  cout << fixed << setprecision(0) << "              S = So + Vot + --- at = "<< So << " + (" << Vo << ")(" << t << ") + 1/2 (" << a << ")(" << t << ") = " << setprecision(4) << color << So + ((Vo + ((a/2)*t)) * t) << reset << endl;
  cout << "                              2" << endl;
  cout << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function solves for velocity squared using the Third Equation of Motion
void calculateMotion3()
{
  //variable definitions
  double Vo = 0.0;    //initial velocity
  double a = 0.0;     //acceleration
  double ds = 0.0;    //change in position
  string aUnits = ""; //unit of measurement for acceleration
  string sUnits = ""; //unit of measurement for position
  string vUnits = ""; //unit of measurement for velocity

  cout << "The Third Equation of Motion solving for Velocity Squared (V^2) is below: " << endl;
  cout << endl;
  cout << "              V^2 = (Vo)^2 + 2(a)(ds)" << endl;
  cout << endl;
  cout << "Please enter a value of type double for initial velocity (Vo): ";
  Vo = validateDouble(Vo);
  cout << "Please enter the unit of measurement for initial velocity (ie. ): ";
  vUnits = validateString(vUnits);
  cout << "Please enter a value of type double for the change in position (ds): ";
  ds = validateDouble(ds);
  cout << "Please enter the unit of measurement for change in position: ";
  sUnits = validateString(sUnits);
  cout << "Please enter a value of type double for the acceleration (a): ";
  a = validateDouble(a);
  cout << "Please enter the unit of measurement for acceleration: ";
  aUnits = validateString(aUnits);
  //aUnits = validateString(aUnits);
  cout << "\nWith an initial velocity of " << Vo << ", acceleration of " << a << ", and change in position of " << ds << ", the velocity squared is " << fixed << setprecision(4) << color << pow(Vo,2) + 2 * a * ds << vUnits << " " << aUnits << " " << sUnits << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << fixed << setprecision(0) << "              V^2 = (Vo)^2 + 2(a)(ds) = (" << Vo << ")^2 + 2(" << a << ")(" << ds << ") = " << setprecision(4) << color << pow(Vo,2) + 2 * a * ds << vUnits << " " << aUnits << sUnits << reset << endl;
  cout << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}

//This function solves for average velocity using the Fourth Equation of Motion
void calculateMotion4()
{
  //variable definitions
  double Vo = 0.0;    //initial velocity
  double V = 0.0;     //final velocity
  string sUnits = ""; //unit of measurement for distance
  string tUnits = ""; //unit of measurement for time

  cout << "The Fourth Equation of Motion solving for average velocity (V_bar) is below: " << endl;
  cout << endl;
  cout << "              _    1" << endl;
  cout << "              V = --- (V + Vo)" << endl;
  cout << "                   2" << endl; 
  cout << endl;
  cout << "Please enter a value of type double for initial velocity (Vo): ";
  Vo = validateDouble(Vo);
  cout << "Please enter a value of type double for the final velocity (V): ";
  V = validateDouble(V);
  cout << "Please enter the unit of measurement for distance (ie. km, m, mi, ft ): ";
  sUnits = validateString(sUnits);
  cout << "Please enter the unit of measurement for time (ie. hr, min, s): ";
  tUnits = validateString(tUnits);
  cout << "\nWith an initial velocity of " << Vo << " and final velocity of " << V << ", the average velocity is " << fixed << setprecision(4) << color << (V + Vo)/2 << sUnits << "/" << tUnits << " " << reset << endl;
  cout << "Plugging in the values entered results in the following formula:" << endl;
  cout << endl;
  cout << "              _    1              1" << endl;
  cout << "              V = --- (V + Vo) = --- (" << V << " + " << Vo << ") = " << fixed << setprecision(4) << color << (V + Vo)/2 << sUnits << "/" << tUnits << " " << reset << endl;
  cout << "                   2              2" << endl; 
  cout << endl;
  cout << endl;
  cout << "---------------------------------------------------------------------" << endl << endl;
}
#endif