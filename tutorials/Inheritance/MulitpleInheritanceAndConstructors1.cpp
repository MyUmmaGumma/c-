#include<iostream>
#include<string>
using namespace std;

class A
{
public:
	A() 
	{	
		cout<<"A()"<<endl;
	}
	A(A& a)
	{
		cout<<"A(A&)"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
};

class B 
{
public:
	B() 
	{	
		cout<<"B()"<<endl;
	}
	B(B& b)
	{
		cout<<"B(B&)"<<endl;
	}
	~B()
	{
		cout<<"~B()"<<endl;
	}
};

class C : public B, public A
{
public:
	C() : A(), B()
	{	
		cout<<"C()"<<endl;
	}
	C(C& c)	: A(c), B(c)
	{
		cout<<"C(C&)"<<endl;
	}
	~C()
	{
		cout<<"~C()"<<endl;
	}
};

C demo(C c)
{
	C obj;
	return obj;
}

void main()
{
	/*C c1,c2;
	c2 = demo(c1); */

	C obj;
}