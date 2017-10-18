#include "login.h"

login::login()
{

}

void login::prompt()
{
	system("cls");
	cout << "Username: ";
	cin >> username;
	cout << "Password: ";
	cin >> password;
}


string login::getUsername()
{
	return username;
}

string login::getPassword()
{
	return password;
}

login::~login()
{
}
