#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    std::vector<string> name; // в векторе name храним имена зарегистрированных пользователей
    std::vector<string> password; // в векторе password храним пароли пользователей, индексы name  и password совпадают 
    string user_name, user_password, user_confirm_password;
    int num;
    bool authorization;
    bool name_free;
    for (; ; )
    {
        cout << "выберете действие:" << endl;// основное меню
        cout << "1. Регистрация пользователя" << endl;
        cout << "2. Авторизация пользователя и работа в чате" << endl;
        cout << "3. Показать пользователи и пароли" << endl; // это на время отладки, в финальной версии удалим
        cout << "Для выхода из программы нажмите любую другую кнопку" << endl << endl;
        cin >> num;
        if ((num > 3) | (num < 1)) // условие выхода из программы
        {
            break;
        }
        switch (num) // выбор действий через оператор switch
        {
        case 1:
            cout << "Введите ваше имя" << endl;
            cin >> user_name;
            if (name.size() == 0)
            {
                cout << "Введите Ваш пароль" << endl;
                cin >> user_password;
                cout << "Введите пароль еще раз" << endl;
                cin >> user_confirm_password;
                if (user_password == user_confirm_password)
                {
                    name.push_back(user_name);
                    password.push_back(user_password);
                    cout << "Пользователь " << user_name << " зарегистрирован" << endl << endl;
                }
                else
                {
                    cout << "Пароли не совпадают. Пользователь НЕ зарегистрирован" << endl << endl;
                }
            }
            else
            {
                name_free = true;
                for (int i = 0; i < name.size(); ++i)
                {
                    if (user_name == name[i])
                    {
                        name_free = false;
                        break;
                    }
                }
                if (name_free)
                {
                    cout << "Придумайте Ваш пароль" << endl;
                    cin >> user_password;
                    cout << "Повторите пароль еще раз" << endl;
                    cin >> user_confirm_password;
                    if (user_password == user_confirm_password)
                    {
                        name.push_back(user_name);
                        password.push_back(user_password);
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
            cout << "Введите Ваше имя:" << endl;
            cin >> user_name;
            cout << "Введите Ваш пароль:" << endl;
            cin >> user_password;
            authorization = false;
            for (int i = 0; i < name.size(); ++i)
            {
                if (user_name == name[i] && user_password == password[i])
                {
                    cout << "Добро пожаловать " << user_name << endl;
                    authorization = true;
                    break;
                }
            }
            if (authorization)
            {
                cout << "Добро пожаловать " << user_name << endl;

                // тут продалжаем писать программу. По моей задумке, после успешной авторизации должно появиться меню:
                                // 1. Отправить сообщение всем пользователям
                                // 2. Отправить личное сообщение
                                // 3. Получить сообщение
                                // 0. Выход в предыдущее меню.

                                // Анне предлагаю написать пункты 1 и 2.
                                // 
                                // Предлагаю создать еще 3 вектора (sender_name - в нем храним имя отправителя, recipient_name - в нем храним имя получателя и message - в нем храним текст сообщения, все вектора string)
                                //Для отправки сообщения всем пользователям запускаем цикл от 0 до <name.size() - 1> (-1 чтобы не отправлять себе) (Анна, метод size() - возвращает размер вектора, т.е. количество занятых ячеек)
                                //и в вектор <sender_name> записываем значенеи переменной <user_name> (в ней хранится значение авторизованного пользователя), в вектор <recipient_name> записываем значение вектора <name> (тут вставляем условие
                                //, что если значение name[] = user_name, то не записываем значение, в вектор <messge> записываем текст сообщения, введенный пользователем с клавиатуры)

                                //В меню "2. Отправить личное сообщение" должно быть 3 пункта:
                                //1. Вывести на экран список зарегистрированных пользователей
                                //2. Отправить сообщение
                                //0. Выход в предыдущее меню.
                                //по первому действию выводим на экран значение ветора <name>
                                //по второму вводим с экрана имя, проверяем наличие этого имени в векторе <name>, если находим, то записываем в вектора <sender_name> <recipient_name> <message> соответствующие значения (отправитель, получатель, тьекст)
                                //если не находимя, выводим на экран, что пользователь не найден, введите имя снова

                                //Андрей, тебе предлагаю написать код для получения сообщений.
                                //ищем в векторе <recipient_name> свое имя, которое хранится в <user_name> и если находим, то сообщаем, что вам сообщение от пользователя, выводим значенеи <sender_name> и само <message>
                                //после вывода сообщения, нужно удалить значения из вектров <sender_name>, <recipient_name> и <message> и уменьшить на один количество проходов в цикле.
                                //по условию после получения сообщения должна появиться возможность ответа - нужно предусмотреть
                                //продолжаем просмотр вектора <recipient_name> - если находим свое имя - выводим сообщение, удаляем, спрашиваем о необходимости ответа и так до конца вектора.




            }
            else
            {
                cout << "Ошибка имени пользователя или пароля" << endl;
            }

            break;
            // кейс 3 я использовал для отладки, в финальной версии удалим.
        case 3:
            for (int i = 0; i < name.size(); i++)
            {
                cout << name[i] << endl;
            }
            for (int i = 0; i < password.size(); i++)
            {
                cout << password[i] << endl;
            }
            break;
        }
    }
    return 0;
}






