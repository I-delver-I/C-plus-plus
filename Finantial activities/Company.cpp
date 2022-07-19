#include "Company.h"

void to_json(json& j, const Company& c)
{
	j = json{ {"name", c.name}, {"month", c.month}, {"income", c.income}, {"salaryAccrual", c.salaryAccrual},
		{"profit", c.profit} };
}

void from_json(const json& j, Company& c)
{
	j.at("name").get_to(c.name);
	j.at("month").get_to(c.month);
	j.at("income").get_to(c.income);
	j.at("salaryAccrual").get_to(c.salaryAccrual);
	j.at("profit").get_to(c.profit);
}

ostream& operator<<(ostream& os, const Company& company)
{
	os << "Name - " << company.name << ", Month - " << company.month << ", Income - " << company.income
		<< ", Salary accrual - " << company.salaryAccrual << ", Profit - " << company.profit;
	
	return os;
}

const string Company::getName()
{
	return name;
}

void Company::setName(string name)
{
	if (strlen(name.c_str()) == 0)
	{
		throw invalid_argument("The name mustn't be empty");
	}

	this->name = name;
}

const int Company::getMonth()
{
	return month;
}

void Company::setMonth(int month)
{
	if (month < 1)
	{
		throw out_of_range("The month number mustn't be less than 1");
	}

	if (month > 12)
	{
		throw out_of_range("The month number mustn't be bigger than 12");
	}

	this->month = month;
}

const double Company::getIncome()
{
	return income;
}

void Company::setIncome(double income)
{
	if (income < 0)
	{
		throw out_of_range("The income mustn't be less than 0");
	}

	this->income = income;
}

const double Company::getSalaryAccrual()
{
	return salaryAccrual;
}

void Company::setSalaryAccrual(double salaryAccrual)
{
	if (salaryAccrual < 0)
	{
		throw out_of_range("The salary accrual mustn't be less than 0");
	}

	if (salaryAccrual > income)
	{
		throw out_of_range("The salary accural mustn't be bigger than income");
	}

	this->salaryAccrual = salaryAccrual;
	profit = income - salaryAccrual;
}

double Company::getProfit()
{
	return profit;
}

Company::Company()
{
	name = "Company";
	month = 0;
	income = 0;
	salaryAccrual = 0;
}

Company::Company(string name, int month, double income, double salaryAccrual)
{
	this->name = name;
	setMonth(month);
	setIncome(income);
	setSalaryAccrual(salaryAccrual);
}