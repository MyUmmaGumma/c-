#include<iostream>
using namespace std;

class A
{
	int x[1000];
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

A demo(const A& obj)
{
	A a1;
	return a1;
}

int main()
{
	A a1,a2;

	a2 = demo(a1);
}
