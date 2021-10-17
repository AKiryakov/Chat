#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User() = default;
	~User() = default;

	void setUserLogin(string login);
	string getUserLogin();
	void setUserPassword(string password);
	string getUserPassword();

private:
	string _login;
	string _password;
};
