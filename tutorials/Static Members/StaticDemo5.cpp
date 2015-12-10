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
//		this->x = _y;

//		this->showAddress();
	}
	static int getY()
	{
		return y;
	}
	void showAddress()
	{
		printf("x = %u\n",&x);
		printf("y = %u\n",&y);

		setY(100);

		y = 60;
	}
};

int A::y;

void main()
{
	A::setY(30);
}