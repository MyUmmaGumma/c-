#include<iostream>
using namespace std;

class A
{
	int x[1000];
public:
	A() 
	{
		cout<<this<<"\t"<<"A()"<<endl;
	}
	A(A& a) 
	{
		cout<<this<<"\t"<<"A(A&)"<<endl;
	}

	~A()
	{
		cout<<this<<"\t"<<"~A()"<<endl;
	}
};

void demo(const A &obj)
{
	A a1;
}

void main()
{
	A a;

	demo(a);
}
