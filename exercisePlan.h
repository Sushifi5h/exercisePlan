/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan					   *
*******************************************************************************************/

#pragma once //gaurd code

//Include standard C++ libraries
#include <iostream> //for basica ins/outs
#include <fstream> //for files
#include <string> //to declare strings
#include <ctype.h> //for string compares toUpper
#include <stdlib.h> // atoi

//forgot name
using std::cout;
using std::cin;
using std::endl;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;

//Exercise Plan Class
class ExercisePlan 
{
//public
public:
	
	ExercisePlan(int initStep = 0, string initplanName = "<blank>", 
		string initdate = "00/00/0000"); //constructor
	~ExercisePlan();//destructor
	ExercisePlan(ExercisePlan &inputExercisePlan); //copy constructor
	ExercisePlan & operator=(ExercisePlan &rhs); //copy construct with equal sign

	//member functions
	void editGoal(void); //edits goal
	void editName(void); //edits Name
	void editDate(void); //edits Date
	void setExercisePlan(int inputSteps, string inputPlanName, string inputDate); //set all value at once

	//member setters
	void setgoalSteps(int newSteps); //set goal Steps
	void setplanName(string newPlanName); //set plan name
	void setdate(string newDate);//set date

	//member getters
	int getgoalSteps(void) const; //gets step of goals
	string getplanName(void) const; //get plan name
	string getdate(void) const; //get date for exercise plan

//private
private:
	int goalSteps; //step goal
	string planName; //plan Name
	string date; //date
};

//none member overload functions
ostream & operator<<(ostream &lhs, ExercisePlan &rhs); //print exercise plan
istream & operator>>(istream &lhs, ExercisePlan &rhs); //take in plan
fstream & operator>>(fstream &lhs, ExercisePlan &rhs); //taking from a file
fstream & operator<<(fstream &lhs, ExercisePlan &rhs); //write to a file