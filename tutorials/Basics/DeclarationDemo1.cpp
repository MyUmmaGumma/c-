#include<iostream>
using namespace std;

int main()
{
	int x,y;

	{				// Control the lifetime explicitly
		int z[10000];

		//
		//
		//
	}

	int z;

	cout<<z;
return 0;
}
