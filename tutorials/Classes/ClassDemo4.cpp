#include<iostream>
using namespace std;

class A
{
	int x,y;

	void initialize(int _x,int _y)
	{
		x = _x;
		y = _y;
	}

public:
	void setData(int _x,int _y)
	{
		initialize(_x,_y);
	}

	void showData()
	{
		cout<<x<<"\t"<<y<<endl;
	}
	void showAddresses()
	{
		printf("\n&x = %u\n",&x);
		printf("&y = %u\n",&y);
		printf("&setData = %u\n",setData);
		printf("&showData = %u\n",showData);
		printf("&showAddresses = %u\n",showAddresses);
	}
};

int main()
{
	A a1,a2,a3;

	a1.showAddresses();
	a2.showAddresses();
	a3.showAddresses();
}
