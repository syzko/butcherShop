/*////////////////////////////////////////
//										//
//	Created By: Steven Bensinger		//
//										//
//	Date Created: 10/12/2017			//
//	Last Modified: 10/20/2017			//
//										//
//	 									//
////////////////////////////////////////*/


#include<iostream>
#include<fstream>
#include<string>
#include<windows.h>
#include"personType.h"
#include"employeeType.h"
#include"adminType.h"
#include"hrType.h"
#include"saleType.h"
#include"purchaseType.h"
#include"accountingType.h"
#include"warehouseType.h"
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

	menu myLoginMenu("loginMenu.txt");//menu object to execute login menu
	login myLogin;//login object to execute login functions
	int indexSelection;//variable to execute menu option
	vector<vector<string>> user = userTable("credentials.txt");//array set equal to loaded user table
	vector<string> departments = deptTable("deptList.txt");//aaray set equal to department table
	
	employeeType curEmployee;//employee object to represent current user
	
	string department;//employee attribute
	string username;//employee attribute
	string password;//employee attribute

	adminType administrator;//object with employee department atrribute = Admin
	hrType hr;//object with employee department atrribute = HR
	saleType sales;//object with employee department atrribute = Sales
	purchaseType purchasing;//object with employee department atrribute = Purchasing
	accountingType accounting;//object with employee department atrribute = Accounting
	warehouseType warehouse;//object with employee department atrribute = Warehouse 


	bool exitSwitch1 = false;//variable to exit loop 1
	bool exitSwitch2 = false;//variable to exit loop 2
	bool restart = false;//variable to restart after logout
	
	
	while (!exitSwitch1)//loop to execute login functions
	{
		myLoginMenu.startMenu();
		indexSelection = myLoginMenu.getIndex();//sets index selection from login class
		bool userFound = false;//exit validation loop

		switch (indexSelection)//executes user selections
		{
		case 0://login
			myLogin.prompt();//execute login prompt
			username = myLogin.getUsername();//sets attribute from login class
			password = myLogin.getPassword();//sets attribute from login class
			while (!userFound)//loop to validate user
			{
				for (int i = 0; i < user.size(); i++)//search user list and compare to attributes
				{
					for (int j = 0; j < user[i].size(); j++)
					{
						if (user[i][j] == username && user[i][j + 1] == password)
						{
							curEmployee.setCredentials(user[i][0], user[i][1], user[i][2], user[i][3], user[i][4]);
							userFound = true;//exit loop
						}
					}
				}
				if (userFound == false)//restart login process
				{
					cout << endl << "User not found! Please Retry." << endl;
					Sleep(2000);
					myLogin.prompt();
					username = myLogin.getUsername();
					password = myLogin.getPassword();
				}
			}//end validation loop
			exitSwitch1 = true;//exit loop 1
			system("cls");
			break;
		case 1://exit
			exitSwitch1 = true;//exit loop 1
			exitSwitch2 = true;//prevent loop 2
			system("cls");
			break;
		}//end switch user selection
	}//end login loop

	while (!exitSwitch2)//loop to execute department classes based on login
	{
		for (int i = 0; i < departments.size(); i++)//search and find department of user
		{
			if (curEmployee.getDepartment() == departments[i])
				indexSelection = i;//set department index
		}

		switch (indexSelection)//execute department
		{
		case 0:
			administrator.adminMenu(restart);
			exitSwitch2 = true;
			break;
		case 1:
			hr.hrMenu(restart);
			exitSwitch2 = true;
			break;
		case 2:
			sales.salesMenu(restart);
			exitSwitch2 = true;
			break;
		case 3:
			purchasing.purchaseMenu(restart);
			exitSwitch2 = true;
			break;
		case 4:
			accounting.accountMenu(restart);
			exitSwitch2 = true;
			break;
		case 5:
			warehouse.warehouseMenu(restart);
			exitSwitch2 = true;
			break;

		}

		if (restart == true)//logout
		{
			goto restartAll;
		}
	
	}//end execution loop

	//end program
	cout << endl << endl;
	system("pause");
	return 0;
}
