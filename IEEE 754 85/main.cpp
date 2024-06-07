#include "Binary.h"
#include "Decimal.h"
#include "TextColor.h"
using namespace std;

int main()
{
	//Menu 
	int choice = 0;
	do
	{
		cout << "\n------------------------------------" << endl;
		PrintText("IEEE 754 85\n", 10 | FOREGROUND_BLUE);
		PrintText("1. Convert Decimal to Binary\n", FOREGROUND_RED | FOREGROUND_BLUE * 2);
		PrintText("2. Convert Binary to Decimal\n", FOREGROUND_RED | FOREGROUND_BLUE * 2);
		PrintText("3. Exit\n", FOREGROUND_WHITE | FOREGROUND_BLUE * 2);
		cout << "------------------------------------" << endl;
		PrintText("Enter your choice: ", FOREGROUND_GREEN | FOREGROUND_BLUE * 2);
		cin >> choice;

		switch (choice)
		{
		case 1:
		{
			float value;
			cout << "Enter a decimal number: ";
			cin >> value;
			Decimal dec(value);
			dec.ConvertToBinary(true);
			cout << endl;
			break;
		}
		case 2:
		{
			string value;
			cout << "Enter a binary number: ";
			cin >> value;
			Binary bin(value);
			bin.ConvertToDecimal(true);
			cout << endl;
			break;
		}
		case 3:
			break;
		default:
			cout << "Invalid choice" << endl;
			break;
		}
	} while (choice != 3);
	return 1;

}