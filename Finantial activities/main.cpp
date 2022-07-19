#include"Company.h"
#include"CompaniesContainer.h"
#include<iostream>
#include"output.h"
#include"fileManager.h"
#include<fstream>
#include"capturer.h"
#include<nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

/*
	� ����� �������� ���������� � ���������� ������������ �����������
	�� �������� ���: ������������ �����������, �����, ����� �����������
	�� ���� �����, ���������� �� ��������, ������� �����������.
	������������ ����, ���������� ������ �����������, � ������� �������������
	���������� �� ��������������� ������ ��������� 50%
*/

int main()
{
	CompaniesContainer companies = captureCompanies();
	writeCompaniesToFile(mainFilePath, companies);
	cout << endl << "The entered companies are: " << endl << readCompaniesFromFile(mainFilePath);

	auto positiveDeviationCompanies = CompaniesContainer(companies.getCompaniesWithPositiveDeviation());
	writeCompaniesToFile(secondaryFilePath, positiveDeviationCompanies);
	cout << endl << "The positive deviation companies are: " << endl << readCompaniesFromFile(secondaryFilePath);
}