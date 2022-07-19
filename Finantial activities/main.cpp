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
	¬ файле хранитс€ информаци€ о финансовой де€тельности предпри€тий
	за истекший год: наименование предпри€ти€, мес€ц, доход предпри€ти€
	за этот мес€ц, начислени€ на зарплату, прибыль предпри€ти€.
	—формировать файл, содержащий список предпри€тий, у которых положительное
	отклонение от среднемес€чного дохода превышает 50%
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