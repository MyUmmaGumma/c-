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
	bool operator==(const Array& a)
	{
		bool equals = true;

		if(size!=a.size)
			equals = false;

		for(int i=0;i<size && equals;++i)
			if(x[i]!=a[i])
				equals = false;

		return equals;
	}
	bool operator!=(const Array& a)
	{
		return !(*this==a);
	}
	Array operator*(int val) // const
	{
		Array tmp = *this;
		for(int i=0;i<size;++i)
			tmp[i]*=val;
		return tmp;
	}
	friend Array operator*(int val,const Array& a)
	{
		// return a*val;
		return const_cast<Array&>(a)*val;
	}
	friend ostream& operator<<(ostream& COUT,
								const Array& a)
	{
		COUT<<"The elements are:"
			<<endl;
		for(int i=0;i<a.size;++i)
			COUT<<a[i]<<"\t";
		COUT<<endl;

		return COUT;
	}
	friend istream& operator>>(istream& CIN,
								Array& a)
	{
		cout<<"Enter "<<a.size<<" elements :"
			<<endl;
		for(int i=0;i<a.size;++i)
			CIN>>a[i];
		
		return CIN;		
	}
	Array& operator++()	// prefix
	{
		for(int i=0;i<size;++i)
			++x[i];
		return *this;
	}
	Array operator++(int)	// postfix
	{
		Array tmp = *this;

		for(int i=0;i<size;++i)
			++x[i];

		return tmp;
	}
	Array& operator--()	// prefix
	{
		for(int i=0;i<size;++i)
			--x[i];
		return *this;
	}
	Array operator--(int)	// postfix
	{
		Array tmp = *this;

		for(int i=0;i<size;++i)
			--x[i];

		return tmp;
	}
	Array& operator*()
	{
		return *this;
	}
	Array* operator->()
	{
		return this;
	}
	Array& operator()(int _size,int *arr)
	{
		this->~Array();

		size = _size;

		x = new int[size];
		for(int i=0;i<size;++i)
			x[i] = arr[i];

		return *this;
	}
};

void main()
{
	Array a(10);

	cout<<a<<endl;

	int x[] = {2,3,4,5,6};

	// a = Array(5,x);	// On demand construction
	// a.Array(5,x);

	a(5,x);		// On demand construction

	cout<<a<<endl;
}