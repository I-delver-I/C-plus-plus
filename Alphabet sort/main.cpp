#include <iostream>
#include<string>
using namespace std;

string captureString();
string stringSortDescending(string stringToSort);
string stringSort(string stringToSort);
bool validateOnlyRegister(string stringToValidate);
bool validateOnlyLetters(string stringToValidate);

int main()
{
	string stringToSort = captureString();
	cout << "The string which is sorted ascending:" << endl << stringSort(stringToSort) << endl;
	cout << "The string which is sorted descending:" << endl << stringSortDescending(stringToSort);
}

bool validateOnlyLetters(string stringToValidate)
{
	for (char symbol : stringToValidate)
	{
		if (!isalpha(symbol))
		{
			return false;
		}
	}

	return true;
}

bool validateOnlyRegister(string stringToValidate)
{
	bool shouldBeLower = islower(stringToValidate[0]);

	for (int i = 1; i < strlen(stringToValidate.c_str()); i++)
	{
		if ((shouldBeLower && !islower(stringToValidate[i])) || (!shouldBeLower && islower(stringToValidate[i])))
		{
			return false;
		}
	}

	return true;
}

string stringSort(string stringToSort)
{
	const char* letters = stringToSort.c_str();
	char tempLetter;

	for (size_t i = 0; i < strlen(letters); i++)
	{
		for (size_t y = 0; y < strlen(letters) - 1; y++)
		{
			if (stringToSort[y] > stringToSort[y + 1])
			{
				tempLetter = stringToSort[y];
				stringToSort[y] = stringToSort[y + 1];
				stringToSort[y + 1] = tempLetter;
			}
		}
	}

	return stringToSort;
}

string stringSortDescending(string stringToSort)
{
	const char* letters = stringToSort.c_str();
	char tempLetter;

	for (size_t i = 0; i < strlen(letters); i++)
	{
		for (size_t y = 0; y < strlen(letters) - 1; y++)
		{
			if (stringToSort[y] < stringToSort[y + 1])
			{
				tempLetter = stringToSort[y];
				stringToSort[y] = stringToSort[y + 1];
				stringToSort[y + 1] = tempLetter;
			}
		}
	}

	return stringToSort;
}

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