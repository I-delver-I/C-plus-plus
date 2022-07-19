#include"capturer.h"

Company captureCompany()
{
	printHorizontalRule();
	cout << "You are capturing a company:" << endl;
	bool exceptionIsCaught;
	Company result;

	do
	{
		exceptionIsCaught = false;

		try
		{
			cout << "Please, enter the name: ";
			string name;
			getline(cin, name);
			result.setName(name);

			cout << "Please, enter the month: ";
			string month;
			getline(cin, month);
			
			try
			{
				stoi(month);
			}
			catch (const invalid_argument&)
			{
				throw invalid_argument("You entered not a number");
			}

			result.setMonth(stoi(month));

			cout << "Please, enter the income: ";
			string income;
			getline(cin, income);

			try
			{
				stod(income);
			}
			catch (const invalid_argument&)
			{
				throw invalid_argument("You entered not a number");
			}

			result.setIncome(stod(income));

			cout << "Please, enter the salary accrual: ";
			string salaryAccrual;
			getline(cin, salaryAccrual);

			try
			{
				stod(salaryAccrual);
			}
			catch (const invalid_argument&)
			{
				throw invalid_argument("You entered not a number");
			}

			result.setSalaryAccrual(stod(salaryAccrual));
		}
		catch (const invalid_argument& ex)
		{
			cout << ex.what() << endl;
			exceptionIsCaught = true;
		}
		catch (const out_of_range& ex)
		{
			cout << ex.what() << endl;
			exceptionIsCaught = true;
		}
	} while (exceptionIsCaught);

	printHorizontalRule();

	return result;
}

CompaniesContainer captureCompanies()
{
	CompaniesContainer result;
	cout << "You are capturing companies:" << endl;
	bool exceptionIsCaught;

	do
	{
		exceptionIsCaught = false;

		try
		{
			result.addCompany(captureCompany());
			cout << "Press <Backspace> to end typing or any other key to continue" << endl;
		}
		catch (const invalid_argument& ex)
		{
			cout << ex.what() << endl;
			exceptionIsCaught = true;
		}
	}
	while (exceptionIsCaught || _getch() != 8);

	return result;
}
