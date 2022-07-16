#include"matrixFunctions.h"
#include<iostream>
#include"capturer.h"
#include"validator.h"

int main()
{
	int rowsCount{};
	int columnsCount{};

	int** matrix = captureMatrix(rowsCount, columnsCount);
	cout << "The matrix itself:" << endl;
	printMatrix(matrix, rowsCount, columnsCount);

	Peak peak = capturePeak();
	int const* rowsPeakElements = getRowsPeakElements(matrix, peak, rowsCount, columnsCount);
	printSequence(rowsPeakElements, rowsCount);
}