#include<iostream>
using namespace std;

class Ostream
{
public:
	void operator<<(char* str)
	{
		printf("%s",str);
	}
	void operator<<(int str)
	{
		printf("%d",str);
	}
}Cout;

int  main()
{
	cout<<"hello\n";

	int x = 5;
	cout<<x;

	Cout<<"hello\n";	
		// Cout.operator<<("hello\n");

	Cout<<x;
}
