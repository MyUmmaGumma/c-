#include<iostream>
using namespace std;

#define SIZE 5

class A
{
	int x,y;
public:
	A() : x(0), y(0) 
	{
		cout<<"A()"<<endl;
	}
	A(int _x,int _y) : x(_x), y(_y) 
	{
		cout<<"A(int,int)"<<endl;
	}
	~A()
	{
		cout<<"~A()"<<endl;
	}
	void show()
	{
		cout<<x<<"\t"<<y<<endl;
	}
};

void display(A x[],int size)
{
	for(int i=0;i<size;++i)
		x[i].show();
}

void main()
{
	int x,y;
	
	cout<<"Enter the value of x : ";
	cin>>x;

	cout<<"Enter the value of y : ";
	cin>>y;

	A *arr = new A[SIZE];
	
	display(arr,SIZE);

	delete[] arr;
}