#include"Company.h"
#include"CompaniesContainer.h"
#include<iostream>
#include"output.h"
using namespace std;

/*
	� ����� �������� ���������� � ���������� ������������ �����������
	�� �������� ���: ������������ �����������, �����, ����� �����������
	�� ���� �����, ���������� �� ��������, ������� �����������.
	������������ ����, ���������� ������ �����������, � ������� �������������
	���������� �� ��������������� ������ ��������� 50%
*/

int main()
{
	Company first = Company("first", 1, 234, 200);
	CompaniesContainer::addCompany(first);
	Company second = Company("second", 2, 100, 50);
	CompaniesContainer::addCompany(second);

	printCollection(CompaniesContainer::getCompanies());
}