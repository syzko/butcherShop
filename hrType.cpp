#include "hrType.h"



hrType::hrType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool hrType::hrMenu(bool &restart)
{
	menu myHrMenu("hrMenu.txt");

	while (!exitSwitch)
	{

		myHrMenu.startMenu();
		indexSelection = myHrMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			payroll();
			break;
		case 1:
			system("cls");
			cout << "Logging Out";
			Sleep(2000);
			system("cls");
			restart = true;
			exitSwitch = true;
			break;
		case 2:
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

void hrType::payroll()
{
	system("cls");
	cout << "You Did Payroll" << endl;
	Sleep(2000);
	system("cls");
}


hrType::~hrType()
{
}
