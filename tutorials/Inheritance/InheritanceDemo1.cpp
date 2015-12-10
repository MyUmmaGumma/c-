#include<iostream>
#include<string>
using namespace std;

class A
{
	int x;
protected:
	int y;
public:
	int z;
};

class B : A			// private by default
{
public:
	void accessBaseData()
	{
		// x = 10;	- Error
		y = 20;
		z = 30;
	}
};

class C : protected A
{
public:
	void accessBaseData()
	{
		// x = 10;	- Error
		y = 20;
		z = 30;
	}
};

class D : public A
{
public:
	void accessBaseData()
	{
		// x = 10;	- Error
		y = 20;
		z = 30;
	}
};

void main()
{
	A a;
	
//	a.x = 10;	- Error
//	a.y = 20;	- Error
	a.z = 30;

	B b;

//	b.x = 10;	- Error
//	b.y = 20;	- Error
//	b.z = 30;

	C c;
//	c.x = 10;	- Error
//	c.y = 20;	- Error
//	c.z = 30;

	D d;
//	d.x = 10;	- Error
//	d.y = 20;	- Error
	d.z = 30;
}