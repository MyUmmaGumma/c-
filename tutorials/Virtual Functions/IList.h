#include<iostream>
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

struct IListFactory
{
	static IList* create(int type)
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