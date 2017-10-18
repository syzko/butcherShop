#include "employeeType.h"



employeeType::employeeType()
{
	dept = " ";
	login = " ";
	password = " ";
}

employeeType::employeeType(string first, string last, string department, string id, string pw)
{
	personType::setName(first, last);
	dept = department;
	login = id;
	password = pw;
}

void employeeType::setCredentials(string first, string last, string department, string id, string pw)
{
	personType::setName(first, last);
	dept = department;
	login = id;
	password = pw;
}

string employeeType::getDepartment() const
{
	return dept;
}

string employeeType::getLogin() const
{
	return login;
}

string employeeType::getPassword() const
{
	return password;
}


employeeType::~employeeType()
{
}
