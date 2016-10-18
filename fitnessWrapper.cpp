/*******************************************************************************************
* Student: Vikram Singh StudentID: 11491025                                                *
* Class: CptS 122, Fall  2016; Lab Section 5                                               *
* Programming Assignment: Programming Assignment 4					                       *
* Date: February 21, 2016                                                                  *
* Description: Writing a program to manage dietplan and exercise plan					   *
*******************************************************************************************/

//include local libraries
#include "fitnessWrapper.h"

/*************************************************************
* Function: construcotr and destrucotr                       *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: constructor and destructor                    *
* Input parameters: none                                     *
* Returns:                                                   *
* Preconditions: Nothing                                     *
* Postconditions: number returned                            *
*************************************************************/
//constructor
FitnessWrapper::FitnessWrapper(void)
{
	this->userDietPlan = new DietPlan[7];
	this->userExercisePlan = new ExercisePlan[7];
}

//destructor
FitnessWrapper::~FitnessWrapper(void)
{
	delete[] this->userDietPlan;
	delete[] this->userExercisePlan;
}

/*************************************************************
* Function: displayMenu                                      *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: sets up main menu                             *
* Input parameters: none                                     *
* Returns: int from 1 to 9                                   *
* Preconditions: Nothing                                     *
* Postconditions: number returned                            *
*************************************************************/
int FitnessWrapper::displayMenu(void)
{
	//local var for choice
	int choice = 0;

	//brief intro
	cout << "\tThis is a basic fitness Aplication." << endl
		<< "This will allow you to change your exercise and diet plans." << endl
		<< "============================================================" << endl;
	
	//do while for user choice
	do {

		//give option to select
		cout << "\t\t Main Menu:" << endl
			 << "=========================================" << endl
			 << "(Please make a selection from 1 to 9)" << endl
			 << "\t1. Load weekly diet plan from file." << endl
			 << "\t2. Load weekly exercise plan from file." << endl
			 << "\t3. Store weekly diet plan to file." << endl
			 << "\t4. Store weekly exercise plan to file." << endl
			 << "\t5. Display weekly diet plan to screen." << endl
			 << "\t6. Display weekly exercise plan to screen." << endl
			 << "\t7. Edit daily diet plan." << endl
			 << "\t8. Edit daily exercise plan." << endl
			 << "\t9. Delete a certain day in the Diet Plan.(in Aplha)" << endl
			 << "\t10. Delete a certain day in Exercise Plan.(in Aplha)" << endl
			 << "\t11. Exit." << endl;

		cout << "Please enter selection: "; //clue for cin
		cin >> choice; //store value into choice

		//help user correct choice
		if ((choice <= 0) || (choice >= 12))
		{
			//print message and puase program
			cout << "=========================================" << endl;
			cout << "Please make another choice. You selected " << choice
				 << ". Which isn't between 1-11." << endl;
			system("pause");
			
		}

		//clear screen works better
		system("cls");
		
	} while ((choice <= 0) || (choice >= 12));

	return choice;
}

/*************************************************************
* Function: appRunner                                        *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description: contains all logic                            *
* Input parameters: none                                     *
* Returns: int from 1 to 9                                   *
* Preconditions: Nothing                                     *
* Postconditions: number returned                            *
*************************************************************/
void FitnessWrapper::appRunner(void)
{
	int exit = 0, dietCheck = 0, exerciseCheck = 0;
	fstream dietPlanFile, exercisePlanFile, dietplanFile1, exerciseFile;
	
	while (!exit)
	{
		switch (displayMenu())
		{
		case 1://load weekly diet plan
			dietCheck = 1;
			dietplanFile1.open("dietPlans.txt");
			loadWeeklydietplan(dietplanFile1);
			dietplanFile1.close();
			break;
		case 2://load weekely exercise plan from file
			exerciseCheck = 1;
			exerciseFile.open("exercisePlans.txt");
			loadWeeklyExerciseplan(exerciseFile);
			exerciseFile.close();
			break;
		case 3://store weekly diet plan to file
			if (dietCheck)
			{
				dietPlanFile.open("writingDietPlan.txt");
				storeWeeklyDietPlan(dietPlanFile);
				dietPlanFile.close();
			}
			else {
				cout << "Please load from file first." << endl;
				system("pause");
				system("cls");
			}
			
			break;
		case 4: //store weekly exercise plan to file
			if (exerciseCheck)
			{
				exercisePlanFile.open("writingExercisePlan.txt");
				storeWeeklyExercisePlan(exercisePlanFile);
				exercisePlanFile.close();
			}
			else {
				cout << "Please load from file first." << endl;
				system("pause");
				system("cls");
			}
			
			break;
		case 5: //display weekly dietplan
			displayWeeklyDietPlan();
			break;
		case 6: //display weekly exercise plan
			displayWeeklyExercisePlan();
			break;
		case 7: //Edit Diet Plan
			editDietPlan();
			break;
		case 8: //Edit Exercise Plan
			editExercisePlan();
			break;
		case 9://delete a certain days diet plan
			deleteADaysDietPlan();
			break;
		case 10://delete a certain days exercise plan
			deleteADayExercisePlan();
			break;
		case 11://save and exit
			if (dietCheck)
			{
				dietPlanFile.open("writingDietPlan.txt");
				storeWeeklyDietPlan(dietPlanFile);
				dietPlanFile.close();
			}
			if (exerciseCheck)
			{
				exercisePlanFile.open("writingExercisePlan.txt");
				storeWeeklyExercisePlan(exercisePlanFile);
				exercisePlanFile.close();
			}
			exit = 1;
		}
	}

}

