#include<iostream>
using namespace std;

class A
{
	int x;
public:
	virtual A() : x(0)
	{
	}
	A(int _x) : x(_x) {}
	~A()
	{
	}
	void show()
	{
		cout<<x<<endl;
	}
};

int main()
{
	A a(10);

	a.show();

	a = A();

	a.show();
}
