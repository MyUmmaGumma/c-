#include<iostream>
using namespace std;

class A
{
	A()
	{
		cout<<"A()"<<endl;
	}
public:
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

class B : public A { public : B() {}};

void main()
{
	B b;
}
