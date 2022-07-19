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
		throw invalid_argument("The same company with entered month already exists");
	}

	companies.push_back(companyToAdd);
}

const vector<Company> CompaniesContainer::getCompanies()
{
	return companies;
}

bool CompaniesContainer::exists(Company companyToCheck)
{
	for (Company company : companies)
	{
		if ((company.getName() == companyToCheck.getName()) && (company.getMonth() == companyToCheck.getMonth()))
		{
			return true;
		}
	}

	return false;
}

vector<Company> CompaniesContainer::whereByName(string companyName)
{
	vector<Company> result;

	for (Company company : companies)
	{
		if (company.getName() == companyName)
		{
			result.push_back(company);
		}
	}

	return result;
}

vector<Company> CompaniesContainer::getCompaniesWithPositiveDeviation()
{
	vector<Company> result;

	for (string name : getCompaniesNames())
	{
		double averageIncome = getAverageIncome(name);

		for (Company company : whereByName(name))
		{
			if (deviationIsPositive(averageIncome, company))
			{
				result.push_back(company);
			}
		}
	}

	return result;
}

double CompaniesContainer::getAverageIncome(string companyName)
{
	double result = 0;
	int count = 0;

	for (Company company : companies)
	{
		if (company.getName() == companyName)
		{
			result += company.getIncome();
			count++;
		}
	}

	return result / count;
}

bool CompaniesContainer::deviationIsPositive(double averageIncome, Company companyWorkMonth)
{
	return (companyWorkMonth.getIncome() / averageIncome) > 1.5;
}

vector<string> CompaniesContainer::getCompaniesNames()
{
	vector<string> result;

	for (Company company : companies)
	{
		if (!count(result.begin(), result.end(), company.getName()))
		{
			result.push_back(company.getName());
		}
	}

	return result;
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
	for (auto company : j)
	{
		c.addCompany(company.get<Company>());
	}
}
