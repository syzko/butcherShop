#include "saleType.h"



saleType::saleType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool saleType::salesMenu(bool &restart)
{
	menu mySalesMenu("salesMenu.txt");

	while (!exitSwitch)
	{

		mySalesMenu.startMenu();
		indexSelection = mySalesMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			makeSale();
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

void saleType::makeSale()
{
	system("cls");
	cout << "You Made a Sale" << endl;
	Sleep(2000);
	system("cls");
}


saleType::~saleType()
{
}
