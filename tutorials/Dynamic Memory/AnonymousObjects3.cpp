#include<iostream>
using namespace std;

class Window
{
public:
	void show()
	{
		cout<<"Executing the application..."<<endl;
	}
};

class MainMenu
{
	Window *window;
public:
	MainMenu()
	{
		window = new Window;

		window->show();
	}
	~MainMenu()
	{
		delete window;
	}
};

class Application
{
	MainMenu *menu;
public:
	Application()
	{
		cout<<"Application Start Up"<<endl;
		menu = new MainMenu;
	}
	~Application()
	{
		cout<<"Application shut down"<<endl;
		delete menu;
	}
};

void main()
{
	// start the application on the stack;

//	Application();

	// start the application on the heap;

	delete new Application;
}