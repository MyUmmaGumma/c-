#include<iostream>
#include<string>
using namespace std;

template<class T1,class T2>
class A
{
	T1 x;
	T2 y;
public:
	A();
	A(T1 _x,T2 _y);
	void show();
};

template<class T1,class T2>
A<T1,T2>::A() : x(T1()), y(T2()) { }

template<class T1,class T2>
A<T1,T2>::A(T1 _x,T2 _y) : x(_x), y(_y) { }

template<class T1,class T2>
void A<T1,T2>::show()
{
	cout<<x<<"\t"<<y<<endl;
}

void main()
{
	A<int,double> obj(45,56.7);

	obj.show();
}
