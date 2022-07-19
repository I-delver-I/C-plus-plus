#include "CompaniesContainer.h"

CompaniesContainer::CompaniesContainer() = default;

CompaniesContainer::CompaniesContainer(vector<Company> companies)
{
	this->companies = companies;
}

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

ostream& operator<<(ostream& os, const CompaniesContainer& companies)
{
	for (Company company : companies.companies)
	{
		os << company << endl;
	}

	return os;
}

void to_json(json& j, const CompaniesContainer& c)
{
	for (Company company : c.companies)
	{
		j.push_back(company);
	}
}

void from_json(const json& j, CompaniesContainer& c)
{
	while (!j.empty())
	{
		c.addCompany(j.get<Company>());
	}
}
