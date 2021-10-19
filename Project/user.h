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
	string getUserLogin() const;
	void setUserName(string name);
	string getUserName() const;
	void setUserPassword(string password);
	string getUserPassword() const;

private:
	string _login; // переменная с логином
	string _name;
	string _password; // переменная с паролем
};
