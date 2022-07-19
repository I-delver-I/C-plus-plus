#pragma once
#include<string>
#include<iostream>
#include<stdexcept>
#include<nlohmann/json.hpp>
using json = nlohmann::json;
using namespace std;

class Company
{
	string name;
	int month;
	double income;
	double salaryAccrual;
	double profit;

public:
	Company();
	Company(string name, int month, double income, double salaryAccrual);
	const string getName();
	void setName(string name);
	const int getMonth();
	void setMonth(int month);
	const double getIncome();
	void setIncome(double income);
	const double getSalaryAccrual();
	void setSalaryAccrual(double salaryAccrual);
	const double getProfit();
	friend ostream& operator<<(ostream& os, const Company& company);
	friend void from_json(const json& j, Company& c);
	friend void to_json(json& j, const Company& c);
};