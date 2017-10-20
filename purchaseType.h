#pragma once
#include"menu.h"

class purchaseType
{
public:
	purchaseType();
	bool purchaseMenu(bool&);
	void buy();
	~purchaseType();

private:
	int indexSelection;
	bool exitSwitch;
};
