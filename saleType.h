#pragma once
#include"menu.h"

class saleType
{
public:
	saleType();
	bool salesMenu(bool&);
	void makeSale();
	~saleType();

private:
	int indexSelection;
	bool exitSwitch;
};
