#include<iostream>
using namespace std;

int getValue(int x)
{
	return rand()%x;
}

int& largest(int &x,int &y,int &z)
{
	return x>y ? (x>z ? x : z) : (y>z ? y : z);
}

int main()
{
	int x,y,z;

	cout<<"Enter 3 numbers : "<<endl;
	cin>>x>>y>>z;

	int ran;
	cout<<"Enter the seed : ";
	cin>>ran;

	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"z = "<<z<<endl;

	largest(x,y,z) = getValue(ran);
	
	cout<<"x = "<<x<<endl;
	cout<<"y = "<<y<<endl;
	cout<<"z = "<<z<<endl;	
}
