#include<iostream>
using namespace std;

class TaskManager
{
	static TaskManager* instance;
	static bool firstTime;
public:
	TaskManager()
	{
		if(firstTime)
		{
			cout<<"Object created..."<<endl;
			firstTime = false;
		}
	}
	~TaskManager()
	{
		if(instance)
		{
			cout<<"Object destroyed..."<<endl;
			instance = 0;
			firstTime = true;
		}
	}
	void* operator new(size_t size)
	{
		if(instance==0)
			instance = reinterpret_cast<TaskManager*>(malloc(size));

		// instance = (TaskManager*) malloc(size);

		return reinterpret_cast<void*>(instance);
	}	
	void operator delete(void *p)
	{
		TaskManager *tm = reinterpret_cast<TaskManager*>(p);

		if(instance)
		{
			tm->~TaskManager();
			free(p);
		}
	}	
};

TaskManager* TaskManager::instance;
bool TaskManager::firstTime = true;

void client1()
{
	TaskManager *tm = new TaskManager;
	cout<<tm<<endl;	

	delete tm;
}

void client2()
{
	TaskManager *tm = new TaskManager;
	cout<<tm<<endl;
}

// and many such clients

void main()
{
	TaskManager *tm1 = new TaskManager;
	cout<<tm1<<endl;

	client1();

	client2();

	TaskManager *tm2 = new TaskManager;
	cout<<tm2<<endl;

	delete tm1;
	delete tm2;
}