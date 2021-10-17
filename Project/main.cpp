#include <string>
#include <iostream>
#include <vector>
#include <windows.h>
#include "Header.h"
using namespace std;

int main()
{
    setlocale(LC_ALL, "Russian");
    SetConsoleOutputCP(1251);
    SetConsoleCP(1251);

    vector<string> name; // в векторе "name" храним имена зарегистрированных пользователей
    vector<string> password; // в векторе password храним пароли пользователей, индексы в "name" и "password" совпадают
    vector<string> sender_name; // вектор с именами отправителей
    vector<string> recipient_name; // вектор с именами получателей
    vector<string> message; // вектор с текстом сообщений

    string user_name, user_password, user_confirm_password, current_message, current_reciption_name, flag_response;// имя текущего пользователя, пароль, подтверждение, текст сообщения, имя получателя сообщения, переменная для определения кому отвечать

    int num, i, j, k;
    bool authorization, name_free, sent_nosuccessfully; // для логикифакта авторизации, свободного имени в чате, факта отправки сообщения.
    for (; ; )
    {
        cout << "выберете действие:" << endl;// основное меню
        cout << "1. Регистрация пользователя" << endl;
        cout << "2. Авторизация пользователя и работа в чате" << endl;
        cout << "3. Показать пользователи и пароли" << endl; // это на время отладки, в финальной версии удалим
        cout << "Для выхода из программы нажмите любую другую кнопку" << endl << endl;
        cin >> num;
        cin.ignore();
        if ((num > 3) | (num < 1)) // условие выхода из программы
        {
            break;
        }
        switch (num) // выбор действий через оператор switch
        {
        case 1:
            cout << "Введите ваше имя" << endl;
            getline(cin, user_name);
            if (name.size() == 0) // если пользователь первый, то не проверяем на уникальность
            {
                cout << "Придумайте Ваш пароль" << endl;
                getline(cin, user_password);

                // проверка совпадения паролей закомментирована на период отладки

                //cout << "Повторите пароль еще раз" << endl;
                //getline(cin, user_confirm_password);

                //if (user_password == user_confirm_password)
                //{
                name.push_back(user_name); // вносим в вектор имя
                password.push_back(user_password); // вносим в вектор пароль
                cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                //}
                //else
                //{
                 //   cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                //}
            }
            else // если в векторе имен есть хотя бы одна запись, проверяем следующих пользователей на уникальность
            {
                name_free = true;
                try // на самом деле не работает (при попытке выйти за предел длины вектора, например "i = name.size()" срабытывает исключение из вектора)
                {
                    for (i = 0; i < name.size(); ++i)
                    {
                        if (user_name == name[i])
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
                    //cout << "Повторите пароль еще раз" << endl;
                    //getline(cin, user_confirm_password);

                    //if (user_password == user_confirm_password)
                    //{
                    name.push_back(user_name); // добавляем нового пользователя в вектор
                    password.push_back(user_password); // добавляем пароль нового пользователя в вектор
                    cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                    break;
                    //}
                    //else
                    //{
                    //    cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                    //}
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
            for (i = 0; i < name.size(); ++i) // перебираем введенные имя и пароль в векторах
            {
                if (user_name == name[i] && user_password == password[i]) // если нашли соответствие авторизация прошла
                {
                    cout << "Добро пожаловать " << user_name << endl << endl;
                    authorization = true; //если имя и пароль верные, переменная authorization = true
                    break;
                }
            }
            if (authorization) // при удачной авторизации получаем доступ к отправке и получению сообщений.
            {

                for (;;)
                {
                    cout << "выберете действие:" << endl;// основное меню
                    cout << "1. Отправить сообщение всем пользователям" << endl;
                    cout << "2. Отправить личное сообщение" << endl;
                    cout << "3. Получить сообщение" << endl; // 
                    cout << "4. показать вектора" << endl; //
                    cout << "Для выхода в предыдущее меню нажмите любую другую кнопку" << endl << endl;
                    cin >> num;
                    cin.ignore();
                    if ((num > 4) | (num < 1)) // условие выхода в предыдущее меню
                    {
                        break;
                    }
                    switch (num) // выбор действий через оператор switch
                    {
                    case 1: // отправка сообщений всем пользователям
                        cout << "введите сообщение" << endl;
                        getline(cin, current_message);
                        for (i = 0; i < name.size(); ++i) // перебираем вектор имен
                        {
                            if (user_name != name[i]) // записываем во все вектора (отправитель, получатель, текст) значения, кроме случая равенства имени текущего пользователя и пользователя из вектора имен (чтобы не отправлять сообщение самому себе)
                            {
                                sender_name.push_back(user_name);
                                recipient_name.push_back(name[i]);
                                message.push_back("сообщение всем от " + user_name + ": " + current_message);
                            }
                        }
                        cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;

                        break;
                    case 2:
                        // отправка сообщения конкретному пользователю
                        sent_nosuccessfully = 1; // значение переменной будет истина, пока пользователь не введет правильно имя получателя
                        cout << "Сейчас в чате зарегистрированы:" << endl; // отображаем список зарегистрированных пользователей
                        for (i = 0; i < name.size(); ++i)
                        {
                            cout << name[i] << "; ";
                        }
                        while (sent_nosuccessfully) // бесконечный цикл, пока не введем точное имя получателя
                        {
                            cout << endl << "кому отправляем сообщение?" << endl;
                            getline(cin, current_reciption_name);

                            for (i = 0; i < name.size(); ++i) // перебираем введенное имя среди зарегистрированных пользователей
                            {
                                if (current_reciption_name == name[i]) // если находим, просим ввести текст сообщения
                                {
                                    cout << "введите сообщение" << endl;
                                    getline(cin, current_message);

                                    sender_name.push_back(user_name); // записываем сообщение в вектора отправителя, получателя, сам текст
                                    recipient_name.push_back(current_reciption_name);
                                    message.push_back("Вам сообщение от " + user_name + ": " + current_message);
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
                        j = message.size();
                        for (i = 0; i < j; ++i)
                        {
                            if (user_name == recipient_name[i]) // если находим свое имя в векторе получателей, 
                            {
                                cout << message[i] << endl; // выводим на экран сообщение
                                cout << "Для ответа пользователю '" << sender_name[i] << "' лично нажмите 'л', для ответа в общий чат нажмите 'в'" << endl; // предлагаем ответить лично или всем
                                cin >> flag_response; // вводим с клавиатуры, если:
                                if (flag_response == "л") // "л" - отпраляем личный ответ
                                {
                                    cin.ignore();
                                    cout << "введите текст сообщения:" << endl;
                                    getline(cin, current_message);
                                    sender_name.push_back(user_name);
                                    recipient_name.push_back(sender_name[i]);
                                    message.push_back("Вам сообщение от " + user_name + ": " + current_message);
                                    cout << "Ваше сообщение отправлено" << endl << endl;
                                }
                                if (flag_response == "в") // если "в" - то отвечаем всем
                                {
                                    cin.ignore();
                                    cout << "введите текст сообщения:" << endl;
                                    getline(cin, current_message);
                                    for (k = 0; k < name.size(); ++k)
                                    {
                                        if (user_name != name[k])
                                        {
                                            sender_name.push_back(user_name);
                                            recipient_name.push_back(name[k]);
                                            message.push_back("сообщение всем от " + user_name + ": " + current_message);
                                        }
                                    }
                                    cout << "Сообщение отправлено всем зарегистрированным пользователям" << endl << endl;
                                }
                                message.erase(message.begin() + i); // удаляем из вектора прочитанное сообщение
                                sender_name.erase(sender_name.begin() + i); // удаляем из вектора имя отправителя
                                recipient_name.erase(recipient_name.begin() + i); // удаляем из вектора имя получателя
                                --j; // длина векторов стала меньше на 1, соответственно уменьшаем на 1 количество проходов
                                --i; // мы только что удалили текущие значения в векторах имя, отправитель, получатель, значит с этим же индексом хранится уже новое сообщение, его будем проверять на следующем проходе
                            }
                        }

                        break;
                    case 4: // для отладки
                        for (i = 0; i < sender_name.size(); ++i)
                        {
                            cout << "отправитель " << sender_name[i] << endl;
                        }
                        for (i = 0; i < recipient_name.size(); ++i)
                        {
                            cout << "получатель " << recipient_name[i] << endl;
                        }
                        for (i = 0; i < message.size(); ++i)
                        {
                            cout << "сообщение " << message[i] << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "Ошибка имени пользователя или пароля" << endl;
            }

            break;
            // кейс 3 я использовал для отладки, в финальной версии удалим.
        case 3:
            for (i = 0; i < name.size(); i++)
            {
                cout << name[i] << endl;
            }
            for (i = 0; i < password.size(); i++)
            {
                cout << password[i] << endl;
            }
            break;
        }
    }
    return 0;
}






