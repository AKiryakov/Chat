#pragma once
#include <string>
#include <vector>
using namespace std;

class Message
{
public:
	Message() = default; // конструктор по умолчанию
	~Message() = default; // деструктор


	Message (const string& login_user, const string& name_current_reciption, const string& message_current) : _sender(login_user), _recinient(name_current_reciption), _message(message_current) {} // конструктор с параметрами


	void setMessage(string message);
	string getMessage() const;

	void setSender(string sender);
	string getSender() const;

	void setRecinient(string recinient);
	string getRecinient() const;


private:
	string _sender; // логин отправителя
	string _recinient; // логин получателя
	string _message; // текст сообщения
};
