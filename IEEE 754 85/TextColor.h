#pragma once
#include "Windows.h"
#include <iostream>

#define FOREGROUND_WHITE 0x0007

template <class T>
void PrintText(T mData, WORD wAttributes = FOREGROUND_WHITE)
{
	HANDLE hConsole = GetStdHandle(STD_OUTPUT_HANDLE);
	SetConsoleTextAttribute(hConsole, wAttributes);
	std::cout << mData;
	SetConsoleTextAttribute(hConsole, FOREGROUND_WHITE);
}