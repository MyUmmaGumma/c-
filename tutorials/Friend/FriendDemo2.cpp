#include<iostream>
using namespace std;

class B;	// forward declaration

void swapValues(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

class A
{
	int x,y;
public:
	void init(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
	friend void swap(A& a,B& b);
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
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
	friend void swap(A& a,B& b)
	{
		swapValues(a.x,b.x);
		swapValues(a.y,b.y);
	}
};

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
