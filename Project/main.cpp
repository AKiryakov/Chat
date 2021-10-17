#include <string>
#include <iostream>
#include <vector>
using namespace std;

int main()
{
    setlocale(LC_ALL, "");
    std::vector<string> name; // � ������� name ������ ����� ������������������ �������������
    std::vector<string> password; // � ������� password ������ ������ �������������, ������� name  � password ��������� 
    string user_name, user_password, user_confirm_password;
    int num;
    bool authorization;
    bool name_free;
    for (; ; )
    {
        cout << "�������� ��������:" << endl;// �������� ����
        cout << "1. ����������� ������������" << endl;
        cout << "2. ����������� ������������ � ������ � ����" << endl;
        cout << "3. �������� ������������ � ������" << endl; // ��� �� ����� �������, � ��������� ������ ������
        cout << "��� ������ �� ��������� ������� ����� ������ ������" << endl << endl;
        cin >> num;
        if ((num > 3) | (num < 1)) // ������� ������ �� ���������
        {
            break;
        }
        switch (num) // ����� �������� ����� �������� switch
        {
        case 1:
            cout << "������� ���� ���" << endl;
            cin >> user_name;
            if (name.size() == 0)
            {
                cout << "������� ��� ������" << endl;
                cin >> user_password;
                cout << "������� ������ ��� ���" << endl;
                cin >> user_confirm_password;
                if (user_password == user_confirm_password)
                {
                    name.push_back(user_name);
                    password.push_back(user_password);
                    cout << "������������ " << user_name << " ���������������" << endl << endl;
                }
                else
                {
                    cout << "������ �� ���������. ������������ �� ���������������" << endl << endl;
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
                    cout << "���������� ��� ������" << endl;
                    cin >> user_password;
                    cout << "��������� ������ ��� ���" << endl;
                    cin >> user_confirm_password;
                    if (user_password == user_confirm_password)
                    {
                        name.push_back(user_name);
                        password.push_back(user_password);
                        cout << "������������ " << user_name << " ���������������" << endl << endl;
                        break;
                    }
                    else
                    {
                        cout << "������ �� ���������. ������������ �� ���������������" << endl << endl;
                    }
                }
                else
                {
                    cout << "��� ��� ������������, ���������� ������" << endl << endl;
                }
            }
            break;
        case 2:
            cout << "������� ���� ���:" << endl;
            cin >> user_name;
            cout << "������� ��� ������:" << endl;
            cin >> user_password;
            authorization = false;
            for (int i = 0; i < name.size(); ++i)
            {
                if (user_name == name[i] && user_password == password[i])
                {
                    cout << "����� ���������� " << user_name << endl;
                    authorization = true;
                    break;
                }
            }
            if (authorization)
            {
                cout << "����� ���������� " << user_name << endl;

                // ��� ���������� ������ ���������. �� ���� �������, ����� �������� ����������� ������ ��������� ����:
                                // 1. ��������� ��������� ���� �������������
                                // 2. ��������� ������ ���������
                                // 3. �������� ���������
                                // 0. ����� � ���������� ����.

                                // ���� ��������� �������� ������ 1 � 2.
                                // 
                                // ��������� ������� ��� 3 ������� (sender_name - � ��� ������ ��� �����������, recipient_name - � ��� ������ ��� ���������� � message - � ��� ������ ����� ���������, ��� ������� string)
                                //��� �������� ��������� ���� ������������� ��������� ���� �� 0 �� <name.size() - 1> (-1 ����� �� ���������� ����) (����, ����� size() - ���������� ������ �������, �.�. ���������� ������� �����)
                                //� � ������ <sender_name> ���������� �������� ���������� <user_name> (� ��� �������� �������� ��������������� ������������), � ������ <recipient_name> ���������� �������� ������� <name> (��� ��������� �������
                                //, ��� ���� �������� name[] = user_name, �� �� ���������� ��������, � ������ <messge> ���������� ����� ���������, ��������� ������������� � ����������)

                                //� ���� "2. ��������� ������ ���������" ������ ���� 3 ������:
                                //1. ������� �� ����� ������ ������������������ �������������
                                //2. ��������� ���������
                                //0. ����� � ���������� ����.
                                //�� ������� �������� ������� �� ����� �������� ������ <name>
                                //�� ������� ������ � ������ ���, ��������� ������� ����� ����� � ������� <name>, ���� �������, �� ���������� � ������� <sender_name> <recipient_name> <message> ��������������� �������� (�����������, ����������, ������)
                                //���� �� ��������, ������� �� �����, ��� ������������ �� ������, ������� ��� �����

                                //������, ���� ��������� �������� ��� ��� ��������� ���������.
                                //���� � ������� <recipient_name> ���� ���, ������� �������� � <user_name> � ���� �������, �� ��������, ��� ��� ��������� �� ������������, ������� �������� <sender_name> � ���� <message>
                                //����� ������ ���������, ����� ������� �������� �� ������� <sender_name>, <recipient_name> � <message> � ��������� �� ���� ���������� �������� � �����.
                                //�� ������� ����� ��������� ��������� ������ ��������� ����������� ������ - ����� �������������
                                //���������� �������� ������� <recipient_name> - ���� ������� ���� ��� - ������� ���������, �������, ���������� � ������������� ������ � ��� �� ����� �������.




            }
            else
            {
                cout << "������ ����� ������������ ��� ������" << endl;
            }

            break;
            // ���� 3 � ����������� ��� �������, � ��������� ������ ������.
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






