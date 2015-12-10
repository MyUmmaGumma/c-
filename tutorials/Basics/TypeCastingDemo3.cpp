#include<iostream>
using namespace std;

void main()
{
	int *a;

	float *b;

	void *x = malloc(4);
	
	a = (int*) x;		// C style

	// or

	a = (int*)(x);		// C++ style

	// or

	a = reinterpret_cast<int*>(x);
					// Modern style

	*a = 10;
	cout<<a<<"\t"<<*a<<endl;	

	b = (float*) x;
	*b = 45.5f;
	cout<<b<<"\t"<<*b<<endl;
	
	cout<<a<<"\t"<<*a<<endl;	
}