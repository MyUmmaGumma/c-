#include<iostream>
#include<cstdlib>
using namespace std;

class A
{
	int x,y;
	int z[1000000];
public:
	A() : x(0), y(0) {}
	A(int _x,int _y) : x(_x), y(_y) 
	{
		cout<<"A(int _x,int _y) : x(_x), y(_y) "<<endl;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
	void* operator new(size_t size)
	{
		cout<<"Inside our new"<<endl;

		void *p = malloc(size*1000);

		cout<<p<<endl;

		if(p==0)
			throw bad_alloc();

		return p;
	}
	void operator delete(void *p)
	{
		cout<<"Inside our delete"<<endl;

		cout<<p<<endl;

		free(p);
	}
};

void main()
{
	try
	{
		A *a = new A(1,2);

		cout<<a<<endl;

		a->show();

		delete a;
	}
	catch(bad_alloc ba)
	{
		cout<<"Unable to allocate memory"<<endl;
	}
}