#include<iostream>
using namespace std;

class A
{
	static int x;
public:
	A(int _x)  // : x(_x)	// - Error
	{
		x = _x;
		cout<<"A()"<<endl;
	}
	void f1()
	{
		++x;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

int A::x = 0;

int main()
{
	int x = 100;

	cout<<x<<endl;

	A a(x);

	a.f1();

	cout<<x<<endl;
}
