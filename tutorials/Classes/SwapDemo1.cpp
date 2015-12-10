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
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

void swap(int& a,int& b)
{
	int temp = a;
	a = b;
	b = temp;
}

void swap(A& a,B& b)
{
	// swap the respective values here...
	
	struct Temp
	{
		int x,y;
	};

	// Crazy implementation
	
	Temp *t1 = (Temp*) &a;	// Successful
					// or
	// Temp *t1 = reinterpret_cast<Temp*>(&a);

	Temp *t2  = (Temp*) &b;	// Successful

	swap(t1->x,t2->x);
	swap(t1->y,t2->y);	
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
