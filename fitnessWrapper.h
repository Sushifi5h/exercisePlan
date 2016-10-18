/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan					   *
*******************************************************************************************/
#pragma //can we used as gaurd code

//Inlcude standard C++ libraries
#include <iostream>//include for ins and outs
#include <fstream> //for files
#include"dietPlan.h" //diet class
#include "exercisePlan.h" //exercise class
#include <stdlib.h> // atoi

//what are these???
using std::cout;
using std::endl;
using std::cin;
using std::string;
using std::ostream;
using std::istream;
using std::fstream;
using std::ifstream;
using std::ofstream;

//Fitness Wrapper class
class FitnessWrapper
{
//public functions
public:
//construct, destrucotr
	FitnessWrapper(); //allocate memory for 
	~FitnessWrapper();//dellocate memory

//private vars and functions
	void appRunner(void); //main logic 
	int displayMenu(void); //display menu and return choice 1-9
	void displayWeeklyDietPlan(void); //display weekly diet plan
	void displayDailyDietPlan(DietPlan &day); //contains cout
	void displayWeeklyExercisePlan(void); //dissplace weekly exercisen
	void displayDailyExercisePlan(ExercisePlan &day);//contains cout
	void editDietPlan(void); //edit diet plan
	void editExercisePlan(void); //edit exercise plan
	void deleteADaysDietPlan(void); //delete a days diet plan
	void deleteADayExercisePlan(void); //delete a exercise plan
	void loadWeeklydietplan(fstream &dietFile); //load weekly diet plan from a file
	void loaddailydietplan(fstream &dietFile, DietPlan &plan);//single
	void loadWeeklyExerciseplan(fstream &exercisePlan); //load weekly diet plan from a file
	void loaddailyExerciseplan(fstream &exercisePlan, ExercisePlan &day); //load weekly diet plan from a file
	void storeWeeklyDietPlan(fstream &dietFile); //write weekly diet plan to file
	void storeWeeklyExercisePlan(fstream &exerciseFile); //write weekly diet plan to file
	void storeDailyDietPlan(fstream &dietFile, DietPlan &day); //write weekly diet plan to file
	void storeDailyExercisePlan(fstream &exerciseFile, int day); //write weekly diet plan to file
	
private:
	DietPlan *userDietPlan; //pointer for dynamic memory allocate
	ExercisePlan *userExercisePlan; //pointer for dynamic memory allocate
	
};