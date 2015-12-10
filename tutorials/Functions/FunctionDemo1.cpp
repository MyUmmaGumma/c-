#include<iostream>
using namespace std;

int add(int a,int b)
{
	return a + b;
}

char* add(char* a,char *b)
{
	char *s = (char*) malloc(strlen(a) + strlen(b) + 1);
	strcpy(s,a);
	strcat(s,b);
	return s;
}


void main()
{
	cout<<add(34,45)<<endl;

	cout<<add("abc",56)<<endl;
}