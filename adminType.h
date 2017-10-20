#pragma once
#include"menu.h"

class adminType
{
public:
	adminType();
	bool adminMenu(bool&);
	void addUser();
	void removeUser();
	void addDepartment();
	void removeDepartment();
	void printUsers();
	void printDepts();

	~adminType();

private:
	int indexSelection;
	bool exitSwitch;
};
