#include<iostream>
using namespace std;

class A
{
	int x;

	friend void demo();

	friend void main();
};

void demo()
{
	A a1;

	a1.x = 50;
}

void main()
{
	demo();

	A a1;
	a1.x = 60;

	cout<<a1.x<<endl;
}