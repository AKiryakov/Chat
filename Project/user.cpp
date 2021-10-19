#include <string>
#include <iostream>
#include <vector>
#include "user.h"
using namespace std;

string User::getUserLogin() const
{
	return _login;
}

void User::setUserLogin(string login)
{
	_login = login;
}

string User::getUserName() const
{
	return _name;
}

void User::setUserName(string name)
{
	_name = name;
}

string User::getUserPassword() const
{
	return _password;
}

void User::setUserPassword(string password)
{
	_password = password;
}
