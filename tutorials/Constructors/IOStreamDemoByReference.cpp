#include<iostream>
using namespace std;

class Ostream
{
public:
	Ostream()
	{
		cout<<"Ostream()"<<endl;
	}
	~Ostream()
	{
		cout<<"~Ostream()"<<endl;
	}
	Ostream(Ostream& o)
	{
		cout<<"Ostream(Ostream&)"<<endl;
	}
	Ostream& operator<<(char* str)
	{
		printf("%s",str);
		return *this;
	}
	Ostream& operator<<(int str)
	{
		printf("%d",str);
		return *this;
	}
};

void main()
{
	Ostream Cout;
	int x = 5;

	Cout<<"hello\n"<<x<<"\n"<<x;		
}