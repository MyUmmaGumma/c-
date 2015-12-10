#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

int main()
{
	A *a = new A;

	a->~A();

	delete a;
}
