#include<iostream>
using namespace std;

class A
{
public:
	A();
	~A();
};

A::A()
{
	cout<<"Object created"<<endl;
}

A::~A()
{
	cout<<"Object destroyed"<<endl;
}

void main()
{
	{
		A obj;
	}
	cout<<"Out of the block"<<endl;
}
