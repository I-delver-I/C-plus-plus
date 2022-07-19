#include"fileManager.h"

void writeCompaniesToFile(const string filePath, CompaniesContainer& companies)
{
	ofstream outputFile(filePath, ios::trunc);
	json data = companies;
	outputFile << data;
	outputFile.close();
}

CompaniesContainer readCompaniesFromFile(const string filePath)
{
	CompaniesContainer result;

	ifstream inputFile(filePath, ios::in);
	json temp;
	inputFile >> temp;
	result = temp;
	inputFile.close();

	return result;
}