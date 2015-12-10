#include<iostream>
using namespace std;

class A
{
	const int x;
public:
	A()  : x(100)
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
	A a;
}
