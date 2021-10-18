#include <string>
#include <iostream>
#include "funk_message.h"
#include <vector>
using namespace std;

void funk_sent_message(vector<Message>& M_V_C, string user_login_, string current_reciption_name_, string current_message_, bool all_or_personal)
{
    M_V_C.push_back(Message()); // добавляем новый объект Message
    int a = M_V_C.size() - 1;
    M_V_C[a].setSender(user_login_); //отправитель
    M_V_C[a].setRecinient(current_reciption_name_); // получатель
    if (all_or_personal) // если all_or_personal = 1, отправляем личное сообщение
    {
        M_V_C[a].setMessage("Вам сообщение от " + user_login_ + ": " + current_message_); // текст сообщения
        cout << "Ваше сообщение отправлено" << endl << endl;
    }
    else // иначе отправляем сообщение всем
    {
        M_V_C[a].setMessage("сообщение всем от " + user_login_ + ": " + current_message_);
    }
}
