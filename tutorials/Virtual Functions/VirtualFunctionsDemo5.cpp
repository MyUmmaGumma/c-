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

class LazySalesperson : public Employee
{
public:
	void work()
	{
		cout<<"Never Sells products"<<endl;
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

void client(Employee *e)
{
	cout<<e<<endl;
	e->work();		// Late Binding
}

Employee* getEmployee(int type)
{
	switch(type)
	{
	case 0:return new Employee;
	case 1:return new Salesperson;
	case 2:return new Trainee;
	case 3:return new Trainer;
	case 4:return new Consultant;
	case 5:return new LazySalesperson;
	}
	return 0;
}
int main()
{
	for(int i=0;i<10;++i)
		client(getEmployee(rand()%6));
}