/*************************************************************
* Function: Display weekly plans for die and exercise plans  *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description:                                               *
* Input parameters: none                                     *
* Returns: int from 1 to 9                                   *
* Preconditions: Nothing                                     *
* Postconditions: number returned                            *
*************************************************************/
//print weekly dietplan
void FitnessWrapper::displayWeeklyDietPlan(void)
{
	cout << "Displaying weekly diet plan." << endl
		 << "=========================================" << endl;

	for (int counter = 0; counter < 7; counter++)
		displayDailyDietPlan(this->userDietPlan[counter]);

	//housekeeping
	cout << "=========================================" << endl
		<< "Returning to Main Menu." << endl;
	system("pause");
	system("cls");
}
void FitnessWrapper::displayDailyDietPlan(DietPlan &day)
{
	cout << day << endl;
}

//print weekly exercise pland
void FitnessWrapper::displayWeeklyExercisePlan(void)
{
	cout << "Displaying weekly exercise plan." << endl
		<< "=========================================" << endl;

	for (int counter = 0; counter < 7; counter++)
		displayDailyExercisePlan(this->userExercisePlan[counter]);

	//housekeeping
	cout << "=========================================" << endl
		<< "Returning to Main Menu." << endl;
	system("pause");
	system("cls");
}

void FitnessWrapper::displayDailyExercisePlan(ExercisePlan &day)
{
	cout << day << endl;
}

/*************************************************************
* Function: Edit diet/exericse plan                          *
* Date Created: 02/21/2015                                   *
* Date Last Modified: 02/21/2015                             *
* Description:                                               *
* Input parameters: none                                     *
* Returns:                                                   *
* Preconditions: Nothing                                     *
* Postconditions: number returned                            *
*************************************************************/

//edit Diet Plan
void FitnessWrapper::editDietPlan(void)
{
	int day = 0;

	do {
		cout << "Please enter the day you would like to edit 1 through 7: ";
		cin >> day;
		system("cls");
	} while ((day <= 0) || (day >= 8));

	cin >> this->userDietPlan[day - 1];
	cout << this->userDietPlan[day - 1] << endl
		 << "Edited Diet Plan. Returning to Main Menu" << endl;

	//house keeping
	system("pause");
	system("cls");
}

//edit Diet Plan
void FitnessWrapper::editExercisePlan(void)
{
	int day = 0;

	do {
		cout << "Please enter the day you would like to edit 1 through 7: ";
		cin >> day;
		system("cls");
	} while ((day <= 0) || (day >= 8));

	cin >> this->userExercisePlan[day - 1];
	cout << this->userExercisePlan[day - 1] << endl
		<< "Edited Exercise Plan. Returning to Main Menu" << endl;

	//house keeping
	system("pause");
	system("cls");
}

//delete days diet plan
void FitnessWrapper::deleteADaysDietPlan(void)
{
	int day = 0;

	do {
		cout << "Please enter the day you would like to edit 1 through 7: ";
		cin >> day;
		system("cls");
	} while ((day <= 0) || (day >= 8));

	this->userDietPlan[day - 1].setDietPlan(0, "deleted", "deleted");
}

//delete days exercise plan
void FitnessWrapper::deleteADayExercisePlan(void)
{
	int day = 0;

	do {
		cout << "Please enter the day you would like to edit 1 through 7: ";
		cin >> day;
		system("cls");
	} while ((day <= 0) || (day >= 8));

	this->userExercisePlan[day - 1].setExercisePlan(0, "deleted", "deleted");
}

//load weekly diet plan from a file
void FitnessWrapper::loadWeeklydietplan(fstream &dietFile)
{

	for (int counter = 0; counter < 7; counter++)
		loaddailydietplan(dietFile,this->userDietPlan[counter]);

	cout << "Done reading weekly diet plans from file." << endl
		<< "Returning to Main Menu." << endl;

	//house keeping
	system("pause");
	system("cls");
}

void FitnessWrapper::loaddailydietplan(fstream &dietFile, DietPlan &plan)
{
	dietFile >> plan;
}
 
//load weekly diet plan from a file
void FitnessWrapper::loadWeeklyExerciseplan(fstream &exercisePlan)
{

	for (int counter = 0; counter < 7; counter++)
		loaddailyExerciseplan(exercisePlan,this->userExercisePlan[counter]);

	cout << "Done reading weekly exercise plans from file." << endl
		<< "Returning to Main Menu." << endl;

	//house keeping
	system("pause");
	system("cls");
}

void FitnessWrapper::loaddailyExerciseplan(fstream &exercisePlan, ExercisePlan &day)
{
	exercisePlan >> day;
}


//write weekly diet plan to file
void FitnessWrapper::storeWeeklyDietPlan(fstream &dietFile)
{

	for (int counter = 0; counter < 7; counter++)
		storeDailyDietPlan(dietFile, this->userDietPlan[counter]);

	cout << "Done storing diet weekly plan to file." << endl
		 << "Returning to Main Menu" << endl;

	//housekeeping
	system("pause");
	system("cls");
}

//write weekly diet plan to file
void FitnessWrapper::storeWeeklyExercisePlan(fstream &exerciseFile)
{
	for (int counter = 0; counter < 7; counter++)
		storeDailyExercisePlan(exerciseFile, counter);
		
	cout << "Done storing exercise weekly plan to file." << endl
		 << "Returning to Main Menu" << endl;

	//housekeeping
	system("pause");
	system("cls");
}

void FitnessWrapper::storeDailyDietPlan(fstream &dietFile, DietPlan &day)
{
	dietFile << day;
}

void FitnessWrapper::storeDailyExercisePlan(fstream &exerciseFile, int day)
{
	exerciseFile << this->userExercisePlan[day];
}