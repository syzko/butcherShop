#pragma once
#include<string>
#include<iostream>

using namespace std;

class personType
{
public:
	personType();
	personType(string first, string last);//constructor /w parameters
	void setName(string first, string last);//sets full name 
	void setLastName(string last);// sets last name
	void setFirstName(string first);// sets first name
	string getFirstName();// returns first name
	string getLastName();// returns last name

	~personType();

private:
	string firstName;
	string lastName;

};
