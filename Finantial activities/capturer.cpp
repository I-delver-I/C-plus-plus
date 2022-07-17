#include"capturer.h"

Company captureCompany()
{
	cout << "You are capturing a company:" << endl;
	bool exceptionIsCaught;
	Company result;

	do
	{
		bool exceptionIsCaught = false;

		try
		{
			cout << "he";
		}
		catch (const invalid_argument& ex)
		{
			cout << ex.what();
			exceptionIsCaught = true;
		}
		catch (const out_of_range& ex)
		{
			cout << ex.what();
			exceptionIsCaught = true;
		}
	} while (exceptionIsCaught);

	return result;
}