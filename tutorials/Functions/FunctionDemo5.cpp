#include<iostream>
using namespace std;

// Error - default from right to left only

int add(int a=30,int b)
{
	return a + b;
}

float add(float a,float b)
{
	cout<<"here..."<<endl;
	return a + b;
}

void main()
{
	cout<<add(34,45)<<endl;
	cout<<add(34)<<endl;
	// cout<<add()<<endl;
}