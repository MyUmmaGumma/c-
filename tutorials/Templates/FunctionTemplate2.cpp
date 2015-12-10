#include<iostream>
#include<string>
using namespace std;

template<class T>
T add(T a,T b)
{
	T c = a + b;
	return c;
}

void main()
{
	// impicit instantiation

	cout<<add(1,2)<<endl;	
	cout<<add(11.4,22.6)<<endl;
	cout<<add(12.4f,22.6f)<<endl;

	// explicit instantiation

	cout<<add<int>(45,56)<<endl;

	cout<<add<string>("Tata","Elxsi")<<endl;
}