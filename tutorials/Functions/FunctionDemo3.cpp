#include<iostream>
using namespace std;

int x()
{
	int a = 10;
	return a;
}

double x()
{
	double b = 45.5;
	return b;
}

void main()
{
	int a = x();
	cout<<a<<endl;

	double b = x();
	cout<<b<<endl;
}