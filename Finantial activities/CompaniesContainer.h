#pragma once
#include<vector>
#include<algorithm>
#include"Company.h"

class CompaniesContainer
{
	vector<Company> companies;

public:
	CompaniesContainer();
	CompaniesContainer(vector<Company> companies);
	void addCompany(Company companyToAdd);
	bool exists(Company company);
	vector<Company> whereByName(string companyName);
	double getAverageIncome(string companyName);
	bool deviationIsPositive(double totalProfit, Company companyWorkMonth);
	vector<string> getCompaniesNames();
	const vector<Company> getCompanies();
	vector<Company> getCompaniesWithPositiveDeviation();
	friend ostream& operator<<(ostream& os, const CompaniesContainer& companies);
	friend void to_json(json& j, const CompaniesContainer& c);
	friend void from_json(const json& j, CompaniesContainer& c);
};