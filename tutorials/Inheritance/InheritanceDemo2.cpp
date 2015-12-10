#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	int z;
};

class B : A			// private by default
{
public:
	void accessBaseData()
	{
		z = 10;
	}
};

struct C : A		// public by default
{
public:
	void accessBaseData()
	{
		z = 10;
	}
};

class D : public C {};

void main()
{
	B b;

//	b.z = 30;

	C c;
	c.z = 30;
}