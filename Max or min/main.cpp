#include"matrixFunctions.h"
#include<iostream>
#include"validator.h"
using namespace std;

int** captureMatrix();

int main()
{
	int** matrix = captureMatrix();
	//printMatrix(matrix);
}

int** captureMatrix()
{
	int** result = nullptr;
	cout << "You are capturing a matrix:" << endl;
	bool errorOccured;

	do
	{
		errorOccured = false;

		cout << "Enter the rows count: ";
		int rowsCount;
		cin >> rowsCount;

		if (!elementsCountIsValid(rowsCount))
		{
			errorOccured = true;
			cout << "The count of rows is less than 1" << endl;
		}

		cout << "Enter the columns count: ";
		int columnsCount;
		cin >> columnsCount;

		if (!elementsCountIsValid(columnsCount))
		{
			errorOccured = true;
			cout << "The count of columns is less than 1" << endl;
		}

		if (!errorOccured)
		{
			result = generateMatrix<int>(rowsCount, columnsCount);
		}
	} 
	while (errorOccured);

	return result;
}