#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

class B : A
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
};

void main()
{
	B obj;
}