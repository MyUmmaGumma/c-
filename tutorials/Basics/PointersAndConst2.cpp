//actually illustrates that operator free frees the memory pointed to
//by its operand. not the operand itself
#include<iostream>
using namespace std;

void demo(const int *x)
{
	cout<<*x<<endl;		// Read

//	*x = 10;			// Write

	x = (int*) malloc(sizeof(int));	// Allocate

//	free(x);			// Deallocate

}

int main()
{
	int *x = (int*) malloc(sizeof(int));
	*x = 100;

	cout<<x<<"\t"<<*x<<endl;

//	demo(x);

	free(x);	// void free(void*);
	
	cout<<x<<"\t"<<*x<<endl;
}
