#include "CompaniesContainer.h"

void CompaniesContainer::addCompany(Company companyToAdd)
{
	if (exists(companyToAdd))
	{
		throw invalid_argument("The entered name of company already exists");
	}

	companies.push_back(companyToAdd);
}

vector<Company> CompaniesContainer::getCompanies()
{
	return companies;
}

bool CompaniesContainer::exists(Company companyToCheck)
{
	for (Company company : companies)
	{
		if (company.getName() == companyToCheck.getName())
		{
			return true;
		}
	}

	return false;
}

vector<Company> CompaniesContainer::companies;