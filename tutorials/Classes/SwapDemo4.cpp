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

class B
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
	int temp;
	
	temp = a.getX();
	a.setX(b.getX());
	b.setX(temp);

	temp = a.getY();
	a.setY(b.getY());
	b.setY(temp);

	// Error

//	swapValues(a.getX(),b.getX());
//	swapValues(a.getY(),b.getY());
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
