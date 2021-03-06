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

// partial specizalition for <char*>

Array<char*>::Array(int sz,char* val) : size(sz)
{
	cout<<"specialization char*"<<endl;
	x = new char*[size];
	for(int i=0;i<size;++i)
	{
		x[i] = new char[20];
		strcpy(x[i],val);
	}
}

Array<char*>::Array(const Array<char*>& a) : size(a.size)
{
	x = new char*[size];
	for(int i=0;i<size;++i)
	{
		x[i] = new char[20];
		strcpy(x[i],a[i]);
	}
}

Array<char*>& Array<char*>::operator=(const Array<char*>& a) 
{
	if(this==&a)
		;
	else
	{
		if(size!=a.size)
		{
			for(int i=0;i<size;++i)
				delete x[i];
			delete[] x;

			size = a.size;
			
			x = new char*[size];
			for(i=0;i<size;++i)
				x[i] = new char[20];
		}
		for(int i=0;i<size;++i)
			strcpy(x[i],a[i]);
	}
	return *this;
}
Array<char*>::~Array() 
{
	for(int i=0;i<size;++i)
		delete x[i];
	delete[] x;
	x = 0;
	size = 0;
}

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