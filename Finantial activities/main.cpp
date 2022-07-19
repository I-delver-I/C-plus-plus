#include"Company.h"
#include"CompaniesContainer.h"
#include<iostream>
#include"output.h"
#include"fileManager.h"
#include<fstream>
#include<nlohmann/json.hpp>
using namespace std;
using json = nlohmann::json;

/*
	¬ файле хранитс€ информаци€ о финансовой де€тельности предпри€тий
	за истекший год: наименование предпри€ти€, мес€ц, доход предпри€ти€
	за этот мес€ц, начислени€ на зарплату, прибыль предпри€ти€.
	—формировать файл, содержащий список предпри€тий, у которых положительное
	отклонение от среднемес€чного дохода превышает 50%
*/

int main()
{
	CompaniesContainer companies;
	Company first = Company("first", 1, 234, 200);
	companies.addCompany(first);
	Company second = Company("second", 2, 100, 50);
	companies.addCompany(second);
	//writeCompaniesToFile(companies);

	/*ofstream inputFile;
	inputFile.open(filePath, ios::in);
	inputFile.write(reinterpret_cast<char *>(&test), sizeof(test));
	inputFile.close();
	
	ifstream file;
	vector<Company> result;
	file.open(filePath, ios::in);
	file.read(reinterpret_cast<char *> (&result), sizeof(result));
	file.close();

	for (Company company : test)
	{
		cout << company << endl;
	}*/

	/*ofstream inputFile(filePath);
	json test = json::parse(first);
	inputFile << test;
	inputFile.close();

	ifstream file(filePath);
	json res;
	file >> res;
	file.close();

	cout << res;*/

	json test = companies;
	cout << "Companies: " << endl << companies << endl;

	//printCollection(readCompaniesFromFile().getCompanies());
}