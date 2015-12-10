#include<iostream>
using namespace std;

class TaskManager
{
public:
	TaskManager() 
	{	
		cout<<this<<endl;
	}
};

void client1()
{
	TaskManager *tm = new TaskManager;
}

void client2()
{
	TaskManager *tm = new TaskManager;
}

void main()
{
	// All clients have different objects
	// They do not share the same object here

	TaskManager *tm = new TaskManager;

	client1();

	client2();

	new TaskManager;
	new TaskManager;
	new TaskManager;
	new TaskManager;
}