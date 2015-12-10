#include<iostream>
using namespace std;

#define ADD(a,b) a + b

void main()
{
	cout<<ADD(34,45)<<endl;

	cout<<ADD("A",32)<<endl;
			// macros are not type safe
}