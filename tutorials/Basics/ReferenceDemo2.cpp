//this last cout of x is a mystery
#include<iostream>
using namespace std;

int main()
{
	int x = 5;

	int &z = x;

	cout<<x<<endl;	
	cout<<z++<<endl;
	cout<<x<<endl;	

	int y =  10;
	z = y;

	cout<<y<<endl;
	cout<<z++<<endl;
	cout<<y<<endl;

	cout<<x<<endl;
}
