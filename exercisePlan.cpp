/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan(Diet Plan)		   *
*******************************************************************************************/

//include class/std libraries
#include "exercisePlan.h"

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
ExercisePlan::ExercisePlan(int initStep, string initplanName, string initdate)
{
	this->goalSteps = initStep;
	this->planName = initplanName;
	this->date = initdate;
}

//destructor
ExercisePlan::~ExercisePlan()
{
	//delcared for point
}

//copy constructor
ExercisePlan::ExercisePlan(ExercisePlan &inputExercisePlan)
{
	this->goalSteps = inputExercisePlan.goalSteps;
	this->planName = inputExercisePlan.planName;
	this->date = inputExercisePlan.date;
}

//copy everything on the right side and set to left side
ExercisePlan & ExercisePlan::operator=(ExercisePlan & rhs)
{
	if (this != &rhs)
	{
		this->goalSteps = rhs.goalSteps;
		this->planName = rhs.planName;
		this->date = rhs.date;
	}
	return *this;
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

//set the member steps
void ExercisePlan::setgoalSteps(int newSteps)
{
	if(newSteps != this->goalSteps)
		this->goalSteps = newSteps;
}

//set the member plan name
void ExercisePlan::setplanName(string newPlanName)
{
	if((this->planName.compare(newPlanName)))
		this->planName = newPlanName;
}

//set date
void ExercisePlan::setdate(string newDate)
{
	if ((this->date.compare(newDate)))
		this->date = newDate;
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

//get goal steps
int ExercisePlan::getgoalSteps(void) const
{
	return this->goalSteps;
}

//get plan Name
string ExercisePlan::getplanName(void) const
{
	return this->planName;
}

//get date
string ExercisePlan::getdate(void) const
{
	return this->date;
}

/*************************************************************
* Function: Following functions will be member functions     *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: main member functions                         *
* Input parameters: none                                     *
* Returns: asked data                                        *
* Preconditions: Nothing                                     *
* Postconditions: data returned                              *
*************************************************************/

//edit goal steps
void ExercisePlan::editGoal(void)
{
	//local var
	char userInput = NULL;
	int newGoal = 0, success = 0;
	//do while for user input
	do {
		//brief message and get cin
		cout << "Please give new gaol steps: ";
		cin >> newGoal;
		if (!success)
		{
			//double check
			cout << "Are you want to change the goal steps from " << goalSteps
				<< " to " << newGoal << "?" << endl
				<< "Type (Y/y) or (N/n): ";
			cin >> userInput;
			//cout << toupper(userInput) << userInput << endl; //for debugging
			//simple and set goal to new goal
			if (toupper(userInput) == 'Y')
			{
				success = 1;
				goalSteps = newGoal;
			}
		}
		//system("pause"); //debugging
		//housekeeping
		system("cls");
	} while (!success);

	//housekeeping
	system("cls");
}

//edit goal plan name
void ExercisePlan::editName(void)
{
	//local var
	int success = 0;
	char userInput = NULL;
	char inputNewPlan[100];
	string newPlan;

	//do while for user input
	do {
		//brief message and get cin
		cout << "Please give new exercise plan name: ";
		cin.ignore();
		cin.getline(inputNewPlan, 99);
		newPlan = (string) inputNewPlan;
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

//edit date
void ExercisePlan::editDate(void)
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
void ExercisePlan::setExercisePlan(int inputSteps, string inputPlanName, string inputDate)
{
	setgoalSteps(inputSteps);
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

//this is to print exericse class
ostream & operator<< (ostream &lhs, ExercisePlan &rhs)
{
	lhs << "Plan Name: " << rhs.getplanName() << endl
		<< "Date: " << rhs.getdate() << endl
		<< "Goal Steps; " << rhs.getgoalSteps();

	return lhs;
}

//insert exercise plan
istream & operator>>(istream &lhs, ExercisePlan &rhs)
{
	/*int getUserGoalSteps = 0;
	string getPlanName, getDate;

	cout << "Please give exercise plan in the following manner (name date steps)" << endl <<
		"Example:" << endl <<
		"Plan: bob" << endl <<  
		"Date: 01/01/2016" << endl <<
		"Goal Steps: 100" << endl << 
		"Would be entered like: bob 01/01/2016 100" << endl <<
		"Please enter exercise plan: ";
	lhs >> getPlanName >> getDate >> getUserGoalSteps;

	rhs.setplanName(getPlanName);
	rhs.setdate(getDate);
	rhs.setgoalSteps(getUserGoalSteps);*/

	rhs.editName();
	rhs.editGoal();
	rhs.editDate();

	system("cls");

	return lhs;
}

//taking a single plan from a file
fstream & operator>>(fstream &lhs, ExercisePlan &rhs)
{
	char planName[100], date[100], tempStep[100], newLineHolder[100];
	int step = 0;

	lhs.getline(planName, 100);
	lhs.getline(tempStep, 100);
	lhs.getline(date, 100);
	lhs.getline(newLineHolder, 100);

	step = atoi(tempStep);

	rhs.setExercisePlan(step, (string)planName, (string)date);

	return lhs;
}

//write to a file
fstream & operator<<(fstream &lhs, ExercisePlan &rhs)
{
	lhs << rhs.getplanName() << endl
		<< rhs.getgoalSteps() << endl
		<< rhs.getdate() << endl << endl;

	return lhs;
}