#include <string>
#include <iostream>
#include <vector>
#include "message.h"
using namespace std;

string Message::getMessage() const
{
	return _message;
}

void Message::setMessage(string message)
{
	_message = message;
}

string Message::getSender() const
{
	return _sender;
}

void Message::setSender(string sender)
{
	_sender = sender;
}

string Message::getRecinient() const
{
	return _recinient;
}

void Message::setRecinient(string recinient)
{
	_recinient = recinient;
}
