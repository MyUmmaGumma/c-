#include<iostream>
#include<string>
using namespace std;

#define ADD(x,y) x + y

int add(int a,int b)
{
	int c = a + b;
	return c;
}

double add(double a,double b)
{
	double c = a + b;
	return c;
}

float add(float a,float b)
{
	float c = a + b;
	return c;
}

void main()
{
	cout<<add(1,2)<<endl;
	cout<<add(1.4,2.6)<<endl;
	cout<<add(1.4f,2.6f)<<endl;
}