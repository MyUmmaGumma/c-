#include<iostream>
#include<string>
using namespace std;

class Base
{
public:
	void show()
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

void client(Base b)
{
	b.show();		// Early Binding
}

void client(Base *b)
{
	((Base*)b)->show();		// Early Binding
}

int main()
{
	client(Base());
	client(Derived());

	client(new Base());
	client(new Derived());
}
