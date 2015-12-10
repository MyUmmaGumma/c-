#include<iostream>
using namespace std;

class A
{
	int x,y;
public:
	void init(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	int& getX()
	{
		return x;
	}
	int& getY()
	{
		return y;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

class B
{
	int x,y;
public:
	void init(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	int& getX()
	{
		return x;
	}
	int& getY()
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
	swapValues(a.getX(),b.getX());
	swapValues(a.getY(),b.getY());
}

void main()
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
