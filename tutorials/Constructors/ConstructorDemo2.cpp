#include<iostream>
using namespace std;

class A
{
	A()
	{
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
public:
	static A* create()
	{
		return (A*) malloc(sizeof(A));
	}
};

int main()
{
	A *obj = (A*) malloc(sizeof(A));

	A *obj2 = A::create();
}
