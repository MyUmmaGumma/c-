#include<iostream>
#include<vector>
using namespace std;

class A
{
	int x;
public:	
	int& getX()
	{
		return x;
	}
	const int& getX() const
	{
		cout<<"Const object"<<endl;
		return x;
	}
	void show()
	{
		cout<<x<<endl;
	}
};

void demo(const A& a) 
{
	cout<<"Making the call"<<endl;
	cout<<a.getX()<<endl;
}

int main()
{
	A a;

	a.getX() = 100;

	cout<<a.getX()<<endl;

	demo(a);
}
