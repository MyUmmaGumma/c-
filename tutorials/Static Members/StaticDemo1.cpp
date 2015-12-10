#include<iostream>
using namespace std;

class A
{
	int x;
	static int y;
public:
	static void setY(int _y)
	{
		y = _y;
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
	A a1,a2,a3;

	a1.showAddress();
	a2.showAddress();
	a3.showAddress();
}