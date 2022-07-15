#include"stringSorting.h"
#include"stringValidation.h"

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