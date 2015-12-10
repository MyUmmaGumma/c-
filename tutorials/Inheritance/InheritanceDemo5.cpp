#include<iostream>
#include<string>
using namespace std;

class A
{
	int x;				// 4 bytes
};

class B : public A
{
	int y;				// 8 bytes
};

class C : public A			
{
	int z;				// 8 bytes
};

class D : public B,public C
{
	int p,q;			// 24 bytes
};

void main()
{
	cout<<sizeof A<<endl;
	cout<<sizeof B<<endl;
	cout<<sizeof C<<endl;	
	cout<<sizeof D<<endl;
}