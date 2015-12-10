#include<iostream>
#include<string>
#include"Date.h"
using namespace std;

class Address
{
	string addr1, addr2;
	string city;
	string pin;
public:
	Address() {}
	Address(string a1,string a2,string c,string p) 
		: addr1(a1), addr2(a2), city(c), pin(p) {}
	void setAddr1(string a1) 
	{
		addr1 = a1;
	}
	void setAddr2(string a2) 
	{
		addr1 = a2;
	}
	void setCity(string c) 
	{
		city = c;
	}
	void setPin(string p) 
	{
		pin = p;
	}
	string getAddr1() 
	{
		return addr1;
	}
	string getAddr2() 
	{
		return addr2;
	}
	string getCity() 
	{
		return city;
	}
	string getPin() 
	{
		return pin;
	}
	operator string()
	{
		return	addr1 + " " + addr2 + " " + 
				city + " " + pin;
	}
};

class Person
{
	string name;
	Date dob;
	Address address;
public:
	Person() {}
	Person(string _name,const Date &_dob,const Address &_address) 
		: name(_name), dob(_dob), address(_address){}
	string getName()
	{
		return name;
	}
	Date getDob()
	{
		return dob;
	}
	Address getAddress()
	{
		return address;
	}
	void setName(string _name)
	{
		name = _name;
	}
	void setDob(const Date& _dob)
	{
		dob = _dob;
	}
	void setAddress(const Address& _address)
	{
		address = _address;
	}
};

class Employee : public Person
{
	string empId;
	double basic;
	int exp;
public:
	Employee() : basic(0), exp(0) {}
	Employee(	string name,const Date &dob,
				const Address &address,
				string id,double b,int e) 
		:	empId(id), basic(b), exp(e), 
			Person(name,dob,address){}
	string getEmpId()
	{
		return empId;
	}
	double getBasic()
	{
		return basic;
	}
	int getExp()
	{
		return exp;
	}
	void setEmpId(string id)
	{
		empId = id;
	}
	void setBasic(double _basic)
	{
		basic = _basic;
	}
	void setExp(int _exp)
	{
		exp = _exp;
	}
};

class Salesperson : public Employee
{
	double sales;
	double target;
public:
	Salesperson() : sales(0), target(0) {}
	Salesperson(string name,const Date &dob,
				const Address &address,
				string id,double b,int e,
				double s,double t) 
		:	sales(s), target(t), 
		Employee(name,dob,address,id,b,e) {}
	double getSales()
	{
		return sales;
	}
	double getTarget()
	{
		return target;
	}
	void setSales(double _sales)
	{
		sales = _sales;
	}
	void setTarget(double _target)
	{
		target = _target;
	}
};

class BranchMgr : public Employee
{
	double allowance;
public:
	BranchMgr() : allowance(0) {}
	BranchMgr(string name,const Date &dob,
				const Address &address,
				string id,double b,int e,
				double all) 
		:	allowance(all), 
			Employee(name,dob,address,id,b,e) {}
	double getAllowance()
	{
		return allowance;
	}
	void setAllowance(double _allowance)
	{
		allowance = _allowance;
	}
};

class Customer : public Person
{
	string custId;
public:
	Customer() {}
	Customer(	string name,const Date &dob,
				const Address &address,
				string _custId) 
		: Person(name,dob,address){}
	string getCustId()
	{
		return custId;
	}
	void setCustId(string _custId)
	{
		custId = _custId;
	}
};

class RegCustomer : public Customer
{
	Date dtReg;
public:
	RegCustomer() {}
	RegCustomer(	string name,const Date &dob,
				const Address &address,
				string _custId,const Date& _dtReg) 
		:	dtReg(_dtReg),
			Customer(name,dob,address,_custId){}
	Date getDtReg()
	{
		return dtReg;
	}
	void setDtReg(Date _dtReg)
	{
		dtReg = _dtReg;
	}
};

void display(Employee *e1)
{
	cout<<"Emp Id : "<<e1->getEmpId()<<endl;
	cout<<"Emp Name : "<<e1->getName()<<endl;
	cout<<"Date of Birth : "<<string(e1->getDob())<<endl;
	cout<<"Address : "<<string(e1->getAddress())<<endl;
	cout<<"Basic : "<<e1->getBasic()<<endl;
	cout<<"Experience : "<<e1->getExp()<<endl;
}

void display(Salesperson *s1)
{
	cout<<endl;
	display((Employee*)(s1));
	cout<<"Sales : "<<s1->getSales()<<endl;
	cout<<"Target : "<<s1->getTarget()<<endl;
}

void display(BranchMgr *b1)
{
	cout<<endl;
	display((Employee*)(b1));
	cout<<"Allowance : "<<b1->getAllowance()<<endl;
}

void main()
{
	Employee *e1 = new Employee("Vivek",Date(5,7,2004),
		Address("415","Kmangala","Bangalore","560034"),
		"AN100",12000,2);

	display(e1);

	Salesperson *s1 = new Salesperson("Zeba",Date(5,7,2004),
		Address("415","Kmangala","Bangalore","560034"),
		"SP100",12000,2,120000,100000);

	display(s1);

	BranchMgr *b1 = new BranchMgr("Durga Prasad",Date(5,7,2004),
		Address("415","Kmangala","Bangalore","560034"),
		"BM100",12000,2,5000);

	display(b1);

	delete e1;
	delete s1;
	delete b1;
}