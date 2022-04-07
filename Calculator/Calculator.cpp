#include <iostream>;
using namespace std;
#include "Functions.h";

int main()
{
	cout << "Welcome to calculator" << endl;
	cout << "Please enter first number: ";
	
	float a;
	cin >> a;

	cout << "Enter an operator: ";
	
	char op;
	cin >> op;

	cout << "Enter second number: ";

	float b;
	cin >> b;

	switch (op)
	{
	case '+':
		cout << "Its: " << add(a, b) << endl; break;
	case '-':
		cout << "Its: " << substrack(a, b) << endl; break;
	case '/':
		cout << "Its: " << divide(a, b) << endl; break;
	case '*':
		cout << "Its: " << multiply(a, b) << endl; break;
	default:
		break;
	}

	return 0;
}