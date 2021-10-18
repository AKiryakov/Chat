#pragma once
#include <string>
#include <vector>
using namespace std;

class Message
{
public:
	Message() = default;
	~Message() = default;

	void setMessage(string message);
	string getMessage() const;

	void setSender(string sender);
	string getSender() const;

	void setRecinient(string recinient);
	string getRecinient() const;


private:
	string _message; // текст сообщения
	string _sender; // логин отправителя
	string _recinient; // логин получателя
};
