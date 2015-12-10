#include<iostream>
using namespace std;

#define SIZE 5

class A
{
	int &x,&y;
public:
	A(int &_x,int &_y) : x(_x), y(_y) 
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

void display(A **x,int size)
{
	for(int i=0;i<size;++i)
		x[i]->show();
}

void main()
{
	int x,y;
	
	cout<<"Enter the value of x : ";
	cin>>x;

	cout<<"Enter the value of y : ";
	cin>>y;

	A **arr = new A*[SIZE];
		// No default constructor invoked

	for(int i=0;i<SIZE;++i)
		arr[i] = new A(x,y);

	++x;
	++y;
	
	display(arr,SIZE);

	for(i=0;i<SIZE;++i)
		delete arr[i];

	delete[] arr;
}