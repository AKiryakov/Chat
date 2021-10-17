#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "user.h"
#include "message.h"
#include "exception.h"

using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);
    vector<User> Users_Vector_Class;
    vector<Message> Message_Vector_Class;
    string user_name, user_password, user_confirm_password, current_message, current_reciption_name, flag_response;// имя текущего пользователя, пароль, подтверждение, текст сообщения, имя получателя сообщения, переменная для определения кому отвечать

    int num, i, j, k;
    bool authorization, name_free, sent_nosuccessfully, finish_program = 1; // для логики факта авторизации, свободного имени в чате, факта отправки сообщения.
    while (finish_program)
    {
        cout << "выберете действие:" << endl;// основное меню
        cout << "1. Регистрация пользователя" << endl;
        cout << "2. Авторизация пользователя и работа в чате" << endl;
        //cout << "3. Показать пользователи и пароли" << endl; // это на время отладки, в финальной версии удалим
        cout << "Для выхода из программы нажмите любую другую кнопку" << endl << endl;
        cin >> num;
        cin.ignore();

        switch (num) // выбор действий через оператор switch
        {
        case 1:
            cout << "Введите ваше имя" << endl;
            getline(cin, user_name);
            if (Users_Vector_Class.size() == 0) // если пользователь первый, то не проверяем на уникальность
            {
                cout << "Придумайте Ваш пароль" << endl;
                getline(cin, user_password);

                // проверка совпадения паролей закомментирована на период отладки

                cout << "Повторите пароль еще раз" << endl;
                getline(cin, user_confirm_password);

                if (user_password == user_confirm_password)
                {
                    Users_Vector_Class.push_back(User()); // добавляем пользователя в вектор
                    Users_Vector_Class[0].setUserLogin(user_name);
                    Users_Vector_Class[0].setUserPassword(user_password);


                    cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                }
                else
                {
                    cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                }
            }
            else // если в векторе имен есть хотя бы одна запись, проверяем следующих пользователей на уникальность
            {
                name_free = true;
                try 
                {
                for (i = 0; i < Users_Vector_Class.size(); ++i)
                {
                    if (user_name == Users_Vector_Class[i].getUserLogin())
                    {
                        name_free = false;
                        break;
                    }
                }
                }

                catch (exception& error) // отработка пойманных исключений
                {
                    cout << error.what();
                }

                if (name_free) // если имя совободно, то приступаем к вводу пароля
                {
                    cout << "Придумайте Ваш пароль" << endl;
                    getline(cin, user_password);

                    // проверка совпадения паролей закомментирована на период отладки
                    cout << "Повторите пароль еще раз" << endl;
                    getline(cin, user_confirm_password);

                    if (user_password == user_confirm_password)
                    {

                        Users_Vector_Class.push_back(User()); // добавляем пользователя в вектор
                        Users_Vector_Class[Users_Vector_Class.size() - 1].setUserLogin(user_name);
                        Users_Vector_Class[Users_Vector_Class.size() - 1].setUserPassword(user_password);

                        cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                        break;
                    }
                    else
                    {
                        cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                    }
                }
                else
                {
                    cout << "Имя уже используется, придумайте другое" << endl << endl;
                }
            }
            break;
        case 2:
            // авторизация
            cout << "Введите Ваше имя:" << endl;
            getline(cin, user_name);

            cout << "Введите Ваш пароль:" << endl;
            getline(cin, user_password);

            authorization = false;
            for (i = 0; i < Users_Vector_Class.size(); ++i) // перебираем введенные имя и пароль в векторах
            {
                if (user_name == Users_Vector_Class[i].getUserLogin() && user_password == Users_Vector_Class[i].getUserPassword()) // если нашли соответствие авторизация прошла
                {
                    cout << "Добро пожаловать " << user_name << endl << endl;
                    authorization = true; //если имя и пароль верные, переменная authorization = true
                    break;
                }
            }
            if (!authorization)
            {
                cout << "Ошибка имени пользователя или пароля" << endl << endl;
            }
            while (authorization)
            {
                cout << "выберете действие:" << endl;// основное меню
                cout << "1. Отправить сообщение всем пользователям" << endl;
                cout << "2. Отправить личное сообщение" << endl;
                cout << "3. Получить сообщение" << endl; // 
                //cout << "4. показать вектора" << endl; //
                cout << "Для выхода в предыдущее меню нажмите любую другую кнопку" << endl << endl;
                cin >> num;
                cin.ignore();
                switch (num) // выбор действий через оператор switch
                {
                case 1: // отправка сообщений всем пользователям
                    cout << "введите сообщение" << endl;
                    getline(cin, current_message);
                    for (i = 0; i < Users_Vector_Class.size(); ++i) // перебираем вектор имен
                    {
                        if (user_name != Users_Vector_Class[i].getUserLogin()) // записываем во все вектора (отправитель, получатель, текст) значения, кроме случая равенства имени текущего пользователя и пользователя из вектора имен (чтобы не отправлять сообщение самому себе)
                        {
                            Message_Vector_Class.push_back(Message());
                            int a = Message_Vector_Class.size() - 1;
                            Message_Vector_Class[a].setSender(user_name);
                            Message_Vector_Class[a].setRecinient(Users_Vector_Class[i].getUserLogin());
                            Message_Vector_Class[a].setMessage("сообщение всем от " + user_name + ": " + current_message);
                        }
                    }
                    cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;

                    break;
                case 2:
                    // отправка сообщения конкретному пользователю
                    sent_nosuccessfully = 1; // значение переменной будет истина, пока пользователь не введет правильно имя получателя
                    cout << "Сейчас в чате зарегистрированы:" << endl; // отображаем список зарегистрированных пользователей
                    for (i = 0; i < Users_Vector_Class.size(); ++i)
                    {
                        cout << Users_Vector_Class[i].getUserLogin() << "; ";
                    }
                    while (sent_nosuccessfully) // бесконечный цикл, пока не введем точное имя получателя
                    {
                        cout << endl << "кому отправляем сообщение?" << endl;
                        getline(cin, current_reciption_name);

                        for (i = 0; i < Users_Vector_Class.size(); ++i) // перебираем введенное имя среди зарегистрированных пользователей
                        {
                            if (current_reciption_name == Users_Vector_Class[i].getUserLogin()) // если находим, просим ввести текст сообщения
                            {
                                cout << "введите сообщение" << endl;
                                getline(cin, current_message);
                                Message_Vector_Class.push_back(Message());
                                int a = Message_Vector_Class.size() - 1;
                                Message_Vector_Class[a].setSender(user_name);
                                Message_Vector_Class[a].setRecinient(current_reciption_name);
                                Message_Vector_Class[a].setMessage("Вам сообщение от " + user_name + ": " + current_message);
                                cout << "Ваше сообщение отправлено" << endl << endl;
                                sent_nosuccessfully = 0; // устанавливаем флаг в положение "сообщение отправлено"
                            }
                        }
                        if (sent_nosuccessfully) // если имя получателя в списке не нашли, сообщаем об этом
                        {
                            cout << "пользователь с именем " << current_reciption_name << " в чате не зарегистрирован" << endl << endl;
                        }
                    }
                    break;

                case 3: // получаем сообщения
                    j = Message_Vector_Class.size();
                    for (i = 0; i < j; ++i)
                    {
                        if (user_name == Message_Vector_Class[i].getRecinient()) // если находим свое имя в векторе получателей, 
                        {
                            cout << Message_Vector_Class[i].getMessage() << endl; // выводим на экран сообщение
                            cout << "Для ответа пользователю '" << Message_Vector_Class[i].getSender() << "' лично нажмите 'л', для ответа в общий чат нажмите 'в'" << endl; // предлагаем ответить лично или всем
                            cin >> flag_response; // вводим с клавиатуры, если:
                            if (flag_response == "л") // "л" - отпраляем личный ответ
                            {
                                cin.ignore();
                                cout << "введите текст сообщения:" << endl;
                                getline(cin, current_message);
                                Message_Vector_Class.push_back(Message());
                                int a = Message_Vector_Class.size() - 1;
                                Message_Vector_Class[a].setSender(user_name);
                                Message_Vector_Class[a].setRecinient(Message_Vector_Class[i].getSender());
                                Message_Vector_Class[a].setMessage("Вам сообщение от " + user_name + ": " + current_message);
                                cout << "Ваше сообщение отправлено" << endl << endl;
                            }
                            if (flag_response == "в") // если "в" - то отвечаем всем
                            {
                                cin.ignore();
                                cout << "введите текст сообщения:" << endl;
                                getline(cin, current_message);
                                for (k = 0; k < Users_Vector_Class.size(); ++k)
                                {
                                    if (user_name != Users_Vector_Class[k].getUserLogin())
                                    {

                                        Message_Vector_Class.push_back(Message());
                                        int a = Message_Vector_Class.size() - 1;
                                        Message_Vector_Class[a].setSender(user_name);
                                        Message_Vector_Class[a].setRecinient(Users_Vector_Class[k].getUserLogin());
                                        Message_Vector_Class[a].setMessage("сообщение всем от " + user_name + ": " + current_message);
                                    }
                                }
                                cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;
                            }
                            Message_Vector_Class.erase(Message_Vector_Class.begin() + i); // удаляем из вектора прочитанное сообщение
                            --j; // длина векторов стала меньше на 1, соответственно уменьшаем на 1 количество проходов
                            --i; // мы только что удалили текущие значения в векторах имя, отправитель, получатель, значит с этим же индексом хранится уже новое сообщение, его будем проверять на следующем проходе
                        }
                    }
                    break;
                    //case 4: // для отладки
                    //    for (i = 0; i < Message_Vector_Class.size(); ++i)
                    //    {
                    //        cout << "отправитель " << Message_Vector_Class[i].getSender() << endl;
                    //        cout << "получатель " << Message_Vector_Class[i].getRecinient() << endl;
                    //        cout << "сообщение: " << Message_Vector_Class[i].getMessage() << endl;

                    //    }
                    //    break;

                default:
                    if ((num > 3) | (num < 1)) // условие выхода в предыдущее меню
                    {
                        authorization = false;
                    }

                    break;
                }
            }
            break;

            //case 3:
            //    for (i = 0; i < Users_Vector_Class.size(); i++)
            //    {
            //        cout << Users_Vector_Class[i].getUserLogin() << endl;

            //        cout << Users_Vector_Class[i].getUserPassword() << endl;
            //    }
            //    break;
        default:
            if ((num > 2) | (num < 1)) // условие выхода из программы
            {
                finish_program = 0;
            }
            break;
        }
    }
    return 0;
}