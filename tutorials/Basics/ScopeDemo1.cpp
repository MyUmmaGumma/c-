// when using the scope resolution operator the :: referes to the global scope
//x value and not the one defined in the main fuvnction
#include<iostream>
using namespace std;

int x = 50;

int main()
{
	int x = 10;
	cout<<x<<endl;
	cout<< ::x<<endl;

	{
		int &X = x;
		cout<<X<<endl;
		X++;
		int x=20;
		cout<<x<<endl;
		cout<< ::x<<endl;
	}

	cout<<x<<endl;
}
