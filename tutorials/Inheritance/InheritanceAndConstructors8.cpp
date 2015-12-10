#include<iostream>
#include<string>
using namespace std;

class A
{
	int x,y,z;
public:
	A() : x(0), y(0) {	}
	A(int _x,int _y) : x(_x), y(_y), z(_y) {}
	A(A& a) : x(a.x), y(a.y), z(a.z) { }
	void showXY()
	{
		cout<<x<<"\t"<<y<<"\t"<<z<<endl;
	}
};

class B : public A
{
	int p,q;
public:
	B() : p(0), q(0) { }
	B(int _p,int _q,int _x,int _y) : p(_p), q(_q), 
		A(_x,_y) { 	}
	B(B& b)  : p(b.p), q(b.q), A(b) { }
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

void demo(B b)
{
	b.showAll();
}

void demo(B* b)
{
	b->showAll();
}

void main()
{
	B b(10,20,30,40);
	b.showAll();

	demo(b);
	demo(&b);
}