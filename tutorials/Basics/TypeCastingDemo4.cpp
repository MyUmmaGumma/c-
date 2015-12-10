#include<iostream>
using namespace std;

struct Node
{
	int a,b;
};

int main()
{
	int *a;

	void *x = malloc(8);
	
	a = (int*) x;		// C style

	a[0] = 10;
	a[1] = 20;

	Node *p = (Node*) x;	

	cout<<a[0]<<"\t"<<a[1]<<endl;
	cout<<p->a<<"\t"<<p->b<<endl;
}
