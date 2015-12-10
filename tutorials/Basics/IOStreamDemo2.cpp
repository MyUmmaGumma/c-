#include<iostream>
using namespace std;

class Ostream
{
public:
	Ostream operator<<(char* str)
	{
		printf("%s",str);
		return Cout;
	}
	Ostream operator<<(int str)
	{
		printf("%d",str);
		return Cout;
	}
}Cout;

nt main()
{
	int x = 5;
	cout<<"hello\n"<<x<<"\n";

	Cout<<"hello\n"<<x<<"\n"<<x;		
}
