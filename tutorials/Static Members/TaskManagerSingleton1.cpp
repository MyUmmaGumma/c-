#include<iostream>
using namespace std;

class TaskManager
{
	static TaskManager *instance;

	TaskManager() 
	{	
		cout<<"Object created : "<<this<<endl;
	}
public:
	static TaskManager* getInstance()
	{
		if(instance==0)
			instance = new TaskManager;
		return instance;
	}	
};

TaskManager* TaskManager::instance;

void client1()
{
	TaskManager *tm = TaskManager::getInstance();
	cout<<tm<<endl;
}

void client2()
{
	TaskManager *tm = TaskManager::getInstance();
	cout<<tm<<endl;
}

void main()
{
	// All clients share the same object here

	TaskManager *tm = TaskManager::getInstance();
	cout<<tm<<endl;

	client1();

	client2();	
}