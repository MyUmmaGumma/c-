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
	Array(const Array& a) : size(a.size)
	{
		x = new int[size];
		for(int i=0;i<size;++i)	// deep copy
			x[i] = a[i];
	}	
	Array& operator=(const Array& a)
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
				x[i] = a[i];
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
		Array tmp(size,x);

		for(int i=0;i<size;++i)
			tmp[i] = -tmp[i];

		return tmp;
	}
	int& operator[](int index)
	{
		return x[index];
	}
	const int& operator[](int index) const
	{
		return x[index];
	}
	Array operator+(const Array& a2)
	{
		Array tmp = *this;
		for(int i=0;i<size;++i)
			tmp[i]+=a2[i];
		return tmp;
	}
	friend Array operator-(const Array& a1,
						   const Array& a2)
	{
		Array tmp = a1;
		for(int i=0;i<tmp.size;++i)
			tmp[i]-=a2[i];
		return tmp;
	}
};

void main()
{
	int x[] = {1,4,3,2,6};

	Array a1(5,x),a2(5);
	Array a3;
	
	// a3 = a1 + a2;

	a3 = a1 - a2;	
		// a3 = operator-(a1,a2);

	a1.display();
	a2.display();
	a3.display();
}
