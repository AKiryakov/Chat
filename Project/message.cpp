#include <string>
#include <iostream>
#include <vector>
#include "Message.h"
using namespace std;

string Message::getMessage()
{
	return _message;
}

void Message::setMessage(string message)
{
	_message = message;
}

string Message::getSender()
{
	return _sender;
}

void Message::setSender(string sender)
{
	_sender = sender;
}

string Message::getRecinient()
{
	return _recinient;
}

void Message::setRecinient(string recinient)
{
	_recinient = recinient;
}
