#include<iostream>
using namespace std;

class A
{
	int x;
public:
	A() : x(0)
	{
		cout<<"A()"<<endl;
	}
	A(int _x) : x(_x) 
	{
		cout<<"A(int)"<<endl;
	}
	A(A& a) : x(a.x)
	{
		cout<<"A(A&)"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
	void operator=(const A &a)
	{
		this->x = a.x;
		cout<<"operator = "<<endl;
	}
	void show()
	{
		cout<<x<<endl;
	}
};

int main()
{
	A a[2];

	for(int i=0;i<2;++i)
		a[i] = A(10);

	for(int i=0;i<2;++i)
		a[i].show();
}
