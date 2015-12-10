#include<iostream>
#include<string>
using namespace std;

class A
{
	int x[100];				// 400 bytes
};

class B :  virtual public A
{
	int y;				// 404 bytes
};

class C :  virtual public A			
{
	int z;				// 404 bytes
};

class D : public B, public C
{
	int p,q;			// 816 bytes
};

int main()
{
	cout<<sizeof (A)<<endl;
	cout<<sizeof (B)<<endl;
	cout<<sizeof (C)<<endl;	
	cout<<sizeof (D)<<endl;
}
