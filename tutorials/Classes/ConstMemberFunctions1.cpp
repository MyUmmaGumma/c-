// illustrates const cast usage
#include<iostream>
using namespace std;

class A
{
	int x;
public:	
	void setX(int _x)
	{
		x = _x;
	}
	int getX()
	{
		return ++x;
	}
	void show()
	{
		cout<<x<<endl;
	}
};

void demo(const A& a)
{
//	a.setX(200);	// Illegal

	cout<<(const_cast<A&>(a)).getX()<<endl;
}

/*
void demo(A& a)
{
	a.setX(200);

	cout<<a.getX()<<endl;
}
*/

void main()
{
	A a;

	a.setX(100);

	cout<<a.getX()<<endl;

	demo(a);

	a.show();
}
