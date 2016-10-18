/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan(Diet Plan)		   *
*******************************************************************************************/

//Include class/std libraries
#include "dietPlan.h"

/*************************************************************
* Function:Following functions will be constructor/destructor*
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: copy constructor, constructor and destructor  *
* Input parameters: data                                     *
* Returns: nothing                                           *
* Preconditions: Nothing                                     *
* Postconditions:                                            *
*************************************************************/

//constructor
DietPlan::DietPlan(int inputCalories, string inputplanName, string inputDate)
{
	goalCalories = inputCalories;
	planName = inputplanName;
	date = inputDate;
}

//copty constructor
DietPlan::DietPlan(DietPlan &inputDietPlan)
{
	goalCalories = inputDietPlan.goalCalories;
	planName = inputDietPlan.planName;
	date = inputDietPlan.date;
}

//copy construct with equal operator
DietPlan & DietPlan::operator=(DietPlan & rhs)
{
	if (this != &rhs)
	{
		this->goalCalories = rhs.goalCalories;
		this->planName = rhs.planName;
		this->date = rhs.date;
	}
	return *this;
}

//destructor
DietPlan::~DietPlan(void)
{
	//delcared for point
}

/*************************************************************
* Function: Following functions will be setters              *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: main setters for the class                    *
* Input parameters: data                                     *
* Returns: nothing                                           *
* Preconditions: Nothing                                     *
* Postconditions:                                            *
*************************************************************/

//sets the member goalCalories
void DietPlan::setgoalCalories(int inputCalories)
{
	goalCalories = inputCalories;
}

//set the member planName
void DietPlan::setplanName(string inputplanName)
{
	planName = inputplanName;
}

//set member date
void DietPlan::setdate(string inputdate)
{
	date = inputdate;
}

/*************************************************************
* Function: Following functions will be getters              *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: main getters for the class                    *
* Input parameters: none                                     *
* Returns: asked data                                        *
* Preconditions: Nothing                                     *
* Postconditions: data returned                              *
*************************************************************/

//get Calories
int DietPlan::getgoalCalories(void) const
{
	return goalCalories;
}

//get plan name
string DietPlan::getplanName(void) const
{
	return planName;
}

//get date
string DietPlan::getdate(void) const 
{
	return date;
}

/*************************************************************
* Function: Following functions will used with member data   *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: main function                                 *
* Input parameters: none                                     *
* Returns: asked data                                        *
* Preconditions: Nothing                                     *
* Postconditions: data returned                              *
*************************************************************/

//edit goal
void DietPlan::editGoal(void)
{
	//local var
	char userInput = NULL;
	int newGoal = 0, success = 0;
	//do while for user input
	do {
		//brief message and get cin
		cout << "Please give new gaol: ";
		cin >> newGoal;
		if (!success)
		{
			//double check
			cout << "Are you want to change the goal calories from " << goalCalories
				<< " to " << newGoal << "?" << endl
				<< "Type (Y/y) or (N/n): ";
			cin >> userInput;
			//cout << toupper(userInput) << userInput << endl; //for debugging
			//simple and set goal to new goal
			if (toupper(userInput) == 'Y')
			{
				success = 1;
				goalCalories = newGoal;
			}
		}
		//system("pause"); //debugging
		//housekeeping
		system("cls");
	} while (!success);

	//housekeeping
	system("cls");
}

//edit Plan Name
void DietPlan::editName(void)
{
	//local var
	int success = 0;
	char userInput = NULL, inputNewPlan[100];
	string newPlan;
	
	//do while for user input
	do {
		//brief message and get cin
		cout << "Please give new diet plan name: ";
		cin.ignore();
		cin.getline(inputNewPlan, 99);
		newPlan = (string)inputNewPlan;
		if (!success)
		{
			//double check
			cout << "Are you want to change plan name from " << planName
				<< " to " << newPlan << "?" << endl
				<< "Type (Y/y) or (N/n): ";
			cin >> userInput;
			//cout << toupper(userInput) << userInput << endl; //for debugging
			//simple and set goal to new goal
			if (toupper(userInput) == 'Y')
			{
				success = 1;
				planName = newPlan;
			}
		}
		//system("pause"); //debugging
		//housekeeping
		system("cls");
	} while (!success);

	//housekeeping
	system("cls");
}

//edit Date
void DietPlan::editDate(void)
{
	//local var
	int success = 0;
	char userInput = NULL, inputNewPlan[100];
	string newDate;

	//do while for user input
	do {
		//brief message and get cin
		cout << "Please give new date: ";
		cin.ignore();
		cin.getline(inputNewPlan, 99);
		newDate = (string)inputNewPlan;
		if (!success)
		{
			//double check
			cout << "Are you want to change date from " << date
				<< " to " << newDate << "?" << endl
				<< "Type (Y/y) or (N/n): ";
			cin >> userInput;
			//cout << toupper(userInput) << userInput << endl; //for debugging
			//simple and set goal to new goal
			if (toupper(userInput) == 'Y')
			{
				success = 1;
				date = newDate;
			}
		}
		//system("pause"); //debugging
		//housekeeping
		system("cls");
	} while (!success);

	//housekeeping
	system("cls");
}

//set all values of exercise plan
void DietPlan::setDietPlan(int inputCalories, string inputPlanName, string inputDate)
{
	setgoalCalories(inputCalories);
	setplanName(inputPlanName);
	setdate(inputDate);
}

/*************************************************************
* Function: Following functions will be nonmember overloadop *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: main non member functions                     *
* Input parameters: none                                     *
* Returns: asked data                                        *
* Preconditions: Nothing                                     *
* Postconditions: data returned                              *
*************************************************************/

//this to print exercise class
ostream & operator<< (ostream &lhs, DietPlan &rhs)
{
	lhs << "Plan Name: " << rhs.getplanName() << endl
		<< "Date: " << rhs.getdate() << endl
		<< "Goal Steps; " << rhs.getgoalCalories();

	return lhs;
}

//insert exercise plan
istream & operator>>(istream &lhs, DietPlan &rhs)
{
	int getUserGoalSteps = 0;
	string getPlanName, getDate;

	/*cout << "Please give diet plan in the following manner (name date calories)" << endl <<
		"Example:" << endl <<
		"Plan: bob" << endl <<
		"Date: 01/01/2016" << endl <<
		"Goal Calories: 2200" << endl <<
		"Would be entered like: bob 01/01/2016 2200" << endl <<
		"Please enter dietplan plan: ";
	lhs >> getPlanName >> getDate >> getUserGoalSteps;
	rhs.setplanName(getPlanName);
	rhs.setdate(getDate);
	rhs.setgoalCalories(getUserGoalSteps);*/

	rhs.editName();
	rhs.editGoal();
	rhs.editDate();


	system("cls");

	return lhs;
}

//taking a single plan from a file
fstream & operator>>(fstream &lhs, DietPlan &rhs)
{
	char planName[100], date[100], tempCalories[100], newLineHolder[100];
	int calories = 0;

	lhs.getline(planName, 100);
	lhs.getline(tempCalories, 100);
	lhs.getline(date, 100);
	lhs.getline(newLineHolder, 100);

	calories = atoi(tempCalories);

	rhs.setDietPlan(calories, (string) planName, (string) date);

	return lhs;
}

//writing a single diet plan to a file
fstream & operator<<(fstream &lhs, DietPlan &rhs)
{
	lhs << rhs.getplanName() << endl
		<< rhs.getgoalCalories() << endl
		<< rhs.getdate() << endl << endl;

	return lhs;
}