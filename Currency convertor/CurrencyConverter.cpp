#include <iostream>
using namespace std;

float conversion(float first, string firstCurrency, string secondCurrency)
{
	if (firstCurrency == "USD" && secondCurrency == "CZK")
	{
		return first * 22;
	}
	else if (firstCurrency == "EUR" && secondCurrency == "CZK")
	{
		return first * 26;
	}
	else if (firstCurrency == "CZK" && secondCurrency == "USD")
	{
		return first / 22;
	}
	else if (firstCurrency == "CZK" && secondCurrency == "EUR")
	{
		return first / 26;
	}
	else
	{
		return 1;
	}
}

int main()
{
	cout << "CURRENCY CONVERTOR" << endl;
	
	float firstCurrVal;
	string firstCurr;
	
	cout << "Enter first value: ";
	cin >> firstCurrVal;

	cout << "Enter what currency it is: ";
	cin >> firstCurr;

	string secondCurr;

	cout << "Enter what currency to convert to: ";
	cin >> secondCurr;

	cout << "The value is: " << conversion(firstCurrVal, firstCurr, secondCurr) << endl;

	return 0;
}