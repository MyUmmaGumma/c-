#include<iostream>
using namespace std;

class A
{
	int x;

	friend class B;
};

class B
{
public:
	void accessA()
	{
		A a1;
		a1.x = 50;
		cout<<a1.x<<endl;
	}
};

void main()
{
	B b;
	b.accessA();
}