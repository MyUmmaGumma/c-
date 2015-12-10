#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	A(int x,int y) {}
	A(A& a)
	{
		cout<<"A(A&)"<<endl;
	}
	A& operator=(A& a)
	{
		cout<<"operator =(A)"<<endl;
		return *this;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

int main()
{
	A a1 = A();		// anonymous object is ignored
					// initialization object
					// explicit call to 
					// default constructor
	
	//a1 = A(45,56);	// invoke a constructor 
					// more than once

	// a1.A(45,56);

	A();		// anonymous object on the stack

	cout<<"Done"<<endl;
}
