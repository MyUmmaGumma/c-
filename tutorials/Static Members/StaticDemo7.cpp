#include<iostream>
using namespace std;

class A
{
	static int count;
public:
	A()
	{
		++count;
	}
	~A()
	{
		--count;
	}
	static int getCount()
	{
		return count;
	}
};

int A::count;

void main()
{
	cout<<"No of objects : "<<A::getCount()<<endl;

	{
		A a1,a2;
		cout<<"No of objects : "<<A::getCount()<<endl;

		{
			A a3,a4;
			cout<<"No of objects : "<<A::getCount()<<endl;
		}
		cout<<"No of objects : "<<A::getCount()<<endl;
	}
	cout<<"No of objects : "<<A::getCount()<<endl;
}