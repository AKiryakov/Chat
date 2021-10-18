#include <string>
#include <iostream>
#include "funk_user.h"
#include <vector>
using namespace std;

void funk_registr_user(vector<User>& U_V_C, string user_login_, string user_password_)
{
    U_V_C.push_back(User()); // добавляем новый объект User в вектор
    U_V_C[U_V_C.size() - 1].setUserLogin(user_login_); // логин нового пользователя
    U_V_C[U_V_C.size() - 1].setUserPassword(user_password_); // пароль нового пользователя
    cout << "Пользователь " << user_login_ << " зарегистрирован" << endl << endl;
}
