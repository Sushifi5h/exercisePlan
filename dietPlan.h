/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan(Diet Plan)		   *
*******************************************************************************************/
#pragma //can we used as gaurd code

//Inlcude standard C++ libraries
#include <iostream> //include for ins and outs
#include <fstream> //for files
#include <string> //for strings
#include <ctype.h>// for to upper
#include <stdlib.h> // atoi

//what are these???
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;

//Diet Plan Class
class DietPlan
{
//public funtions 
public:
	
	DietPlan(int inputCalories = 2000, string inputplanName = "<blank>", 
		string inputDate = "00/00/0000"); //constructor
	~DietPlan(); //destructor	
	DietPlan(DietPlan &inputDietPlan); //copy constructor
	DietPlan & operator=(DietPlan &rhs); //copy construct with equal sign

	//member functions
	void editGoal(void); //edits goal
	void editName(void); //edits Name
	void editDate(void); //edits Date
	void setDietPlan(int inputCalories, string inputPlanName, string inputDate); //set all value at once

	//member setters
	void setgoalCalories(int inputCalories); //sets the member goalCalories
	void setplanName(string inputplanName); //set the member planName
	void setdate(string inputdate); //set member date

	//member getters	
	int getgoalCalories(void) const; //gets goal calories
	string getplanName(void) const; //get plan name
	string getdate(void) const; //get date

//private vars and functions
private:
	int goalCalories;
	string planName;
	string date;
};

//none member overload functions
ostream & operator<< (ostream &lhs, DietPlan &rhs); //print exercise plan
istream & operator>>(istream &lhs, DietPlan &rhs); //take in plan
fstream & operator>>(fstream &lhs, DietPlan &rhs); //taking from a file
fstream & operator<<(fstream &lhs, DietPlan &rhs); //write to a file