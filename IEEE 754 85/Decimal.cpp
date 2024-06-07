#include "Decimal.h"
#include "TextColor.h"

Decimal::Decimal(float value) : _value(value) {}

string Decimal::ConvertToBinary(bool hasAnswer)
{
	//Sign bit
	char sign = _value < 0 ? '1' : '0';

	if (hasAnswer) {
		PrintText("Because the number is negative, the sign bit is ", FOREGROUND_WHITE);
		PrintText(sign, FOREGROUND_BLUE);
	}
	
	float _temp = _value < 0 ? -_value : _value;

	int intPart = (int)_temp;

	float fracPart = _temp - intPart;

	if (hasAnswer)
	{
		PrintText("\nThe integer part is ", FOREGROUND_WHITE);
		PrintText(intPart, FOREGROUND_GREEN);
		PrintText("\nThe fractional part is ", FOREGROUND_WHITE);
		PrintText(fracPart, FOREGROUND_RED | FOREGROUND_BLUE * 2);
	}

	//Convert Fractional part to binary
	string fracBin = "";
	while (fracPart != 1 && fracPart != 0)
	{
		fracPart *= 2;
		if (fracPart < 1) fracBin += '0';
		else if (fracPart > 1)
		{
			fracBin += '1';
			fracPart -= 1;
		}
		else
		{
			fracBin += '1';
			break;
		}
	}

	//Convert Integer part to binary
	string intBin = "";
	while (true)
	{
		intBin = (intPart % 2 == 0 ? '0' : '1') + intBin;
		intPart = intPart >> 1;
		if (intPart == 0) break;
	}

	if (hasAnswer)
	{
		PrintText("\nThe binary representation of the integer part is ", FOREGROUND_WHITE);
		PrintText(intBin, FOREGROUND_GREEN);
		PrintText("\nThe binary representation of the fractional part is ", FOREGROUND_WHITE);
		PrintText(fracBin, FOREGROUND_RED | FOREGROUND_BLUE * 2);
	}

	string Significand = intBin + fracBin;

	//Add zeros to the right of the significand
	int neededZeros = 23 - Significand.size();
	for (int i = 0; i < neededZeros; i++)
	{
		Significand += '0';
	}

	if (hasAnswer)
	{
				PrintText("\nThe significand is ", FOREGROUND_WHITE);
		PrintText(Significand, FOREGROUND_GREEN);
	}

	//Expontent
	int exp = intBin.size() - 1;
	if (intBin[0] == '0')
	{
		while (Significand[0] == '0')
		{
			exp -= 1;
			Significand.erase(Significand.begin() + 0);
		}
	}


	Significand.erase(Significand.begin() + 0);

	if (hasAnswer)
	{
		PrintText("\nThe exponent is ", FOREGROUND_WHITE);
		PrintText(exp, FOREGROUND_RED);
		PrintText("\nThe significand after multiplying ", FOREGROUND_WHITE);
		PrintText("2^", FOREGROUND_RED);
		PrintText(exp, FOREGROUND_RED);
		PrintText(" is ", FOREGROUND_WHITE);
		PrintText(Significand, FOREGROUND_GREEN);
	}

	string Exponent = "";
	if (exp < 0) exp = (exp - 1) & 0x7F;
	else exp += 127;
	for(int i = 0; i < 8; i++)
	{
		Exponent = (((exp >> i) & 1) == 1 ? '1' : '0') + Exponent;
	}

	if (hasAnswer)
	{
		PrintText("\nThe exponent in binary is ", FOREGROUND_WHITE);
		PrintText(Exponent, FOREGROUND_RED);
	}

	if (hasAnswer)
	{
				PrintText("\nThe IEEE 754 32-bit binary representation of ", FOREGROUND_BLUE | FOREGROUND_GREEN);
		PrintText(_value, FOREGROUND_GREEN);
		PrintText(" is ", FOREGROUND_WHITE);
		PrintText(sign, FOREGROUND_BLUE);
		PrintText(" | ", FOREGROUND_WHITE);
		PrintText(Exponent, FOREGROUND_RED);
		PrintText(" | ", FOREGROUND_WHITE);
		PrintText(Significand, FOREGROUND_GREEN);
	}

	return (sign + Exponent + Significand);
}