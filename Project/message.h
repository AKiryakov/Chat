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
	string getMessage();

	void setSender(string sender);
	string getSender();

	void setRecinient(string recinient);
	string getRecinient();


private:
	string _message;
	string _sender;
	string _recinient;
};
