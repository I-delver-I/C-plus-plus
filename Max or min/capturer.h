#pragma once
#include"capturer.h"
#include"peak.h"
#include"validator.h"
#include"matrixFunctions.h"
#include<iostream>
using namespace std;

Peak capturePeak();
int** captureMatrix(int& rowsCount, int& columnsCount);