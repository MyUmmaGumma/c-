#include<iostream>
using namespace std;

#define SIZE 5

void allocate(char** &str,int size,char *s)
{
	str = new char*[size];
	for(int i=0;i<size;++i)
	{
		str[i] = new char[strlen(s)+1];
		strcpy(str[i],s);
	}
}

void display(char **str,int size)
{
	for(int i=0;i<size;++i)
		cout<<str[i]<<endl;	
}

void deallocate(char** str,int size)
{
	for(int i=0;i<size;++i)
		delete str[i];
	delete[] str;
}

void main()
{
	char *s = "TATA ELXSI";

	char **str = 0;

	printf("%u\n",str);

	allocate(str,SIZE,s);

	printf("%u\n",str);

	display(str,SIZE);

	deallocate(str,SIZE);
}