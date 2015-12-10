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
	A(A& a)
	{
		cout<<"A(A&)"<<endl;
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
	B(int x) // : A()		// by default A()
	{
		cout<<"B(int x)"<<endl;
	}
	B(B& b)  : A(b)
	{
		cout<<"B(B&)"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
};

void main()
{
	B obj(10);

	B b2 = obj;
}