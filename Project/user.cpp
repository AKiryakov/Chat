#include <string>
#include <iostream>
#include <vector>
#include "User.h"
using namespace std;

string User::getUserLogin()
{
	return _login;
}

void User::setUserLogin(string login)
{
	_login = login;
}

string User::getUserPassword()
{
	return _password;
}

void User::setUserPassword(string password)
{
	_password = password;
}
