#include<iostream>
#include<string>
using namespace std;

class A
{
	int x,y;
public:
	A() : x(0), y(0) {}
	A(int _x,int _y) : x(_x), y(_y) {}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

class B : public A
{
	int p;
public:
	B() : p(0) {}
	B(int _p,int _x,int _y) : p(_p), A(_x,_y) {}
	void show()
	{
		A::show();
		cout<<p<<endl;
	}
};

void main()
{
	B b(1,2,3);
	
/*	// A(b).show();	 // - legal 
					 // cast to Base class
	b.show();*/

	B b2 = b;
	b2.show();
}