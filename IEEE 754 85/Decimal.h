#pragma once
#include <iostream>
using namespace std;

class Decimal
{
private:
	float _value;

public:
	Decimal(float value);

	string ConvertToBinary(bool hasAnswer);

};