#include<iostream>
#include<string>
#include<vector>
#include"Date.h"
using namespace std;

class SalCalc
{
	static SalCalc *instance;

	SalCalc() {}

public:
	static SalCalc* getInstance()
	{
		if(instance==0)
			instance = new SalCalc;
		return instance;
	}
	double getSalary(double basic,int exp)
	{
		double ra = 20;

		if(exp>10)
			ra = 50;
		else if(exp>8)
			ra = 45;
		else if(exp>5)
			ra = 35;
		else if(exp>2)
			ra = 30;

		double all = basic * ra/100;
		double sal = basic + all;

		return sal;
	}
	double getIncentives(double sales,double target)
	{
		return sales>target ? (sales-target) * 0.30 : 0;
	}
};

SalCalc* SalCalc::instance;

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
	virtual ~Person() = 0 { }
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
	virtual double getSalary()
	{
		return SalCalc::getInstance()->getSalary(basic,exp);
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
	double getSalary()
	{
		return	Employee::getSalary() + 
			SalCalc::getInstance()->getIncentives(sales,target);
	}
	double getIncentives()
	{
		return SalCalc::getInstance()->getIncentives(sales,target);
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
	double getSalary()
	{
		return Employee::getSalary() + allowance;
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
	virtual double getFees()
	{
		return 0;
	}
};

class Category
{
	char type;
	double fees;
	double discount;
public:
	Category() : type(' '), fees(0), discount(0) {}
	Category(char t,double f,double d) 
		: type(t), fees(d), discount(d) {}
	void setType(char t)
	{
		type = t;
	}
	char getType()
	{
		return type;
	}
	void setFees(double f)
	{
		fees = f;
	}
	double getFees()
	{
		return fees;
	}
	void setDiscount(double dis)
	{
		discount = dis;
	}
	double getDiscount()
	{
		return discount;
	}
};

class RegCustomer : public Customer
{
	Date dtReg;
	Category category;
public:
	RegCustomer() {}
	RegCustomer(	string name,const Date &dob,
				const Address &address,
				string _custId,const Date& _dtReg, 
				Category _category) 
		:	dtReg(_dtReg), category(_category),
			Customer(name,dob,address,_custId){}
	Date getDtReg()
	{
		return dtReg;
	}
	void setDtReg(Date _dtReg)
	{
		dtReg = _dtReg;
	}
	void setCategory(const Category& c)
	{
		category = c;
	}
	Category getCategory()
	{
		return category;
	}
	double getFees()
	{
		return category.getFees();
	}
};

class Branch
{
	string branchId;
	Address address;
	Employee *mgr;
public:
	Branch() : mgr(0) {}
	Branch(string id,const Address& addr,Employee *_mgr)
		: branchId(id), address(addr), mgr(_mgr) {}
	void setBranchId(string id)
	{
		branchId = id;
	}
	string getBranchId()
	{
		return branchId;
	}
	void setAddress(const Address& adr)
	{
		address = adr;
	}
	Address getAddress()
	{
		return address;
	}
	void setManager(Employee *mgr)
	{
		this->mgr = mgr;
	}
	Employee* getManager()
	{
		return mgr;
	}
};

class Company
{
	string name;
	Address regOff;
	Address corpOff;
	vector<Customer*> *customers;
	vector<Employee*> *employees;
	vector<Branch*> *branches;
	
	void init()
	{
		customers = new vector<Customer*>;
		employees = new vector<Employee*>;
		branches = new vector<Branch*>;
	}
public:
	Company() 
	{ 
		init();
	}
	Company(string n,Address ro,Address co) 
		: name(n), regOff(ro), corpOff(co) 
	{
		init();
	}
	void setName(string n)
	{
		name = n;
	}
	string getName()
	{
		return name;
	}
	void setRegOff(const Address& a)
	{
		regOff = a;
	}
	Address getRegOff()
	{
		return regOff;
	}
	void setCorpOff(const Address& a)
	{
		corpOff = a;
	}
	Address getCorpOff()
	{
		return corpOff;
	}
	vector<Branch*>* getBranches()
	{
		return branches;
	}
	vector<Employee*>* getEmloyees()
	{
		return employees;
	}
	vector<Customer*>* getCustomers()
	{
		return customers;
	}
	int getNumEmployees()
	{
		return employees->size();
	}
	int getNumCustomers()
	{
		return customers->size();
	}
	int getNumBranches()
	{
		return branches->size();
	}
	void add(Employee *e)
	{
		employees->push_back(e);
	}
	void add(Customer *c)
	{
		customers->push_back(c);
	}
	void add(Branch *b)
	{
		branches->push_back(b);
	}
	int getNumSalespersons()
	{
		int count=0;
		for(int i=0;i<employees->size();++i)
		{
			Salesperson *s = dynamic_cast<Salesperson*>((*employees)[i]);
			if(s!=0)
				++count;
		}
		return count;
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
	cout<<"Salary : "<<e1->getSalary()<<endl;
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