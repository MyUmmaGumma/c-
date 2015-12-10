#include<iostream>
using namespace std;

int main()
{
	float f = 45.5f;

	int a= 9 ;

	a = f;		// implicit conversion
				// not always correct on 
				// different data types
				// okay here...

	// or

	a = (int) f;	// explicit - C style

	// or

	a = int(f);		// C++ style

	// or

	a = static_cast<int>(f);	
					// Modern C++ style

	cout<<a<<endl;	
}
