#include <string>
#include <iostream>
#include "funk_user.h"
#include <vector>
using namespace std;

void funk_registr_user(vector<User>& U_V_C, string login_user, string name_user, string password_user)
{
    U_V_C.push_back(User()); // добавляем новый объект User в вектор
    U_V_C[U_V_C.size() - 1].setUserLogin(login_user); // логин нового пользователя
    U_V_C[U_V_C.size() - 1].setUserName(name_user); // логин нового пользователя
    U_V_C[U_V_C.size() - 1].setUserPassword(password_user); // пароль нового пользователя
    cout << "Пользователь " << name_user << " зарегистрирован" << endl << endl;
}
