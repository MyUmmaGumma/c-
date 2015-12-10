#include<iostream>
#include<string>
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

template<class T>
void display(const Array<T>& a)
{
	for(int i=0;i<a.getSize();++i)
		cout<<a[i]<<"\t";
	cout<<endl;
}

template<class T>
void accept(const Array<T>& a)
{
	cout<<"Enter "<<a.getSize()<<" elements : "<<endl;
	for(int i=0;i<a.getSize();++i)
		cin<<a[i]<<"\t";
	cout<<endl;
}

void main()
{
	Array<char*> a1(5,"Tata Elxsi");

	display(a1);

	for(int i=0;i<a1.getSize();++i)
	{
		char s[20];
		cout<<"Enter a string : ";
		cin>>s;

		a1[i] = s;
	}

	display(a1);
}