#include "purchaseType.h"



purchaseType::purchaseType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool purchaseType::purchaseMenu(bool &restart)
{
	menu myPurchaseMenu("purchaseMenu.txt");

	while (!exitSwitch)
	{

		myPurchaseMenu.startMenu();
		indexSelection = myPurchaseMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			buy();
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

void purchaseType::buy()
{
	system("cls");
	cout << "You Made a Purchase" << endl;
	Sleep(2000);
	system("cls");
}


purchaseType::~purchaseType()
{
}
