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

void main()
{
	Base b;
	Derived d;

	b.show();
	d.show();

	b = d;
	b.show();
	
//	d = b;			// Error
	
	// d = (Derived)(b);	// Error

	((Derived)(d)).show();

	// or

	((Base)(d)).show();		

	// or

	// ((Derived)(b)).show();	// Error
}