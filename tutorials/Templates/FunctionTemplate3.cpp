#include<iostream>
#include<string>
using namespace std;

template<class T>
T add(T a,T b)
{
	T c = a + b;
	return c;
}

// specialization for char*

char* add(char* a,char* b)
{
	char* c = new char[strlen(a) + strlen(b) + 1];
	strcpy(c,a);
	strcat(c,b);
	return c;
}

void main()
{
	cout<<add("Tata","Elxsi")<<endl;
}