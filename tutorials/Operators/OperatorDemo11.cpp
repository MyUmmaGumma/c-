#include<iostream>
#include<cstdlib>
using namespace std;

class A
{
	int x,y;
public:
	A() : x(0), y(0) {}
	A(int _x,int _y) : x(_x), y(_y) { }
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
	A* operator->()
	{
		return this;
	}
};

void demo(A &a)
{
	a->show();

	// and many other such functions are used...
}

void main()
{
	A *a = new A(10,20);

	demo(*a);
}