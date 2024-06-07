#include "Binary.h"
#include <math.h>
#include "TextColor.h"

Binary::Binary(string value) : _value(value)
{
	//Fill the value with 0s if it is less than 32 bits
	if (_value.size() < 32)
	{
		_value += string(32 - _value.size(), '0');
	}
}

float Binary::ConvertToDecimal(bool hasAnswer)
{
	//Separate the integer and fractional parts
	char sign = _value[0];
	string Exponent = _value.substr(1, 8);
	string Significand = "1" + _value.substr(9, 23);

	//cout << "Sign = " << sign << endl;
	//cout << "Exponent = " << Exponent << endl;
	//cout << "Significand = " << Significand << endl;

	//Calculate the exponent
	int exp = 0;
	for (int i = 0; i < Exponent.size(); i++)
	{
		exp <<= 1;
		if (Exponent[i] == '1') exp |= 1;
	} 
	exp -= 127;

	if (hasAnswer)
	{
		PrintText("The binary exponent is ", FOREGROUND_WHITE);
		PrintText(Exponent, FOREGROUND_RED);
		PrintText("\nThe decimal exponent is ", FOREGROUND_WHITE);
		PrintText(exp + 127, FOREGROUND_RED);
		PrintText(" - 127 = ", FOREGROUND_RED);
		PrintText(exp, FOREGROUND_RED);
	}
	
	//Calculate the significand

	if (hasAnswer)
	{
		PrintText("\nThe significand is ", FOREGROUND_WHITE);
		PrintText(_value.substr(9, 23), FOREGROUND_GREEN);
		PrintText("\nThe significand after adding '1' ", FOREGROUND_WHITE);
		PrintText(Significand, FOREGROUND_GREEN);
	}

	int intPart = 0;
	float floatPart = 0;
	if (exp >= 0)
	{
		for (int i = 0; i <= exp; i++)
		{
			if (Significand[i] == '1') intPart = (intPart << 1) | 1;
			else intPart = intPart << 1;
		}

		if (hasAnswer)
		{
			PrintText("\nThe integer part is ", FOREGROUND_WHITE);
			PrintText(intPart, FOREGROUND_GREEN);
		}

		for (int i = exp + 1; i < Significand.size(); i++)
		{
			if (Significand[i] == '1') floatPart += pow(0.5f, i - exp);
		}

		if (hasAnswer)
		{
			PrintText("\nThe fractional part is ", FOREGROUND_WHITE);
			PrintText(floatPart, FOREGROUND_RED | FOREGROUND_BLUE * 2);
		}

		floatPart += intPart;
	}
	else
	{
		if (hasAnswer)
		{
			PrintText("\nThe integer part is ", FOREGROUND_WHITE);
			PrintText("0", FOREGROUND_GREEN);
		}
		exp = abs(exp);

		if (exp > 23)
		{
			if (hasAnswer)
			{
				PrintText("\nValue: 0", FOREGROUND_BLUE | FOREGROUND_GREEN);
				return 0;
			}
		}


		for (int i = exp; i < Significand.size() - exp; i++)
		{
			if (Significand[i - exp] == '1') floatPart += pow(0.5f, i);
		}
	}

	if (hasAnswer)
	{
		PrintText("\nThe decimal value is ", FOREGROUND_WHITE);
		PrintText("Sign: ", FOREGROUND_WHITE);
		PrintText(sign, FOREGROUND_BLUE);
		PrintText(" => ", FOREGROUND_WHITE);
		PrintText(sign == '0' ? "+" : "-", FOREGROUND_GREEN);
		PrintText("\nValue: ", FOREGROUND_BLUE | FOREGROUND_GREEN);
		PrintText((sign == '0' ? 1 : -1) * floatPart, 10 | FOREGROUND_BLUE);
	}

	return (sign == '0' ? 1 : -1) * floatPart;
}