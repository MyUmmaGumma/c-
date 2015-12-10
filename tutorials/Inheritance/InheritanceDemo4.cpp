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

class B : A			// Single-level
{
	int a,b;
};

class C : B			// Multi-level
{
	int p,q;
};

class D {};

class E : public A, public D {};	// Multiple

void main()
{
	cout<<sizeof A<<endl;
	cout<<sizeof B<<endl;
	cout<<sizeof C<<endl;
}