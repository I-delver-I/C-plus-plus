#pragma once
#include<vector>
#include"Company.h"

class CompaniesContainer
{
	static vector<Company> companies;

public:
	static void addCompany(Company companyToAdd);
	static bool exists(Company company);
	static vector<Company> getCompanies();
};