#include<iostream>
using namespace std;

class A
{
	int x[1000];
public:
	A() 
	{
		cout<<"A()--"<<this<<endl;
	}
	A(A& a) 
	{
		cout<<"A(A&)--"<<this<<endl;
	}

	~A()
	{
		cout<<"~A()-- "<<this<<endl;
	}
};

A demo(A obj)
{
	A a1;
	return obj;
}

int main()
{
	A a1,a2;

	a2 = demo(a1);
}
