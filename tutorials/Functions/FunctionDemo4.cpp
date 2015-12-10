#include<iostream>
using namespace std;

int add(int a,int b)
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
	cout<<add(float(34.5),float(45.6))<<endl;
}