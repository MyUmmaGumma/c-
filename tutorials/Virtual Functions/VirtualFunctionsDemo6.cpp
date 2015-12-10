#include<iostream>
#include<string>
using namespace std;

class Employee
{
public:
	virtual void work()
	{
		cout<<"Does some work"<<endl;
	}
};

class Salesperson : public Employee
{
public:
	void work()
	{
		cout<<"Sells products"<<endl;
	}
};

class Trainee : public Employee
{
public:
	void work()
	{
		cout<<"Sleeps after lunch break"<<endl;
	}
};

class Trainer : public Employee
{
public:
	void work()
	{
		cout<<"Cures insomnia"<<endl;
	}
};

class Consultant : public Trainer
{
public:
	void work()
	{
		cout<<"Consults"<<endl;
	}
};

int main()
{
	cout<<sizeof (Consultant)<<endl;
}
