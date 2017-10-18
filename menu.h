#pragma once
#include<iostream>
#include<string>
#include<vector>
#include<fstream>

using namespace std;

class menu
{
public:
	menu();
	menu(string);//constructor with parameters
	void startMenu();//builds & activates a menu, gets menu choice for use by the driver
	int getIndex();//returns index number
	int getCount();//returns the number of menu options
	~menu();
private:
	int menuIndex;
	int lineCount;
	vector<string> menuList;
};
