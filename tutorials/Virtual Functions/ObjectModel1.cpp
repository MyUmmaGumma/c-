#include<iostream>
#include<string>
using namespace std;

typedef int (*PF)();
typedef void(*CONSTRUCTOR)(int _x,int _y);

struct A
{
	int x,y;
	CONSTRUCTOR init;
	PF opn;	
}*This;

void construct(int _x,int _y)
{
	This->x = _x;
	This->y = _y;
}

int add()
{
	return This->x + This->y;
}

int subtract()
{
	return This->x - This->y;
}

A* factory(int _x,int _y,int type)
{
	A *a = (A*) malloc(sizeof(A));
	a->init = construct;
	This = a;
	a->init(_x,_y);
	if(type==1)
		a->opn = add;
	else
		a->opn = subtract;

	return a;
}

void client(A *obj)
{
	This = obj;
	cout<<obj->opn()<<endl;		// late binding
}

void main()
{
	int type;
	cout<<"Type : ";
	cin>>type;

	client(factory(10,20,type));

	
}