#pragma once
#include <string>
#include <vector>
using namespace std;

class Bad_range : public exception // ������� ����� ������, ���������� �� ����������� ������ exception
{
public:
	virtual const char* what() const noexcept override
	{
		return "ERROR: bad range array"; // ������������ �� ������ ��� ��������� ����������
	}
};
