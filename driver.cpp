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

const int NUM_OF_ATTRIBUTES = 5;//constant for userTable size

//loads a list of possible users from a text file into a 2D vector 
vector<vector<string>> userTable(string file)
{


	int lineCount = 0; //variable used to set userTable size 
	string line; //line to be counted
	ifstream inFile;//variable to open desired file

	inFile.open(file);

	//gets number of lines contained by the inFile
	while (!inFile.eof())
	{
		getline(inFile, line);
		lineCount++;
	}
	inFile.close();

	vector<vector<string>> userArray(lineCount, vector<string>(NUM_OF_ATTRIBUTES));//declaring userTable

	inFile.open(file);
	
	//fills the 2D vector with all users and their attributes
	for (int i = 0; i < lineCount; i++)
	{
		for (int j = 0; j < NUM_OF_ATTRIBUTES; j++)
		{
			inFile >> userArray[i][j];
		}
	}

	return userArray;
}//end userTable

 //loads a list of possible departments from a text file into a vector 
vector<string> deptTable(string file)
{

	int lineCount = 0; //variable used to set deptTable size 
	string line; //line to be counted
	ifstream inFile;//variable to open desired file

	inFile.open(file);

	//gets number of lines contained by the inFile
	while (!inFile.eof())
	{
		getline(inFile, line);
		lineCount++;
	}
	inFile.close();

	vector<string> deptArray(lineCount);//declaring deptTable

	inFile.open(file);

	//fills the vector with the departments
	for (int i = 0; i < lineCount; i++)
	{
		inFile >> deptArray[i];
	}
	

	return deptArray;
}//end deptTable


int main()
{
restartAll: 

	menu myLoginMenu("loginMenu.txt");
	login myLogin;
	int indexSelection;
	vector<vector<string>> user = userTable("credentials.txt");
	vector<string> departments = deptTable("deptList.txt");
	
	employeeType curEmployee;
	string department;
	string username;
	string password;
	
	bool exitSwitch1 = false;
	bool exitSwitch2 = false;
	

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
			system("cls");
			break;
		}
	}

	while (!exitSwitch2)
	{
		for (int i = 0; i < departments.size(); i++)
		{
			if (curEmployee.getDepartment() == departments[i])
				indexSelection = i;
		}
		
		switch (indexSelection)
		{
		case 0:
			cout << "Admin" << endl;
			break;
		case 1:
			cout << "HR" << endl;
			break;
		case 2:
			cout << "Sales" << endl;
			break;
		case 3:
			cout << "Purchasing" << endl;
			break;
		case 4:
			cout << "Accounting" << endl;
			break;
		case 5:
			cout << "Warehouse" << endl;
			break;
			

		}
		
		exitSwitch2 = true;
	}

	cout << endl << endl;
	system("pause");
	return 0;
}
