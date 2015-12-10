#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	virtual void show()
	{
		cout<<"Base"<<endl;
	}
};

class Derived : public Base
{
public:
	void show()		// Method Over-riding
	{
		cout<<"Derived"<<endl;
	}
};

void client(Base &b)
{
	b.show();		// Late Binding
}

void client(Base *b)
{
	b->show();		// Late Binding
}

void main()
{
	client(Base());
	client(Derived());

	client(new Base());
	client(new Derived());
}