#include<iostream>
#include<string>
using namespace std;

class Base
{
	int *x;
public:
	Base()
	{
		cout<<"Memory allocated for x..."<<endl;
		x = new int[100];
	}
	~Base()
	{
		cout<<"Memory release for x..."<<endl;
		delete[] x;
	}
};

class Derived : public Base
{
	int *y;
public:
	Derived()
	{
		cout<<"Memory allocated for y..."<<endl;
		y = new int[50];
	}
	~Derived()
	{
		cout<<"Memory release for y..."<<endl;
		delete[] y;
	}
};

int main()
{
	Base *b = new Derived;

	delete b;
}
