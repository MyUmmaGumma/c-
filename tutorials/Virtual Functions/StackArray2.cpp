#include<iostream>
#include<string>
using namespace std;

struct IList
{
	virtual void insert()=0;
	virtual void erase()=0;
};

class Array : public IList
{
public:
	void insert()
	{
		cout<<"Array insert"<<endl;
	}
	void erase()
	{
		cout<<"Array erase"<<endl;
	}
};

class LinkedList : public IList
{
public:
	void insert()
	{
		cout<<"LinkedList insert"<<endl;
	}
	void erase()
	{
		cout<<"LinkedList erase"<<endl;
	}
};

class Vector : public IList
{
public:
	void insert()
	{
		cout<<"Vector insert"<<endl;
	}
	void erase()
	{
		cout<<"Vector erase"<<endl;
	}
};

class Queue : public IList
{
public:
	void insert()
	{
		cout<<"Queue insert"<<endl;
	}
	void erase()
	{
		cout<<"Queue erase"<<endl;
	}
};

class IListFactory
{
	static IListFactory *instance;
	IListFactory() {}

public:
	static IListFactory* getInstance()
	{
		if(instance==0)
			instance = new IListFactory;
		return instance;
	}	
	IList* create(int type)
	{
		switch(type)
		{
		case 1:return new Array;
		case 2:return new LinkedList;
		case 3:return new Vector;
		case 4:return new Queue;
		}
		return 0;
	}
};

IListFactory* IListFactory::instance=0;

class Client
{
public:
	void use(int type)
	{
		IList *l = IListFactory::getInstance()->create(type);

		l->insert();
		l->erase();
	}	
};

void main()
{
	cout<<"Enter the type : ";
	int type;
	cin>>type;

	Client *client = new Client;
	client->use(type);
}