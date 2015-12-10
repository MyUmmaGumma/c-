#include<iostream>
using namespace std;

class A
{
	int x,y;
public:
	void setData(int _x,int _y)
	{
		x = _x;
		y = _y;
	}
	void showData()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

void main()
{
	A obj;

//	obj.x = 10;	// Error
	
	obj.setData(10,20);
	obj.showData();
}
