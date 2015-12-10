#include<iostream>
using namespace std;

int main()
{
	int x = 5;

	int &ref = x;
	cout<<ref<<endl;

	int *ref2 = &x;
	cout<<*ref2<<endl;
}
