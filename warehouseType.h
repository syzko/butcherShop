#pragma once
#include"menu.h"

class warehouseType
{
public:
	warehouseType();
	bool warehouseMenu(bool &);
	void checkInventory();
	~warehouseType();

private:
	int indexSelection;
	bool exitSwitch;
};
