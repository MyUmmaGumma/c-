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

class B : public A
{
public:
	B()
	{
		cout<<"B()"<<endl;
	}
	B(int x) 
	{
		cout<<"B(int x)"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
};

void main()
{
	B obj(10);
}