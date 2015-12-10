#include<iostream>
using namespace std;

class A
{
	int *x;
	int y;
	int z;
public:
	A()
	{
		x = new int[10];
		for(int i=0;i<10;++i)
			x[i] = i+1;
		cout<<"A()"<<endl;
	}
	~A()
	{
		delete[] x;
		cout<<"~A()"<<endl;
	}
	int* get()
	{
		return x;
	}
};

void main()
{
	cout<<sizeof A<<endl;

	int *x;

	A *a = new A;

	x = a->get();

	cout<<x[0]<<endl;

	free(a);

	cout<<x[0]<<endl;
}
