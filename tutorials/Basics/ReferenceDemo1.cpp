// no concept of reference to a reference cos its still just a reference
#include<iostream>
using namespace std;

int main()
{
	int x = 5;

	int *y = &x;

	cout<<*y<<endl;

	int &z = x;
	cout<<z<<endl;
}
