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
/*	void operator-()
	{
		cout<<"hello"<<endl;
		for(int i=0;i<size;++i)
			x[i] = -x[i];
	}*/
	friend void operator-(const Array& a)
	{
		for(int i=0;i<a.size;++i)
			a.x[i] = -a.x[i];
	}
};

void main()
{
	Array a1(5);
	Array a2 = a1;

	a1.display();
	a2.display();
	
	-a2;	// a2.operator-();

	-a2;	// operator-(a2);

	a2.display();	
}
