#include<iostream>
#include<iomanip>
#include <string>
using namespace std;

enum Peak
{
	Min,
	Max
};

template<typename T>
T** captureMatrix(int& rowsCount, int& columnsCount);
Peak capturePeak();
bool elementsCountIsValid(int elementsCount);
template<typename T>
T* getRowsPeakElements(T** matrix, Peak epeak, const int rowsCount, const int columnsCount);
template<typename T>
T getMaxElement(T* sequence, const int size);
template<typename T>
T getMinElement(T* sequence, const int size);
template<typename T>
void printSequence(T* sequence, const int size);
template<typename T>
T** generateMatrix(const int rowsCount, const int columnsCount);
template<typename T>
T** fillMatrix(T** matrix, const int rowsCount, const int columnsCount);
template<typename T>
void printMatrix(T** matrix, const int rowsCount, const int columnsCount);

int main()
{
	int rowsCount{};
	int columnsCount{};

	auto matrix = captureMatrix<double>(rowsCount, columnsCount);
	cout << "The matrix itself:" << endl;
	printMatrix(matrix, rowsCount, columnsCount);

	Peak peak = capturePeak();
	auto rowsPeakElements = getRowsPeakElements(matrix, peak, rowsCount, columnsCount);
	
	cout << "The peak elements of every row in matrix:" << endl;
	printSequence(rowsPeakElements, rowsCount);
}

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
	auto result = new T * [rowsCount];

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

				if (rawNumber != "0" && !atof(rawNumber.c_str()))
				{
					wrongInput = true;
					cout << "You entered not a number" << endl;
				}
				else
				{
					result[i][y] = atof(rawNumber.c_str());
				}
			} while (wrongInput);
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
			cout << setw(10) << matrix[i][y] << " ";
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
T* getRowsPeakElements(T** matrix, Peak epeak, const int rowsCount, const int columnsCount)
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

bool elementsCountIsValid(int elementsCount)
{
	if (elementsCount < 1)
	{
		return false;
	}

	return true;
}

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

bool isIntNumber(string rawNumber)
{
	return atoi(rawNumber.c_str());
}

int captureRowsCount()
{
	cout << "Enter the rows count: ";
	string rawRowsCount;
	cin >> rawRowsCount;
	int result;

	if (!isIntNumber(rawRowsCount))
	{
		cout << "You entered not a number" << endl;

		return NULL;
	}

	result = atoi(rawRowsCount.c_str());

	if (!elementsCountIsValid(result))
	{
		cout << "The count of rows is less than 1" << endl;

		return NULL;
	}

	return result;
}

int captureColumnsCount()
{
	cout << "Enter the columns count: ";
	string rawColumnsCount;
	cin >> rawColumnsCount;
	int result;

	if (!isIntNumber(rawColumnsCount))
	{
		cout << "You entered not a number" << endl;

		return NULL;
	}

	result = atoi(rawColumnsCount.c_str());

	if (!elementsCountIsValid(result))
	{
		cout << "The count of columns is less than 1" << endl;

		return NULL;
	}

	return result;
}

template<typename T>
T** captureMatrix(int& rowsCount, int& columnsCount)
{
	T** result = nullptr;
	cout << "You are capturing a matrix:" << endl;
	bool errorOccured;

	do
	{
		errorOccured = false;

		rowsCount = captureRowsCount();

		if (rowsCount == NULL)
		{
			errorOccured = true;
		}

		if (!errorOccured)
		{
			columnsCount = captureColumnsCount();

			if (columnsCount == NULL)
			{
				errorOccured = true;
			}
		}

		if (!errorOccured)
		{
			result = generateMatrix<T>(rowsCount, columnsCount);
			result = fillMatrix(result, rowsCount, columnsCount);
			cout << endl;
		}
	} while (errorOccured);

	return result;
}