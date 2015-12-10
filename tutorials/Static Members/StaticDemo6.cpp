#include<iostream>
using namespace std;

class A
{
public:
	virtual static void demo()
	{
		cout<<"A demo"<<endl;
	}
};

class B : public A
{
public:
/*	static void demo()
	{
		cout<<"B demo"<<endl;
	}*/
};

void main()
{
	B::demo();
}