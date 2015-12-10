#include<iostream>
using namespace std;

class A
{
protected:
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

class B : public A { };

void main()
{
	B b;

//	A a;
}
