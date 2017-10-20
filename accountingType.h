#pragma once
#include"menu.h"

class accountingType
{
public:
	accountingType();
	bool accountMenu(bool&);
	void checkBalance();
	~accountingType();

private:
	int indexSelection;
	bool exitSwitch;
};
