#include<iostream>
#include<string>
using namespace std;

class Address
{
	string addr;
	string city;
	string pin;
public:
	Address() {}
	Address(string _addr,
			string _city,
			string _pin) 
		: addr(_addr), city(_city), pin(_pin) {}
	~Address()
	{
		cout<<"Deleting the address : "<<this<<endl<<endl;
	}
	void setAddr(string _addr)
	{
		addr = _addr;
	}
	string getAddr()
	{
		return addr;
	}
	void setCity(string _city)
	{
		city = _city;
	}
	string getCity()
	{
		return city;
	}
	void setPin(string _pin)
	{
		pin = _pin;
	}
	string getPin()
	{
		return pin;
	}
	string getAddress()
	{
		return addr + " " + city + " " + pin;
	}
};

class Employee
{
	string name;
	Address *address;
public:
	Employee() : address(0) {}
	Employee(string _name,Address *_address)
		: name(_name)
	{
		address = new Address(*_address);
	}
	Employee(const Employee &e) : name(e.name)
	{
		address = new Address(*(e.address));
	}
	Employee& operator=(const Employee& e)
	{
		if(this==&e)
			;
		else
		{
			name = e.name;
			delete address;
			address = new Address(*(e.address));
		}
		return *this;
	}
	~Employee()
	{
		cout<<"Deleting the employee : "
			<<name<<"\t"<<this<<endl;
		delete address;
		address = 0;
	}
	void setName(string _name)
	{
		name = _name;
	}
	string getName()
	{
		return name;
	}
	void setAddress(Address* _address)
	{
		address = new Address(*_address);
	}
	Address* getAddress()
	{
		return new Address(*address);
	}
};

class LinkedList
{
	class Node
	{
		friend class LinkedList;
		Employee* data;
		Node *prev;
		Node *next;
	public:
		Node(Employee *_data=0) 
			: prev(0), next(0) 
		{
			data = new Employee(*_data);
		}
		Node(const Node& n) 
			: prev(n.prev), next(n.next)
		{
			data = new Employee(*(n.data));
		}
		Node& operator=(const Node& n) 
		{
			if(this==&n)
				;
			else
			{
				prev = n.prev;
				next = n.next;
				delete data;
				data = new Employee(*(n.data));
			}
			return *this;
		}
		~Node()
		{
			cout<<"Deleting the node : "<<this<<endl;	
			delete data;
			prev = 0;
			next = 0;
			data = 0;
		}
	};
	Node *start;
	Node *last;
public:
	LinkedList() : start(0), last(0)
	{
		cout<<"Creating the Linked List..."<<endl<<endl;
	}
	LinkedList(const LinkedList& l) : start(0), last(0)
	{
		Node *tmp = l.start;
		while(tmp)
		{
			push_back(tmp->data);
			tmp = tmp->next;
		}
	}
	LinkedList& operator=(const LinkedList& l)
	{
		if(this==&l)
			;
		else
		{
			this->~LinkedList();

			Node *tmp = l.start;
			while(tmp)
			{
				push_back(tmp->data);
				tmp = tmp->next;
			}
		}
		return *this;
	}
	~LinkedList()
	{
		cout<<"\nDeleting the Linked List..."<<endl;

		Node *tmp = last ? last->prev : 0 ;

		while(tmp)
		{
			delete tmp->next;
			tmp = tmp->prev;
		}
		delete start;

		start = last = 0;
	}
	void push_back(Employee* data)
	{
		if(start==0)
			last = start = new Node(data);
		else
		{
			last->next = new Node(data);
			last->next->prev = last;
			last = last->next;
		}
	}
	void display()
	{
		cout<<"\nDisplaying the linked list..."<<endl<<endl;
		
		Node *tmp = start;
		while(tmp)
		{
			cout<<"Name : "<<tmp->data->getName()<<endl
				<<"Address : "<<tmp->data->getAddress()->getAddress()<<endl;

			tmp = tmp->next;
		}
	}
};

void client(LinkedList l)
{
	cout<<"\nInside client..."<<endl;
	l.display();
}

void main()
{
	LinkedList l1;
	char choice = 'y';

	do
	{
		string name, addr, city, pin;

		cout<<"Name : ";
		cin>>name;

		cout<<"Addr : ";
		cin>>addr;

		cout<<"City : ";
		cin>>city;

		cout<<"Pin : ";
		cin>>pin;

		Address *address = new Address(addr,city,pin);
		Employee *e = new Employee(name,address);
	
		l1.push_back(e);
		delete e;

		cout<<"Enter choice (y/n) : ";
		cin>>choice;
		cout<<endl;
	}while(choice=='Y' || choice=='y');

	l1.display();

	client(l1);

	l1.display();
}