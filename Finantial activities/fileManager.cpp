#include"fileManager.h"

void writeCompaniesToFile(CompaniesContainer companies)
{
	ofstream file(filePath, ios::app);
	//json data = json::parse(num);
	//file << data;
	file.close();
}

CompaniesContainer readCompaniesFromFile()
{
	CompaniesContainer result;
	ifstream file(filePath, ios::in);
	json temp;
	file >> temp;
	file.close();

	//result = CompaniesContainer(temp);
	//result

	return result;
}