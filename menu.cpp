#include "menu.h"



menu::menu()
{
	lineCount = 0;
	menuIndex = 0;
}

menu::menu(string file)
{
	lineCount = 0;
	string line;
	ifstream inFile;

	inFile.open(file);
	while (!inFile.eof())
	{
		getline(inFile, line);
		menuList.push_back(line);
		lineCount++;
	}
	inFile.close();

}

void menu::startMenu()
{
	for (int i = 0; i < lineCount; i++)
	{
		cout << i + 1 << ": " << menuList[i] << endl;
	}


	bool isValid = false;
	while (!isValid)
	{
		cout << "Please enter the number of the option you want: ";
		cin >> menuIndex;
		if (cin.fail())
		{
			cin.clear();
			cin.ignore();
			cout << "That is not a valid selection!" << endl << endl;

		}
		else if (menuIndex <= lineCount && menuIndex > 0)
		{
			isValid = true;
		}
		else
		{
			cout << "That is not a valid selection!" << endl << endl;

		}
	}
	//cout << "You selected option " << menuIndex << endl;
	menuIndex--;
}

int menu::getIndex()
{
	return menuIndex;
}

int menu::getCount()
{
	return lineCount;
}


menu::~menu()
{
}
