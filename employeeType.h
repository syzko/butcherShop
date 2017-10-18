#pragma once
#include<vector>
#include<iomanip>
#include<fstream>
#include "personType.h"
class employeeType :public personType
{
public:
	employeeType();
	employeeType(string first, string last, string department, string id, string pw);//constructor w/ parameters
	void setCredentials(string first, string last, string department, string id, string pw);//reads in & sets information for logged in user
	
	string getDepartment() const;//returns department
	string getLogin() const;//returns login id
	string getPassword() const;//returns password
	
	~employeeType();

private:
	string dept;
	string login;
	string password;
};
