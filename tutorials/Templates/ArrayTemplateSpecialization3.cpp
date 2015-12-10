#include<iostream>
#include<vector>
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
	
template<class T>
class Allocator
{
	typedef T value;
	typedef T& reference;
	typedef T* pointer;
	typedef const T& const_reference;
	typedef const T* const_pointer;
public:
	void allocate(pointer &p,size_t size)
	{
		p = new T[size];
	}
	void construct(reference val,value init)
	{
		val = init;
	}
	void deallocate(pointer p,size_t size)
	{
		// ignore size

		delete[] p;
	}
};

// partial specialization for <char*>

void Allocator<char*>::allocate(char** &p,size_t size)
{
	p = new char*[size];
	for(int i=0;i<size;++i)
		p[i] = new char[20];
}

void Allocator<char*>::construct(char* &val,char* init)
{
	strcpy(val,init);
}

void Allocator<char*>::deallocate(char** p,size_t size)
{
	// use size

	for(int i=0;i<size;++i)
		delete p[i];

	delete[] p;
}

// class Array

template<class T>
class Array
{					
	T* x;
	int size;
	Allocator<T> allocator;
public:
	Array() : x(0), size(0) { }
	Array(int sz,T val=T()) : size(sz)
	{
		allocator.allocate(x,size);
		for(int i=0;i<size;++i)
			allocator.construct(x[i],val);		
	}
	Array(const Array<T>& a) : size(a.size)
	{
		allocator.allocate(x,size);
		for(int i=0;i<size;++i)
			allocator.construct(x[i],val);		
	}
	Array<T>& operator=(const Array<T>& a) 
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

template<class T>
void display(const Array<T>& a)
{
	for(int i=0;i<a.getSize();++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}

template<class T>
void accept(Array<T>& a)
{
	cout<<"Enter "<<a.getSize()<<" elements "
		<<"of the type "<<typeid(T).name()<<endl;
	for(int i=0;i<a.getSize();++i)
		cin>>a[i];
}

void main()
{
	Array<char*> a2(5,"");

	accept(a2);
	display(a2);
}