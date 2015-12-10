#include<iostream>
using namespace std;
// const objects can call const member fubctions only
class A
{
	int x;
public:	
	void setX(int _x)
	{
		x = _x;
	}
	int getX() const
	{
		return x;
	}
	void show()
	{
		cout<<x<<endl;
	}
};

void demo(const A& a) 
{
//	a.setX(200);	// Illegal

	cout<<a.getX()<<endl;

//	a.show();
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
