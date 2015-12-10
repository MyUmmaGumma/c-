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

void main()
{
	//A *a = (A*) malloc(sizeof(A));

	A *a2 = new A;

	// free(a);

	delete a2;
}
