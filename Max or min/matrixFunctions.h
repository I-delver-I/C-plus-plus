#pragma once
#include<iostream>
#include<iomanip>
#include"peak.h"
using namespace std;

template<typename T>
void printSequence(T* sequence, const int size)
{
	for (size_t i = 0; i < size; i++)
	{
		cout << sequence[i] << " ";
	}

	cout << endl;
}

template<typename T>
T** generateMatrix(const int rowsCount, const int columnsCount)
{
	auto result = new T*[rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		result[i] = new T[columnsCount];
	}

	return result;
}

template<typename T>
T** fillMatrix(T** matrix, const int rowsCount, const int columnsCount)
{
	T** result = matrix;

	for (size_t i = 0; i < rowsCount; i++)
	{
		cout << "Fill the " << i + 1 << " row:" << endl;

		for (size_t y = 0; y < columnsCount; y++)
		{
			bool wrongInput;

			do
			{
				wrongInput = false;

				cout << "Enter the element: ";
				string rawNumber;
				cin >> rawNumber;
				T number = (T)atof(rawNumber.c_str());

				if (rawNumber != "0" && !number)
				{
					wrongInput = true;
					cout << "You entered not a number" << endl;
				}
				else
				{
					result[i][y] = number;
				}
			}
			while (wrongInput);
		}
	}

	return result;
}

template<typename T>
void printMatrix(T** matrix, const int rowsCount, const int columnsCount)
{
	for (size_t i = 0; i < rowsCount; i++)
	{
		for (size_t y = 0; y < columnsCount; y++)
		{
			cout << setw(5) << matrix[i][y] << " ";
		}

		cout << endl;
	}
}

template<typename T>
T getMinElement(T* sequence, const int size)
{
	T result = sequence[0];

	for (size_t i = 1; i < size; i++)
	{
		if (sequence[i] < result)
		{
			result = sequence[i];
		}
	}

	return result;
}

template<typename T>
T getMaxElement(T* sequence, const int size)
{
	T result = sequence[0];

	for (size_t i = 1; i < size; i++)
	{
		if (sequence[i] > result)
		{
			result = sequence[i];
		}
	}

	return result;
}

template<typename T>
T* getRowsPeakElements(T **matrix, Peak epeak, const int rowsCount, const int columnsCount)
{
	auto result = new T[rowsCount];

	if (epeak == Max)
	{
		for (size_t i = 0; i < rowsCount; i++)
		{
			result[i] = getMaxElement(matrix[i], columnsCount);
		}
	}
	else if (epeak == Min)
	{
		for (size_t i = 0; i < rowsCount; i++)
		{
			result[i] = getMinElement(matrix[i], columnsCount);
		}
	}

	return result;
}