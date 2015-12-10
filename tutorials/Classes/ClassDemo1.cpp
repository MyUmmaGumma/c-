#include<iostream>
using namespace std;

class A
{
	// private by default
// private:
	int x,y;

public:
	void setData(int _x,int _y);
	void showData();
};

inline void A::setData(int _x,int _y)
{
	x = _x;
	y = _y;
}

inline void A::showData()
{
	cout<<x<<"\t"<<y<<endl;
}

int main()
{
	A obj;

//	obj.x = 10;	// Error
	
	obj.setData(10,20);
	obj.showData();
}
