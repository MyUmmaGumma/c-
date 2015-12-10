#include<iostream>
using namespace std;

int main()
{
	int x = 5;

	int &ref = x;
	cout<<ref<<endl;

	int *ref2 = &x;
	cout<<*ref2<<endl;

	int y = 10;

	ref = y;

	// *ref = y;

	int &ref3 = ref;
	ref3++;
	cout<<ref3;
	// int *ref3 = &(*ref);
}
