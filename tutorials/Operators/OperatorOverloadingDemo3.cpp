#include<iostream.h>

class Array
{
	int *x;
	int size;
public:
	Array() : x(0), size(0) { }
	Array(int _size) : size(_size)
	{
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = i+1;
	}
	Array(int _size,int *arr) : size(_size)
	{
		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = arr[i];
	}
	Array(Array& a) : size(a.size)
	{
		x = new int[size];
		for(int i=0;i<size;++i)	// deep copy
			x[i] = a.x[i];
	}	
	Array& operator=(Array& a)
	{
		if(this==&a)
			;
		else
		{
			if(size!=0)
				delete[] x;
			
			size = a.size;

			x = new int[size];
			for(int i=0;i<size;++i)	// deep copy
				x[i] = a.x[i];
		}
		return *this;
	}
	~Array()
	{
		delete[] x;
	}
	void display()
	{
		cout<<"The elements are : "<<endl;
		for(int i=0;i<size;++i)
			cout<<x[i]<<"\t";
		cout<<endl;
	}
	Array operator-()
	{
		Array tmp = *this;

		for(int i=0;i<size;++i)
			tmp.x[i] = -tmp.x[i];

		return tmp;
	}
};

void main()
{
	int x[] = {1,4,3,2,6};

	Array a1(5,x);
	Array a2;

	a2 = -a1;	// a1.operator-();
		// a2.operator=(a1.operator-());

	a1.display();
	a2.display();
}
