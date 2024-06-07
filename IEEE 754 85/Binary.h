#pragma once
#include <iostream>
using namespace std;

class Binary
{
private:
	string _value;

public:
	Binary(string value);

	float ConvertToDecimal(bool hasAnswer);
};