#include "warehouseType.h"



warehouseType::warehouseType()
{
	indexSelection = 0;
	exitSwitch = false;
}

bool warehouseType::warehouseMenu(bool &restart)
{
	menu myWaresMenu("warehouseMenu.txt");

	while (!exitSwitch)
	{

		myWaresMenu.startMenu();
		indexSelection = myWaresMenu.getIndex();

		switch (indexSelection)
		{
		case 0:
			checkInventory(); 
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

void warehouseType::checkInventory()
{
	system("cls");
	cout << "You Checked Inventory" << endl;
	Sleep(2000);
	system("cls");
}


warehouseType::~warehouseType()
{
}
