#include<iostream>
#include<string>
using namespace std;

class A
{
	int x[100];			// 400 bytes
};

class B : public A
{
	int x,y;			// 408 bytes
};

class C :  public A
{
	int p;				// 404 bytes
};

class D : virtual public B, virtual public C
{
	int i,j;			// 820 bytes
};

int main()
{
	cout<<sizeof (A)<<endl;
	cout<<sizeof (B)<<endl;
	cout<<sizeof (C)<<endl;
	cout<<sizeof (D)<<endl;
}
