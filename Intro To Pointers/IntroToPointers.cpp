#include <iostream>
using namespace std;

void print(void* pointer, char type) {
	switch (type)
	{
	case 'i': 
		cout << *((int*)pointer) << endl; break;
	case 'c':
		cout << *((char*)pointer) << endl; break;
	}
}

int main()
{
    
	int n = 5;
	char letter = 'c';

	print(&n, 'i');
	print(&letter, 'c');

    return 0;
}
