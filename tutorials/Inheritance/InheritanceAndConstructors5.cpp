#include<iostream>
#include<string>
using namespace std;

class A
{
	int x,y;
public:
	A() : x(0), y(0) {	}
	A(int _x,int _y) : x(_x), y(_y) {}
	A(A& a) : x(a.x), y(a.y) { }
	void showXY()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

class B : public A
{
	int p,q;
public:
	B() : p(0), q(0) { }
	B(int _p,int _q) : p(_p), q(_q) { }
	B(B& b)  : p(b.p), q(b.q) { }
	void showAll()
	{
		cout<<p<<"\t"<<q<<endl;
		// cout<<x<<"\t"<<y<<endl;		// Error
			// Cannot access private data of Base class
		showXY();
		// Can indirectly access the private data of
		// Base class through a public method
		// as memory is allocated, but accessibility
		// is only through a method of the base class
	}
};

void main()
{
	B b(10,20);
	b.showAll();
}