/*////////////////////////////////////////
//										//
//	Created By: Steven Bensinger		//
//										//
//	Date Created: 10/12/2017			//
//	Last Modified: 10/18/2017			//
//										//
//	 									//
////////////////////////////////////////*/


#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include"personType.h"
#include"employeeType.h"
#include"menu.h"
#include"login.h"

using namespace std;
const int NUM_OF_ATTRIBUTES = 5;

vector<vector<string>> userTable(string file)
{


	int lineCount = 0;
	string line;
	ifstream inFile;

	inFile.open(file);
	while (!inFile.eof())
	{
		getline(inFile, line);
		lineCount++;
	}
	inFile.close();

	vector<vector<string>> userArray(lineCount, vector<string>(NUM_OF_ATTRIBUTES));

	inFile.open(file);
	for (int i = 0; i < lineCount; i++)
	{
		for (int j = 0; j < NUM_OF_ATTRIBUTES; j++)
		{
			inFile >> userArray[i][j];
		}
	}

	return userArray;
}


int main()
{
restartAll:

	menu myLoginMenu("loginMenu.txt");
	menu myAdminMenu("adminMenu.txt");
	login myLogin;
	int indexSelection;
	vector<vector<string>> user = userTable("credentials.txt");
	string department;
	string username;
	string password;
	bool exitSwitch1 = false;
	bool exitSwitch2 = false;
	employeeType curEmployee;

	while (!exitSwitch1)
	{
		myLoginMenu.startMenu();
		indexSelection = myLoginMenu.getIndex();
		bool userFound = false;

		switch (indexSelection)
		{
		case 0:
			myLogin.prompt();
			username = myLogin.getUsername();
			password = myLogin.getPassword();
			while (!userFound)
			{
				for (int i = 0; i < user.size(); i++)
				{
					for (int j = 0; j < user[i].size(); j++)
					{
						if (user[i][j] == username && user[i][j + 1] == password)
						{
							curEmployee.setCredentials(user[i][0], user[i][1], user[i][2], user[i][3], user[i][4]);
							userFound = true;
						}
					}
				}
				if (userFound == false)
				{
					cout << endl << "User not found! Please Retry." << endl;
					Sleep(2000);
					myLogin.prompt();
					username = myLogin.getUsername();
					password = myLogin.getPassword();
				}
			}
			exitSwitch1 = true;
			system("cls");
			break;
		case 1:
			exitSwitch1 = true;
			exitSwitch2 = true;
			break;
		}
	}

	while (!exitSwitch2)
	{
		system("cls");
		cout << "Hello, " << curEmployee.getFirstName() << "! What would you like to do?" << endl << endl;
		myAdminMenu.startMenu();
		indexSelection = myAdminMenu.getIndex();
		
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
