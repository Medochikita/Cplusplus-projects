#include <iostream>

using std::endl;
using std::cout;
using std::cin;

int main()
{
	float x1 = 0, x2 = 0, a = 0, b = 0, c = 0;

	cout << "enter a: ";
	cin >> a;
	cout << "enter b: ";
	cin >> b;
	cout << "enter c: ";
	cin >> c;

	x1 = (-b + (b * b - 4 * a * c)) / 2 * a;
	x2 = (-b - (b * b - 4 * a * c)) / 2 * a;

	cout << "x1 = " << x1 << endl;
	cout << "x2 = " << x2 << endl;

	return 0;
}