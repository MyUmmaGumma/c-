#include<iostream>
using namespace std;

class A
{
public:
	A()
	{
		cout<<this<<endl;
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
