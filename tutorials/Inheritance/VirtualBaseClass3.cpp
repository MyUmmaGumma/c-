#include<iostream>
#include<string>
using namespace std;

class A
{
	int x[100];			// 400 bytes
};

class B : virtual public A
{
	int x,y;			// 412 bytes
};

class C :  virtual public A
{
	int p;				// 408 bytes
};

class D : public B, public C
{
	int i,j;			// 428 bytes
};

void main()
{
	A a;
	B b;
	C c;
	D d;

	cout<<sizeof A<<endl;
	cout<<sizeof B<<endl;
	cout<<sizeof C<<endl;
	cout<<sizeof D<<endl;
}