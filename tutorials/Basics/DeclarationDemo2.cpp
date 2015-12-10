#include<iostream>
using namespace std;

int main()
{
	int x;
	cin>>x;

	for(int i=0;i<x;++i)		// AWD
		cout<<i<<endl;

	cout<<"Outside : "<<i<<endl;

	for(int a=0;a<x;++a)		// AWD
	{
		static int i=0;
		cout<<++i<<endl;
	}
return 0;
}
