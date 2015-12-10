#include<iostream>
using namespace std;

void main()
{
	int *p = (int*) malloc(sizeof(int));
	*p = 100;
	cout<<*p<<endl;

	int *q = new int;
	*q = 100;
	cout<<*q<<endl;

	int *a = new int(100);
	cout<<*a<<endl;

	int size = 10;
	int i;

	int *x = (int*) malloc(sizeof(int)*size);
	for(i=0;i<size;++i)
		x[i] = i+1;

	int *y = new int[size];
	for(i=0;i<size;++i)
		y[i] = i+1;

	for(i=0;i<size;++i)
		cout<<x[i]<<"\t";
	cout<<endl;

	for(i=0;i<size;++i)
		cout<<y[i]<<"\t";
	cout<<endl;

	free(p);
	delete q;
	delete a;		// delete a single value

	free(x);		
	delete[] y;		// delete an array
}
