#include"matrixFunctions.h"
#include<iostream>
#include"peek.h"
#include<iomanip>
using namespace std;

//template<typename T>
//void printMatrix(T** matrix)
//{
//	for (T* row : matrix)
//	{
//		for (T element : row)
//		{
//			cout << setw(7) << element << " ";
//		}
//
//		cout << endl;
//	}
//}

template<typename T>
T** generateMatrix(int rowsCount, int columnsCount)
{
	T** result = new T*[rowsCount];

	for (int i = 0; i < rowsCount; i++)
	{
		result[i] = new T[columnsCount];
	}

	return result;
}

//template<typename T>
//T* getRowsPeekElements(T **matrix, Peek epeek)
//{
//	int rowsCount = sizeof(matrix) / sizeof(matrix[0]);
//	T* result = new T[rowsCount];
//	int i = 0;
//
//	if (epeek == Max)
//	{
//		for (T* sequence : matrix)
//		{
//			result[i] = getMaxElement(sequence);
//			i++;
//		}
//	}
//	else
//	{
//		for (T* sequence : matrix)
//		{
//			result[i] = getMinElement(sequence);
//			i++;
//		}
//	}
//
//	return result;
//}

template<typename T>
T getMinElement(T *sequence)
{
	T result = sequence[0];

	for (T element : sequence)
	{
		if (element > result)
		{
			result = element;
		}
	}

	return result;
}

template<typename T>
T getMaxElement(T* sequence)
{
	T result = sequence[0];

	for (T element : sequence)
	{
		if (element < result)
		{
			result = element;
		}
	}

	return result;
}