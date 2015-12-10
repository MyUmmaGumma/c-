#include<iostream>
using namespace std;

class A
{
	int x;
	static int y;
public:
	A() : x(0){}
	static void setY(int _y)
	{
		y = _y;
	}
	static int getY()
	{
		return y;
	}
	void showAddress()
	{
		printf("x = %u\n",&x);
		printf("y = %u\n",&y);
	}
};

int A::y;

void main()
{
	A::setY(30);

	A a1;
	cout<<a1.getY()<<endl;
	a1.setY(50);

	A a2;
	cout<<a2.getY()<<endl;
	a2.setY(40);

	A a3;
	cout<<a3.getY()<<endl;
	a3.setY(20);

	cout<<a1.getY()<<endl;
	cout<<a2.getY()<<endl;
	cout<<a3.getY()<<endl;
}