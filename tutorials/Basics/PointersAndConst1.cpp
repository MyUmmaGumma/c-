#include<iostream>
using namespace std;

void demo(const int *x)
{
	cout<<*x<<endl;		// Read

//	*x = 10;			// Write

	x = (int*) malloc(sizeof(int));	// Allocate

	free(x);			// Deallocate

}

int main()
{
	int *x = (int*) malloc(sizeof(int));
	*x = 100;

	demo(x);
}
