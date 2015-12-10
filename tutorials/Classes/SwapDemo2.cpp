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

void swap(A& a,B& b)
{
	// Another Crazy implementation
	
	void *t1 = (void*) &a;	// Successful
	void *t2  = (void*) &b;	// Successful
	void *t3 = malloc(sizeof(A));

	memcpy(t3,t1,sizeof(A));
	memcpy(t1,t2,sizeof(A));
	memcpy(t2,t3,sizeof(A));
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
