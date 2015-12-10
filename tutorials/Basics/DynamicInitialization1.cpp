#include<iostream>
#include<cstdlib>
using namespace std;

void main()
{
	int x,y;
	cout<<"Enter two numbers : "<<endl;
	cin>>x>>y;

	int z= x + y;	// Dynamic initialization
	cout<<z<<endl;

	// Dynamic initialization promotes cohesion

	int *p;

	p = (int*) malloc(sizeof(int));

	// instead use...

	int *p2 = (int*) malloc(sizeof(int));
	// Never leave a pointer unitialized...
}