#include"Company.h"
#include"CompaniesContainer.h"
#include<iostream>
#include"output.h"
using namespace std;

/*
	¬ файле хранитс€ информаци€ о финансовой де€тельности предпри€тий
	за истекший год: наименование предпри€ти€, мес€ц, доход предпри€ти€
	за этот мес€ц, начислени€ на зарплату, прибыль предпри€ти€.
	—формировать файл, содержащий список предпри€тий, у которых положительное
	отклонение от среднемес€чного дохода превышает 50%
*/

int main()
{
	Company first = Company("first", 1, 234, 200);
	CompaniesContainer::addCompany(first);
	Company second = Company("second", 2, 100, 50);
	CompaniesContainer::addCompany(second);

	printCollection(CompaniesContainer::getCompanies());
}