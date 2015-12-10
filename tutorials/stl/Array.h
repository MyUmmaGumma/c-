#include<iostream>
#include"Allocator.h"
#include<typeinfo>
using namespace std;

// class Array

template<class T,class A=Allocator<T> >
class Array
{		
	typedef T value;
	typedef T& reference;
	typedef T* pointer;
	typedef const T& const_reference;
	typedef const T* const_pointer;

	T* x;
	int size;
	A allocator;
public:
	class iterator
	{
		pointer x;
	public:
		iterator(pointer p=0) : x(p) {}
	};

	Array() : x(0), size(0) { }
	Array(int sz,T val=T()) : size(sz)
	{
		allocator.allocate(x,size);
		for(int i=0;i<size;++i)
			allocator.construct(x[i],val);		
	}
	Array(const Array<T,A>& a) : size(a.size)
	{
		allocator.allocate(x,size);
		for(int i=0;i<size;++i)
			allocator.construct(x[i],val);		
	}
	Array<T,A>& operator=(const Array<T,A>& a) 
	{
		if(this==&a)
			;
		else
		{
			if(size!=a.size)
			{
				allocator.deallocate(x,size);
				size = a.size;
				allocator.allocate(x,size);
			}
			for(int i=0;i<size;++i)
				allocator.construct(x[i],val);		
		}
		return *this;
	}
	~Array() 
	{
		allocator.deallocate(x,size);
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
	T* begin()
	{
		return x;
	}
	T* end()
	{
		return x+size;
	}
};

template<class T,class A = Allocator<T> >
class Client
{
public:
	void display(const Array<T,A>& a)
	{
		for(int i=0;i<a.getSize();++i)
			cout<<a[i]<<"\t";
		cout<<endl;
	}

	template<class T,class A>
	void accept(Array<T,A>& a)
	{
		cout<<"Enter "<<a.getSize()<<" elements "
			<<"of the type "<<typeid(T).name()<<endl;
		for(int i=0;i<a.getSize();++i)
			cin>>a[i];
	}
};
