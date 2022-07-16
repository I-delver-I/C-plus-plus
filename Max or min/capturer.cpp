#include"capturer.h"

Peak capturePeak()
{
	bool errorOccured;

	do
	{
		errorOccured = false;

		cout << "Enter <Max> or <Min> (without braces) to capture values in matrix rows: ";
		string rawPeak;
		cin >> rawPeak;

		if (rawPeak == "Min")
		{
			return Min;
		}
		else if (rawPeak == "Max")
		{
			return Max;
		}
		else
		{
			errorOccured = true;
			cout << "You entered wrong value" << endl;
		}
	} while (errorOccured);

	cout << endl;
}

int** captureMatrix(int& rowsCount, int& columnsCount)
{
	int** result = nullptr;
	cout << "You are capturing a matrix:" << endl;
	bool errorOccured;

	do
	{
		errorOccured = false;

		cout << "Enter the rows count: ";
		cin >> rowsCount;

		if (!elementsCountIsValid(rowsCount))
		{
			errorOccured = true;
			cout << "The count of rows is less than 1" << endl;
		}

		cout << "Enter the columns count: ";
		cin >> columnsCount;

		if (!elementsCountIsValid(columnsCount))
		{
			errorOccured = true;
			cout << "The count of columns is less than 1" << endl;
		}

		if (!errorOccured)
		{
			result = generateMatrix<int>(rowsCount, columnsCount);
			result = fillMatrix(result, rowsCount, columnsCount);
			cout << endl;
		}
	} while (errorOccured);

	return result;
}