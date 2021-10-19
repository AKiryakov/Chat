#include <string>
#include <iostream>
#include "funk_message.h"
#include <vector>
using namespace std;

void funk_sent_message(vector<Message>& M_V_C, string login_user, string name_current_reciption, string message_current, bool all_or_personal)
{
    M_V_C.push_back(Message()); // добавляем новый объект Message
    int a = M_V_C.size() - 1;
    M_V_C[a].setSender(login_user); //отправитель
    M_V_C[a].setRecinient(name_current_reciption); // получатель
    if (all_or_personal) // если all_or_personal = 1, отправляем личное сообщение
    {
        M_V_C[a].setMessage("Вам сообщение от " + login_user + ": " + message_current); // текст сообщения
        cout << "Ваше сообщение отправлено" << endl << endl;
    }
    else // иначе отправляем сообщение всем
    {
        M_V_C[a].setMessage("сообщение всем от " + login_user + ": " + message_current);
    }
}
