#include<iostream>
using namespace std;

// instead use default arguments
// avoid overloading...

int add(int a,int b)
{
	return a + b;
}

int add(int a)
{
	return a + 30;
}

int add()
{
	return 20 + 30;
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
	cout<<add()<<endl;
}