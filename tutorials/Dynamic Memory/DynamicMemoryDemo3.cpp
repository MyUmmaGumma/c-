#include<iostream>
using namespace std;

class A
{
	int *x;
public:
	A()
	{
		x = new int[10];
		cout<<"A()"<<endl;
	}
	~A()
	{
		cout<<x<<endl;
		delete[] x;
		cout<<"~A()"<<endl;
	}
};

void main()
{
	A *a = (A*) malloc(sizeof(A));

	delete a;
}
