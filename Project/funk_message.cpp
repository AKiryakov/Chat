#include <string>
#include <iostream>
#include "funk_message.h"
#include <vector>
using namespace std;

void funk_sent_message(vector<Message>& M_V_C, string login_user, string name_current_reciption, string message_current)
{
    M_V_C.push_back(Message(login_user, name_current_reciption, message_current)); // добавляем новый объект Message
}
