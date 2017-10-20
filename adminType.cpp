#include "adminType.h"



adminType::adminType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool adminType::adminMenu(bool &restart)
{
	menu myAdminMenu("adminMenu.txt");

	while (!exitSwitch)
	{

		myAdminMenu.startMenu();
		indexSelection = myAdminMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			addUser();
			break;
		case 1:
			removeUser();
			break;
		case 2:
			addDepartment();
			break;
		case 3:
			removeDepartment();
			break;
		case 4:
			printUsers();
			break;
		case 5:
			printDepts();
			break;
		case 6:
			system("cls");
			cout << "Logging Out";
			Sleep(2000);
			system("cls");
			restart = true;
			exitSwitch = true;
			break;
		case 7:
			system("cls");
			cout << "Exiting" << endl;
			Sleep(2000);
			system("cls");
			exitSwitch = true;
			break;
		}//end switch
	}//end while
	return restart;
}

void adminType::addUser()
{
	system("cls");
	cout << "You Added a New User" << endl;
	Sleep(2000);
	system("cls");
}

void adminType::removeUser()
{
	system("cls");
	cout << "You Removed a User" << endl;
	Sleep(2000);
	system("cls");
}

void adminType::addDepartment()
{
	system("cls");
	cout << "You Added a Department" << endl;
	Sleep(2000);
	system("cls");
}

void adminType::removeDepartment()
{
	system("cls");
	cout << "You Removed a Department" << endl;
	Sleep(2000);
	system("cls");
}


void adminType::printUsers()
{
	system("cls");
	cout << "You Printed the Users" << endl;
	Sleep(2000);
	system("cls");
}

void adminType::printDepts()
{
	system("cls");
	cout << "You Printed the Departments" << endl;
	Sleep(2000);
	system("cls");
}

adminType::~adminType()
{
}
