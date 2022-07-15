#include"stringValidation.h"

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

bool validateOneRegister(string stringToValidate)
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