#include<iostream>
using namespace std;

class Array
{
	int *x;
	int size;
public:
	Array() : x(0), size(0) 
	{
		cout<<"Array()"<<endl;
	}
	Array(int _size) : size(_size)
	{
		cout<<"Array(int)"<<endl;
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = i+1;
	}
	Array(Array& a) : size(a.size)
	{
		cout<<"Array(Array&)"<<endl;		
		x = new int[size];
		for(int i=0;i<size;++i)	// deep copy
			x[i] = a.x[i];
	}	
	void operator=(Array& a)
	{
		cout<<"operator = "<<endl;
		if(size!=0)
			delete[] x;

		x = new int[size];
		for(int i=0;i<size;++i)	// deep copy
			x[i] = a.x[i];
	}
	~Array()
	{
		cout<<"~Array()"<<endl;		
		delete[] x;
	}
};

Array demo(Array obj)
{
	Array a2(3);
	return a2;
}

void main()
{
	Array a1(5),a2(6);

	a2 = demo(a1);
}
