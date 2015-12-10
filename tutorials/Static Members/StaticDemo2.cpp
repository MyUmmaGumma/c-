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
	cout<<A::getY()<<endl;

	A::setY(30);

	cout<<A::getY()<<endl;
}