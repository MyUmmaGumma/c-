#include<iostream>
#include<string>
#include<vector>
using namespace std;

template<class T1,class T2>
class A
{
	T1 x;
	T2 y;
public:
	A() : x(T1()), y(T2()) { }
	A(T1 _x,T2 _y) : x(_x), y(_y) { }
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

void main()
{
	A<int,double> obj(45,56.7);

	obj.show();
}
