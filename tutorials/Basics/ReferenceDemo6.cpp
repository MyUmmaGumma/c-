#include<iostream>
using namespace std;

struct A
{
	int x[1000];
};


void demo(A a)		// CBV == CALL BY VALUE
{

}

void demo(const A& a)		// const &
{

}

int main()
{
	A a;

	cout<<sizeof(A)<<endl;

	demo(a);
}
