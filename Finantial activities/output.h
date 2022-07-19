#pragma once
#include<vector>
#include<iostream>
using namespace std;

template<typename T>
void printCollection(vector<T> collection)
{
	for (T element : collection)
	{
		cout << element << endl;
	}
}

void printHorizontalRule();