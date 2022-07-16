#include"stringSorting.h"
#include"capturer.h"

int main()
{
	string stringToSort = captureString();
	cout << "The string which is sorted ascending:" << endl << stringSort(stringToSort) << endl;
	cout << "The string which is sorted descending:" << endl << stringSortDescending(stringToSort);
}