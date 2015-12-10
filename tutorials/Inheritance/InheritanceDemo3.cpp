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
	int a,b;
};

class C : B 
{
	int p,q;
};

int main()
{
	cout<<sizeof(A)<<endl;
	cout<<sizeof (B)<<endl;
	cout<<sizeof (C)<<endl;
}
