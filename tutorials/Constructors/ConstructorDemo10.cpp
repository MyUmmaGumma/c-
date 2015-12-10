#include<iostream>
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
	void x()
	{
		cout<<"x()"<<endl;
	}
};

class B : public A
{
public:
	B()
	{
		//x();
		A();	// create an anonymous object
		cout<<"B()"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
};

int main()
{
	B obj;
}
