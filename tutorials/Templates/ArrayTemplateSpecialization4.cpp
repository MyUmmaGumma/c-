#include<iostream>
#include<vector>
#include"Allocator.h"
#include"MyAllocator.h"
#include<string>
#include<typeinfo>
using namespace std;


class Employee
{
	string empId;
	string name;
public:
	Employee() {}
	Employee(string id,string nm)
		: empId(id), name(nm) {}
	string getName() const
	{
		return name;
	}
	string getEmpId() const
	{
		return empId;
	}
};

ostream& operator<<(ostream& Cout,const Employee& e)
{
	Cout<<e.getEmpId()<<"\t"<<e.getName()<<endl;
	return Cout;
}

// class Array

template<class T,class A=Allocator<T> >
class Array
{					
	T* x;
	int size;
	A allocator;
public:
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

void main()
{
	Array<char*> a2(5,"");

	Client<char*> client;

	client.accept(a2);
	client.display(a2);
}