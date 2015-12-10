#include<iostream>
using namespace std;

int main()
{
	int x = 5;

	int& y = x;

	const int& z = x;

	cout<<x<<endl;
	cout<<++y<<endl;
	 //cout<<++z<<endl;
}
