#include"capturer.h"

string captureString()
{
	string result;
	bool errorOccured;

	do
	{
		errorOccured = false;

		cout << "Please, enter a string which consists only of letters: ";
		cin >> result;

		if (!validateOnlyLetters(result))
		{
			errorOccured = true;
			cout << "The string includes not only letters" << endl;
		}
		else if (!validateOnlyRegister(result))
		{
			errorOccured = true;
			cout << "The string's letters doesn't have the same register" << endl;
		}
	} while (errorOccured);

	return result;
}