#pragma once
#include <string>
#include <vector>
using namespace std;

class User
{
public:
	User() = default; // конструктор по умолчанию
	~User() = default; // деструктор

	User(const string& login_user, const string& name_user, const string& password_user) : _login(login_user), _name(name_user), _password(password_user){} // конструктор с параметрами

	void setUserLogin(string login);
	string getUserLogin() const;
	void setUserName(string name);
	string getUserName() const;
	void setUserPassword(string password);
	string getUserPassword() const;

private:
	string _login; // переменная с логином
	string _name; // переменная с именем
	string _password; // переменная с паролем
};
