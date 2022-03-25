/********************************************************************
*  Assignment: Unit 1
*  Title:      Physics Calculator
*  Student:    Michael Nguyen
*  Teacher:    Tyson McMillan
*  Date:       03/25/2022
*
*  Description: This is a program that will mimic a physics 
*    calculator.  The program will display a menu with several 
*    options to calculate several physics formulas. 
*    
*********************************************************************/
#include<iostream>
#include "functions.h"

int main() {

  
  //Change-Reset Color borrowed from Dr. T's Starter Code. (thank you sir)
  string option = ""; //the option local to int main()
  string color = "\x1b[" + to_string(32) + ";1m";
  string reset = "\x1b[0m";
  char menuOption;

  do
    {
      
    displayMenu();
      
    cout << "Please Select and Option. " << endl;
    
    menuOption = validateChar(menuOption);

    processMainMenuSelection(menuOption);

    }while(toupper(menuOption) != 'E');
  
  return 0;
}