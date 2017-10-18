#pragma once
#include<string>
#include<iostream>

using namespace std;

class login
{
public:
	login();
	void prompt();//prompts the user and stores input
	string getUsername();//returns user name
	string getPassword();//returns password
	~login();

private:
	string username;
	string password;
};
