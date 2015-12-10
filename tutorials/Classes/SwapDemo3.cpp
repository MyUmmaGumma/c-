// it is a mystery how this works
#include<iostream>
using namespace std;

struct A
{
	int x,y;
public:
	void init(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	void setX(int _x)
	{
		x = _x;
	}
	int getX()
	{
		return x;
	}
	void setY(int _y)
	{
		y = _y;
	}
	int getY()
	{
		return y;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

struct B
{
	int x,y;
public:
	void init(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	void setX(int _x)
	{
		x = _x;
	}
	int getX()
	{
		return x;
	}
	void setY(int _y)
	{
		y = _y;
	}
	int getY()
	{
		return y;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

void swapValues(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(A& a,B& b)
{
/*	swapValues(a.getX(),b.getX());
	swapValues(a.getY(),b.getY());	*/

	swapValues(a.x,b.x);
	swapValues(a.y,b.y);	
}

int main()
{
	A a;
	B b;

	a.init(10,20);
	b.init(30,40);

	cout<<"Before swapping"<<endl;
	a.show();
	b.show();

	swap(a,b);

	cout<<"After swapping"<<endl;
	a.show();
	b.show();
}
