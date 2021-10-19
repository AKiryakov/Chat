#include <string>
#include <iostream>
#include "funk_user.h"
#include <vector>
using namespace std;

void funk_registr_user(vector<User>& U_V_C, string login_user, string name_user, string password_user)
{
    U_V_C.push_back(User(login_user, name_user, password_user)); // добавляем новый объект User в вектор
    cout << "Пользователь " << name_user << " зарегистрирован" << endl << endl;
}
