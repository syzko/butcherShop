#pragma once
#include"menu.h"

class hrType
{
public:
	hrType();
	bool hrMenu(bool&);
	void payroll();
	~hrType();

private:
	int indexSelection;
	bool exitSwitch;
};
