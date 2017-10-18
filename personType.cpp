#include "personType.h"



personType::personType()
{
	string firstName = " ";
	string lastName = " ";
}

personType::personType(string first, string last)
{
	setName(first, last);
}


void personType::setName(string first, string last)
{
	firstName = first;
	lastName = last;
}

void personType::setLastName(string last)
{
	lastName = last;
}

void personType::setFirstName(string first)
{
	firstName = first;
}


string personType::getFirstName()
{
	return firstName;
}


string personType::getLastName()
{
	return lastName;
}

personType::~personType()
{
}
