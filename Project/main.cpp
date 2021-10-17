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

    vector<string> name; // � ������� "name" ������ ����� ������������������ �������������
    vector<string> password; // � ������� password ������ ������ �������������, ������� � "name" � "password" ���������
    vector<string> sender_name; // ������ � ������� ������������
    vector<string> recipient_name; // ������ � ������� �����������
    vector<string> message; // ������ � ������� ���������

    string user_name, user_password, user_confirm_password, current_message, current_reciption_name, flag_response;// ��� �������� ������������, ������, �������������, ����� ���������, ��� ���������� ���������, ���������� ��� ����������� ���� ��������

    int num, i, j, k;
    bool authorization, name_free, sent_nosuccessfully; // ��� ����������� �����������, ���������� ����� � ����, ����� �������� ���������.
    for (; ; )
    {
        cout << "�������� ��������:" << endl;// �������� ����
        cout << "1. ����������� ������������" << endl;
        cout << "2. ����������� ������������ � ������ � ����" << endl;
        cout << "3. �������� ������������ � ������" << endl; // ��� �� ����� �������, � ��������� ������ ������
        cout << "��� ������ �� ��������� ������� ����� ������ ������" << endl << endl;
        cin >> num;
        cin.ignore();
        if ((num > 3) | (num < 1)) // ������� ������ �� ���������
        {
            break;
        }
        switch (num) // ����� �������� ����� �������� switch
        {
        case 1:
            cout << "������� ���� ���" << endl;
            getline(cin, user_name);
            if (name.size() == 0) // ���� ������������ ������, �� �� ��������� �� ������������
            {
                cout << "���������� ��� ������" << endl;
                getline(cin, user_password);

                // �������� ���������� ������� ���������������� �� ������ �������

                //cout << "��������� ������ ��� ���" << endl;
                //getline(cin, user_confirm_password);

                //if (user_password == user_confirm_password)
                //{
                name.push_back(user_name); // ������ � ������ ���
                password.push_back(user_password); // ������ � ������ ������
                cout << "������������ " << user_name << " ���������������" << endl << endl;
                //}
                //else
                //{
                 //   cout << "������ �� ���������. ������������ �� ���������������" << endl << endl;
                //}
            }
            else // ���� � ������� ���� ���� ���� �� ���� ������, ��������� ��������� ������������� �� ������������
            {
                name_free = true;
                try // �� ����� ���� �� �������� (��� ������� ����� �� ������ ����� �������, �������� "i = name.size()" ����������� ���������� �� �������)
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

                catch (exception& error) // ��������� ��������� ����������
                {
                    cout << error.what();
                }


                if (name_free) // ���� ��� ���������, �� ���������� � ����� ������
                {
                    cout << "���������� ��� ������" << endl;
                    getline(cin, user_password);

                    // �������� ���������� ������� ���������������� �� ������ �������
                    //cout << "��������� ������ ��� ���" << endl;
                    //getline(cin, user_confirm_password);

                    //if (user_password == user_confirm_password)
                    //{
                    name.push_back(user_name); // ��������� ������ ������������ � ������
                    password.push_back(user_password); // ��������� ������ ������ ������������ � ������
                    cout << "������������ " << user_name << " ���������������" << endl << endl;
                    break;
                    //}
                    //else
                    //{
                    //    cout << "������ �� ���������. ������������ �� ���������������" << endl << endl;
                    //}
                }
                else
                {
                    cout << "��� ��� ������������, ���������� ������" << endl << endl;
                }
            }
            break;
        case 2:
            // �����������
            cout << "������� ���� ���:" << endl;
            getline(cin, user_name);

            cout << "������� ��� ������:" << endl;
            getline(cin, user_password);

            authorization = false;
            for (i = 0; i < name.size(); ++i) // ���������� ��������� ��� � ������ � ��������
            {
                if (user_name == name[i] && user_password == password[i]) // ���� ����� ������������ ����������� ������
                {
                    cout << "����� ���������� " << user_name << endl << endl;
                    authorization = true; //���� ��� � ������ ������, ���������� authorization = true
                    break;
                }
            }
            if (authorization) // ��� ������� ����������� �������� ������ � �������� � ��������� ���������.
            {

                for (;;)
                {
                    cout << "�������� ��������:" << endl;// �������� ����
                    cout << "1. ��������� ��������� ���� �������������" << endl;
                    cout << "2. ��������� ������ ���������" << endl;
                    cout << "3. �������� ���������" << endl; // 
                    cout << "4. �������� �������" << endl; //
                    cout << "��� ������ � ���������� ���� ������� ����� ������ ������" << endl << endl;
                    cin >> num;
                    cin.ignore();
                    if ((num > 4) | (num < 1)) // ������� ������ � ���������� ����
                    {
                        break;
                    }
                    switch (num) // ����� �������� ����� �������� switch
                    {
                    case 1: // �������� ��������� ���� �������������
                        cout << "������� ���������" << endl;
                        getline(cin, current_message);
                        for (i = 0; i < name.size(); ++i) // ���������� ������ ����
                        {
                            if (user_name != name[i]) // ���������� �� ��� ������� (�����������, ����������, �����) ��������, ����� ������ ��������� ����� �������� ������������ � ������������ �� ������� ���� (����� �� ���������� ��������� ������ ����)
                            {
                                sender_name.push_back(user_name);
                                recipient_name.push_back(name[i]);
                                message.push_back("��������� ���� �� " + user_name + ": " + current_message);
                            }
                        }
                        cout << "��������� ���������� ���� ������������������ �������������" << endl << endl;

                        break;
                    case 2:
                        // �������� ��������� ����������� ������������
                        sent_nosuccessfully = 1; // �������� ���������� ����� ������, ���� ������������ �� ������ ��������� ��� ����������
                        cout << "������ � ���� ����������������:" << endl; // ���������� ������ ������������������ �������������
                        for (i = 0; i < name.size(); ++i)
                        {
                            cout << name[i] << "; ";
                        }
                        while (sent_nosuccessfully) // ����������� ����, ���� �� ������ ������ ��� ����������
                        {
                            cout << endl << "���� ���������� ���������?" << endl;
                            getline(cin, current_reciption_name);

                            for (i = 0; i < name.size(); ++i) // ���������� ��������� ��� ����� ������������������ �������������
                            {
                                if (current_reciption_name == name[i]) // ���� �������, ������ ������ ����� ���������
                                {
                                    cout << "������� ���������" << endl;
                                    getline(cin, current_message);

                                    sender_name.push_back(user_name); // ���������� ��������� � ������� �����������, ����������, ��� �����
                                    recipient_name.push_back(current_reciption_name);
                                    message.push_back("��� ��������� �� " + user_name + ": " + current_message);
                                    cout << "���� ��������� ����������" << endl << endl;
                                    sent_nosuccessfully = 0; // ������������� ���� � ��������� "��������� ����������"
                                }
                            }
                            if (sent_nosuccessfully) // ���� ��� ���������� � ������ �� �����, �������� �� ����
                            {
                                cout << "������������ � ������ " << current_reciption_name << " � ���� �� ���������������" << endl << endl;
                            }
                        }
                        break;

                    case 3: // �������� ���������
                        j = message.size();
                        for (i = 0; i < j; ++i)
                        {
                            if (user_name == recipient_name[i]) // ���� ������� ���� ��� � ������� �����������, 
                            {
                                cout << message[i] << endl; // ������� �� ����� ���������
                                cout << "��� ������ ������������ '" << sender_name[i] << "' ����� ������� '�', ��� ������ � ����� ��� ������� '�'" << endl; // ���������� �������� ����� ��� ����
                                cin >> flag_response; // ������ � ����������, ����:
                                if (flag_response == "�") // "�" - ��������� ������ �����
                                {
                                    cin.ignore();
                                    cout << "������� ����� ���������:" << endl;
                                    getline(cin, current_message);
                                    sender_name.push_back(user_name);
                                    recipient_name.push_back(sender_name[i]);
                                    message.push_back("��� ��������� �� " + user_name + ": " + current_message);
                                    cout << "���� ��������� ����������" << endl << endl;
                                }
                                if (flag_response == "�") // ���� "�" - �� �������� ����
                                {
                                    cin.ignore();
                                    cout << "������� ����� ���������:" << endl;
                                    getline(cin, current_message);
                                    for (k = 0; k < name.size(); ++k)
                                    {
                                        if (user_name != name[k])
                                        {
                                            sender_name.push_back(user_name);
                                            recipient_name.push_back(name[k]);
                                            message.push_back("��������� ���� �� " + user_name + ": " + current_message);
                                        }
                                    }
                                    cout << "��������� ���������� ���� ������������������ �������������" << endl << endl;
                                }
                                message.erase(message.begin() + i); // ������� �� ������� ����������� ���������
                                sender_name.erase(sender_name.begin() + i); // ������� �� ������� ��� �����������
                                recipient_name.erase(recipient_name.begin() + i); // ������� �� ������� ��� ����������
                                --j; // ����� �������� ����� ������ �� 1, �������������� ��������� �� 1 ���������� ��������
                                --i; // �� ������ ��� ������� ������� �������� � �������� ���, �����������, ����������, ������ � ���� �� �������� �������� ��� ����� ���������, ��� ����� ��������� �� ��������� �������
                            }
                        }

                        break;
                    case 4: // ��� �������
                        for (i = 0; i < sender_name.size(); ++i)
                        {
                            cout << "����������� " << sender_name[i] << endl;
                        }
                        for (i = 0; i < recipient_name.size(); ++i)
                        {
                            cout << "���������� " << recipient_name[i] << endl;
                        }
                        for (i = 0; i < message.size(); ++i)
                        {
                            cout << "��������� " << message[i] << endl;
                        }
                        break;
                    }
                }
            }
            else
            {
                cout << "������ ����� ������������ ��� ������" << endl;
            }

            break;
            // ���� 3 � ����������� ��� �������, � ��������� ������ ������.
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






