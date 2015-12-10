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
	// A();

	delete new A;	// on the heap
}
