#include<iostream>
using namespace std;

#define ADD(a,b) a + b

inline int add(int a,int b)
{
	return a + b;
}

void main()
{
	cout<<ADD(45,56)<<endl;
	cout<<add("45",56)<<endl;
}