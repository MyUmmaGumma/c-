#include<iostream>
using namespace std;

class TaskManager
{
public:
	TaskManager() {	}
};

void client1()
{
	TaskManager *tm = new TaskManager;
	cout<<tm<<endl;
}

void client2()
{
	TaskManager *tm = new TaskManager;
	cout<<tm<<endl;
}

void main()
{
	// All clients have different objects
	// They do not share the same object here

	TaskManager *tm = new TaskManager;
	cout<<tm<<endl;

	client1();

	client2();
}