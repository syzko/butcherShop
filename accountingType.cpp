#include "accountingType.h"



accountingType::accountingType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool accountingType::accountMenu(bool &restart)
{
	menu myAccountMenu("accountMenu.txt");

	while (!exitSwitch)
	{

		myAccountMenu.startMenu();
		indexSelection = myAccountMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			checkBalance();
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

void accountingType::checkBalance()
{
	system("cls");
	cout << "You Checked the Balance" << endl;
	Sleep(2000);
	system("cls");
}


accountingType::~accountingType()
{
}
