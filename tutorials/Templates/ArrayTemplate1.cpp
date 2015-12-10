#include<iostream>
#include<string>
using namespace std;

template<class T>
class Array
{
	T* x;
	int size;
public:
	Array() : x(0), size(0) { }
	Array(int sz,T val=T()) : size(sz)
	{
		x = new T[size];
		for(int i=0;i<size;++i)
			x[i] = val;
	}
	Array(const Array<T>& a) : size(a.size)
	{
		x = new T[size];
		for(int i=0;i<size;++i)
			x[i] = a[i];
	}
	Array<T>& operator=(const Array<T>& a) 
	{
		if(this==&a)
			;
		else
		{
			if(size!=a.size)
			{
				delete[] x;
				size = a.size;
				x = new T[size];
			}
			for(int i=0;i<size;++i)
				x[i] = a[i];
		}
		return *this;
	}
	~Array() 
	{
		delete[] x;
		x = 0;
		size = 0;
	}
	int getSize() const
	{
		return size;
	}
	T& operator[](int index) 
	{
		return x[index];
	}
	const T& operator[](int index) const 
	{
		return x[index];
	}
};

template<class T>
void display(const Array<T>& a)
{
	for(int i=0;i<a.getSize();++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}

void main()
{
	Array<int> a1,a2(5),a3(5,10),a4(a3);
	a1 = a4;

	display(a1);
	display(a2);
	display(a3);
	display(a4);
}